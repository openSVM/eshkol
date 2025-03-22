#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/memory.h"
#include "core/string_table.h"
#include "core/diagnostics.h"
#include "frontend/lexer/lexer.h"
#include "frontend/parser/parser.h"
#include "backend/codegen.h"

// Forward declarations of functions we'll implement later
static char* read_file(const char* filename, size_t* length);

/**
 * Print usage information
 * 
 * @param program_name The name of the program
 */
static void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s [options] <input.esk> [output.c]\n", program_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -v, --verbose   Enable verbose output\n");
    fprintf(stderr, "  -d, --debug     Enable debug output (implies verbose)\n");
    fprintf(stderr, "  -h, --help      Display this help message\n");
    fprintf(stderr, "Arguments:\n");
    fprintf(stderr, "  <input.esk>     Input Eshkol source file\n");
    fprintf(stderr, "  [output.c]      Optional output C file (if not provided, compiles and runs)\n");
}

/**
 * Eshkol Compiler - Main Entry Point
 * 
 * This is the main entry point for the Eshkol compiler.
 * It handles command-line arguments and initiates the compilation process.
 */
int main(int argc, char** argv) {
    printf("Eshkol Compiler v0.1.0\n");
    
    // Parse command line arguments
    bool verbose_mode = false;
    bool debug_mode = false;
    const char* input_file = NULL;
    const char* output_file = NULL;
    
    // Skip program name
    int arg_index = 1;
    
    // Parse options
    while (arg_index < argc && argv[arg_index][0] == '-') {
        const char* arg = argv[arg_index];
        
        if (strcmp(arg, "-v") == 0 || strcmp(arg, "--verbose") == 0) {
            verbose_mode = true;
        } else if (strcmp(arg, "-d") == 0 || strcmp(arg, "--debug") == 0) {
            debug_mode = true;
            verbose_mode = true; // Debug implies verbose
        } else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Error: Unknown option '%s'\n", arg);
            print_usage(argv[0]);
            return 1;
        }
        
        arg_index++;
    }
    
    // Check if we have enough arguments
    if (arg_index >= argc) {
        fprintf(stderr, "Error: No input file specified\n");
        print_usage(argv[0]);
        return 1;
    }
    
    // Get input filename
    input_file = argv[arg_index++];
    
    // Get output filename if provided
    if (arg_index < argc) {
        output_file = argv[arg_index++];
    }
    
    // Print debug information
    if (debug_mode) {
        printf("Debug mode enabled\n");
    } else if (verbose_mode) {
        printf("Verbose mode enabled\n");
    }
    
    // Read input file
    size_t source_length = 0;
    char* source = read_file(input_file, &source_length);
    if (!source) {
        return 1;
    }
    
    // Initialize memory arena
    Arena* arena = arena_create(1024 * 1024); // 1MB initial size
    if (!arena) {
        fprintf(stderr, "Error: Failed to create memory arena\n");
        free(source);
        return 1;
    }
    
    // Initialize string table
    StringTable* strings = string_table_create(arena, 1024); // 1024 initial capacity
    if (!strings) {
        fprintf(stderr, "Error: Failed to create string table\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Initialize diagnostic context
    DiagnosticContext* diag = diagnostic_context_create(arena);
    if (!diag) {
        fprintf(stderr, "Error: Failed to create diagnostic context\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Set verbosity level
    if (debug_mode) {
        diagnostic_context_set_verbosity(diag, VERBOSITY_DEBUG);
    } else if (verbose_mode) {
        diagnostic_context_set_verbosity(diag, VERBOSITY_VERBOSE);
    }
    
    // Initialize lexer
    Lexer* lexer = lexer_create(arena, strings, diag, source);
    if (!lexer) {
        fprintf(stderr, "Error: Failed to create lexer\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Initialize parser
    Parser* parser = parser_create(arena, strings, diag, lexer);
    if (!parser) {
        fprintf(stderr, "Error: Failed to create parser\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Parse program
    AstNode* ast = parser_parse_program(parser);
    if (!ast) {
        fprintf(stderr, "Error: Failed to parse program\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Initialize code generator
    CodegenContext* codegen = codegen_context_create(arena, diag);
    if (!codegen) {
        fprintf(stderr, "Error: Failed to create code generator\n");
        arena_destroy(arena);
        free(source);
        return 1;
    }
    
    // Determine mode
    if (output_file) {
        // Compile to C file
        printf("Compiling %s to %s...\n", input_file, output_file);
        
        // Generate C code
        if (!codegen_generate(codegen, ast, output_file)) {
            fprintf(stderr, "Error: Failed to generate C code\n");
            arena_destroy(arena);
            free(source);
            return 1;
        }
        
        printf("Successfully compiled %s to %s\n", input_file, output_file);
    } else {
        // Compile and run
        printf("Compiling and running %s...\n", input_file);
        
        // Generate C code to a temporary file
        char temp_file[256];
        snprintf(temp_file, sizeof(temp_file), "%s.c", input_file);
        
        // Generate C code
        if (!codegen_generate(codegen, ast, temp_file)) {
            fprintf(stderr, "Error: Failed to generate C code\n");
            arena_destroy(arena);
            free(source);
            return 1;
        }
        
        // Compile and execute
        int result = codegen_compile_and_execute(codegen, temp_file, NULL, 0);
        if (result != 0) {
            fprintf(stderr, "Error: Failed to compile and execute program\n");
            arena_destroy(arena);
            free(source);
            return 1;
        }
    }
    
    // Clean up
    arena_destroy(arena);
    free(source);
    return 0;
}

/**
 * Read file contents into a string
 * 
 * @param filename The name of the file to read
 * @param length Pointer to store the length of the file
 * @return The file contents as a string, or NULL on error
 */
static char* read_file(const char* filename, size_t* length) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Allocate buffer
    char* buffer = malloc(size + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Out of memory\n");
        fclose(file);
        return NULL;
    }
    
    // Read file contents
    size_t read = fread(buffer, 1, size, file);
    fclose(file);
    
    if (read != size) {
        fprintf(stderr, "Error: Could not read file '%s'\n", filename);
        free(buffer);
        return NULL;
    }
    
    // Null-terminate
    buffer[size] = '\0';
    
    if (length) {
        *length = size;
    }
    
    return buffer;
}
