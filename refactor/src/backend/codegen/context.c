/**
 * @file context.c
 * @brief Code generation context management implementation
 */

#include "backend/codegen/context.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Create a code generator context
 */
CodegenContext* codegen_context_create(Arena* arena, DiagnosticContext* diagnostics, TypeInferenceContext* type_context) {
    assert(arena != NULL);
    assert(diagnostics != NULL);
    
    // Allocate context
    CodegenContext* context = arena_alloc(arena, sizeof(CodegenContext));
    if (!context) return NULL;
    
    // Initialize context
    context->arena = arena;
    context->diagnostics = diagnostics;
    context->type_context = type_context;
    context->output = NULL;
    context->indent_level = 0;
    context->in_function = false;
    context->temp_dir = NULL;
    
    return context;
}

/**
 * @brief Initialize a code generator context
 */
bool codegen_context_init(CodegenContext* context, Arena* arena, TypeInferenceContext* type_context, const char* output_file) {
    assert(context != NULL);
    assert(arena != NULL);
    
    // Initialize context
    context->arena = arena;
    context->type_context = type_context;
    context->indent_level = 0;
    context->in_function = false;
    context->temp_dir = NULL;
    
    // Open output file
    if (output_file != NULL) {
        context->output = fopen(output_file, "w");
        if (!context->output) {
            return false;
        }
    } else {
        context->output = stdout;
    }
    
    return true;
}

/**
 * @brief Get the arena from the context
 */
Arena* codegen_context_get_arena(CodegenContext* context) {
    assert(context != NULL);
    return context->arena;
}

/**
 * @brief Get the diagnostics from the context
 */
DiagnosticContext* codegen_context_get_diagnostics(CodegenContext* context) {
    assert(context != NULL);
    return context->diagnostics;
}

/**
 * @brief Get the type inference context from the context
 */
TypeInferenceContext* codegen_context_get_type_context(CodegenContext* context) {
    assert(context != NULL);
    return context->type_context;
}

/**
 * @brief Get the output file from the context
 */
FILE* codegen_context_get_output(CodegenContext* context) {
    assert(context != NULL);
    return context->output;
}

/**
 * @brief Set the output file for the context
 */
void codegen_context_set_output(CodegenContext* context, FILE* output) {
    assert(context != NULL);
    context->output = output;
}

/**
 * @brief Get the indent level from the context
 */
int codegen_context_get_indent_level(CodegenContext* context) {
    assert(context != NULL);
    return context->indent_level;
}

/**
 * @brief Set the indent level for the context
 */
void codegen_context_set_indent_level(CodegenContext* context, int indent_level) {
    assert(context != NULL);
    context->indent_level = indent_level;
}

/**
 * @brief Increment the indent level
 */
void codegen_context_increment_indent(CodegenContext* context) {
    assert(context != NULL);
    context->indent_level++;
}

/**
 * @brief Decrement the indent level
 */
void codegen_context_decrement_indent(CodegenContext* context) {
    assert(context != NULL);
    if (context->indent_level > 0) {
        context->indent_level--;
    }
}

/**
 * @brief Check if we're currently in a function
 */
bool codegen_context_in_function(CodegenContext* context) {
    assert(context != NULL);
    return context->in_function;
}

/**
 * @brief Set whether we're in a function
 */
void codegen_context_set_in_function(CodegenContext* context, bool in_function) {
    assert(context != NULL);
    context->in_function = in_function;
}

/**
 * @brief Write indentation to the output
 */
void codegen_context_write_indent(CodegenContext* context) {
    assert(context != NULL);
    assert(context->output != NULL);
    
    for (int i = 0; i < context->indent_level; i++) {
        fprintf(context->output, "    ");
    }
}
