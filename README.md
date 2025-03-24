# 🚀 Eshkol

*The high-performance LISP-like language that brings scientific computing and AI to the next level*

[![MIT License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Project Status](https://img.shields.io/badge/Status-Early%20Development-yellow.svg)]()
[![Scheme Compatibility](https://img.shields.io/badge/Scheme-R5RS%20%7C%20R7RS--small-green.svg)]()

## 🌟 What is Eshkol?

Eshkol is a revolutionary programming language that combines the elegant, expressive syntax of Scheme with the raw performance of C. Designed specifically for scientific computing and artificial intelligence applications, Eshkol delivers the perfect balance between developer productivity and computational efficiency.

Unlike other languages that force you to choose between expressiveness and performance, Eshkol gives you both:

- **Write code that reads like mathematical notation** with our LISP-like syntax
- **Run at near-C speeds** thanks to our direct compilation to optimized C code
- **Manage memory deterministically** with our innovative arena-based memory system
- **Accelerate numerical computations** using built-in SIMD optimizations
- **Differentiate functions automatically** for machine learning and optimization tasks
- **Leverage existing C libraries** with zero-overhead interoperability

## ✨ Core Features

### 🔥 What's Working Now

- **Powerful Scheme Foundation** - Core special forms fully implemented:
  - `define`, `if`, `lambda`, `begin`, `quote`, `set!`, `let`, `and`, `or`
  - Write expressive, functional code just like in Scheme

- **Arena-Based Memory Management** - Deterministic performance without GC pauses:
  - Predictable memory allocation and deallocation patterns
  - No garbage collection pauses or unpredictable latency spikes
  - Perfect for real-time applications and high-performance computing

### 🛠️ Currently In Development

- **Type System** - Optional static typing (coming soon):
  - Gradual typing system that combines static and dynamic typing
  - Type annotations for function parameters, return values, and variables
  - Type inference to reduce annotation burden
  - Compile-time type checking for early error detection

- **Scientific Computing Primitives** - Built-in support for numerical computation:
  - Vector and matrix operations with optimized implementations
  - Vector calculus operations (gradient, divergence, curl, laplacian)
  - Automatic SIMD vectorization for parallel data processing
  - High-performance mathematical functions

- **Automatic Differentiation** - First-class support for gradient-based methods:
  - Compute derivatives with machine precision
  - Support for both forward and reverse mode differentiation
  - Jacobian and Hessian matrix computation
  - Perfect for optimization, machine learning, and scientific computing

- **C Interoperability** - Seamless integration with existing codebases:
  - Zero-overhead FFI for calling C functions
  - Direct access to C data structures
  - Callback support for C libraries that require function pointers

- **VSCode Integration** - Modern development experience:
  - Syntax highlighting
  - Language configuration
  - Enhanced editing experience

### 🔮 Coming Soon

- **Comprehensive Scheme Compatibility** - Full implementation of R5RS and R7RS-small:
  - Phase 1 (In Progress): Core data types and fundamental operations
  - Phase 2: List processing and control flow
  - Phase 3: Higher-order functions and data structures
  - Phase 4: I/O and system interface
  - Phase 5: Advanced features

- **Advanced Concurrency** - Efficient parallel computation:
  - Task parallelism for concurrent execution
  - Data parallelism for collection operations
  - Message passing for safe communication
  - Lock-free algorithms for high-performance concurrency

- **GPU Acceleration** - Leverage the power of graphics processors:
  - GPGPU computing for massively parallel workloads
  - Automatic kernel generation from high-level code
  - Seamless integration with CPU code

- **Interactive Development Environment** - Rapid prototyping and exploration:
  - REPL for interactive code evaluation
  - Notebook interface for literate programming
  - Visualization tools for data exploration

## 📊 Performance

Eshkol is designed from the ground up for high performance:

- **Compilation to C** ensures optimal machine code generation
- **Arena-based memory management** eliminates GC pauses
- **SIMD optimization** exploits modern CPU vector instructions
- **Specialized numerical algorithms** for scientific computing workloads

Early benchmarks show performance comparable to hand-optimized C code for numerical workloads, while maintaining the expressiveness of a high-level language.

## 🚀 Getting Started

### Building from Source

```bash
mkdir -p build
cd build
cmake ..
make
```

### Running Your First Eshkol Program

Create a file named `hello.esk`:

```scheme
(define (main)
  (display "Hello, Eshkol!"))
```

Compile and run:

```bash
./eshkol hello.esk
```

### More Examples

Check out the `examples/` directory for sample programs demonstrating Eshkol's capabilities:

- `hello.esk` - Basic "Hello, World!" program
- `factorial.esk` - Recursive factorial calculation
- `function_composition.esk` - Higher-order functions and composition
- `arithmetic.esk` - Basic arithmetic operations
- `typed_functions.esk` - Using type annotations
- `vector_calculus.esk` - Vector operations and calculus
- `autodiff_example.esk` - Automatic differentiation in action

## 📚 Documentation

Comprehensive documentation is available to help you learn and master Eshkol:

- **[Vision and Purpose](docs/vision/PURPOSE_AND_VISION.md)** - The core philosophy behind Eshkol
- **[Differentiation Analysis](docs/vision/DIFFERENTIATION_ANALYSIS.md)** - How Eshkol compares to other languages
- **[AI Focus](docs/vision/AI_FOCUS.md)** - Eshkol's unique advantages for AI development
- **[Scientific Computing](docs/vision/SCIENTIFIC_COMPUTING.md)** - Eshkol's scientific computing capabilities
- **[Technical White Paper](docs/vision/TECHNICAL_WHITE_PAPER.md)** - In-depth technical details
- **[Future Roadmap](docs/vision/FUTURE_ROADMAP.md)** - The planned evolution of Eshkol
- **[Scheme Compatibility](docs/scheme_compatibility/MASTER_TRACKING.md)** - Status of Scheme feature implementation

## 🧩 File Extensions

Eshkol uses the following file extensions:

- `.esk` - Eshkol source files
- `.eskh` - Eshkol header files
- `.eskir` - Intermediate representation
- `.eskc` - Generated C code
- `.esklib` - Compiled library
- `.eskmod` - Module file
- `.eskproj` - Project configuration
- `.eskpkg` - Package definition

## 🤝 Contributing

Eshkol is an ambitious project, and we welcome contributions from the community! Whether you're interested in language design, compiler implementation, scientific computing, or AI, there's a place for you in the Eshkol ecosystem.

Check out our [Scheme Compatibility Implementation Plan](docs/scheme_compatibility/IMPLEMENTATION_PLAN.md) to see where you can help implement Scheme features.

## 📜 License

MIT

## 📝 Citation

If you use Eshkol in your research, please cite it as:

```bibtex
@software{tsotchke2025eshkol,
  author       = {tsotchke},
  title        = {Eshkol: A high-performance LISP-like language for scientific computing and AI},
  year         = {2025},
  url          = {https://github.com/tsotchke/eshkol}
}
```
