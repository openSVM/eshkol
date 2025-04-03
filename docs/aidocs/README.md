# Eshkol Programming Language Documentation

## Introduction

Eshkol is a modern programming language designed to combine the elegance and expressiveness of Scheme with the performance and efficiency of C. It features arena-based memory management, gradual typing, automatic differentiation, and powerful scientific computing capabilities.

The language is designed for applications where both performance and safety are critical, such as scientific computing, machine learning, embedded systems, and high-performance computing.

## Table of Contents

### Core Concepts
- [Overview](OVERVIEW.md) - High-level overview of the Eshkol language
- [Getting Started](GETTING_STARTED.md) - Installation and first steps
- [Memory Management](MEMORY_MANAGEMENT.md) - Arena-based allocation system
- [Type System](TYPE_SYSTEM.md) - Gradual typing and type inference
- [Function Composition](FUNCTION_COMPOSITION.md) - Closures and function composition
- [Scheme Compatibility](SCHEME_COMPATIBILITY.md) - R5RS and R7RS-small compatibility

### Advanced Features
- [Automatic Differentiation](AUTODIFF.md) - Forward and reverse-mode differentiation
- [Vector Operations](VECTOR_OPERATIONS.md) - SIMD-optimized vector and matrix operations
- [Compiler Architecture](COMPILER_ARCHITECTURE.md) - Compilation pipeline and optimization
- [eBPF Guide](EBPF_GUIDE.md) - Compiling Eshkol for eBPF targets

### Examples and Applications
- [BTree Map](examples/BTREE_MAP.md) - BTreeMap implementation
- [Trie](examples/TRIE.md) - Trie data structure implementation
- [Sorting Algorithms](examples/SORTING.md) - QuickSort and MergeSort implementations
- [Compression](examples/COMPRESSION.md) - Simple compression algorithm implementation
- [Neural Network](examples/NEURAL_NETWORK.md) - Neural network implementation
- [Gradient Descent](examples/GRADIENT_DESCENT.md) - Optimization using gradient descent

### Project Information
- [Knowledge Graph](KNOWLEDGE_GRAPH.md) - Relationships between Eshkol components
- [Compilation Guide](COMPILATION_GUIDE.md) - Building Eshkol from source
- [Roadmap](ROADMAP.md) - Planned features and development priorities

## How to Navigate This Documentation

1. **New Users**: Start with the [Overview](OVERVIEW.md) and [Getting Started](GETTING_STARTED.md) guides.
2. **Understanding Core Concepts**: Read about the [Memory Management](MEMORY_MANAGEMENT.md) and [Type System](TYPE_SYSTEM.md).
3. **Scientific Computing**: Explore [Automatic Differentiation](AUTODIFF.md) and [Vector Operations](VECTOR_OPERATIONS.md).
4. **Implementation Details**: Dive into [Compiler Architecture](COMPILER_ARCHITECTURE.md) and [Scheme Compatibility](SCHEME_COMPATIBILITY.md).
5. **Examples**: Check the examples directory for practical implementations.

## Contributing

Contributions to both the Eshkol language and its documentation are welcome. See the [Roadmap](ROADMAP.md) for current development priorities and how to get involved.
