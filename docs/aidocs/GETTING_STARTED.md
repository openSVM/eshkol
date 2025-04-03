# Getting Started with Eshkol

## Installation

### Prerequisites

Before installing Eshkol, ensure you have the following prerequisites:

- C compiler (GCC 9+ or Clang 10+)
- CMake 3.15+
- Make or Ninja build system
- Git

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/eshkol.git
   cd eshkol
   ```

2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

3. Configure with CMake:
   ```bash
   cmake ..
   ```

4. Build:
   ```bash
   make -j$(nproc)
   ```

5. Install (optional):
   ```bash
   sudo make install
   ```

## Hello, World!

Let's create a simple "Hello, World!" program in Eshkol:

1. Create a file named `hello.esk`:
   ```scheme
   (define (main)
     (display "Hello, Eshkol!")
     (newline))
   ```

2. Compile the program:
   ```bash
   eshkol compile hello.esk -o hello
   ```

3. Run the program:
   ```bash
   ./hello
   ```

You should see the output: `Hello, Eshkol!`

## Basic Syntax and Concepts

### Variables and Definitions

```scheme
;; Define a variable
(define x 42)

;; Define a function
(define (square x)
  (* x x))

;; Use the function
(display (square 5))  ; Outputs: 25
```

### Control Flow

```scheme
;; Conditional expression
(if (> x 0)
    (display "Positive")
    (display "Non-positive"))

;; Multiple expressions with begin
(begin
  (display "First line")
  (display "Second line"))

;; Looping with recursion
(define (countdown n)
  (if (= n 0)
      (display "Blast off!")
      (begin
        (display n)
        (countdown (- n 1)))))
```

### Data Types

Eshkol supports several built-in data types:

- **Numbers**: Integers and floating-point numbers
- **Booleans**: `#t` (true) and `#f` (false)
- **Strings**: Text enclosed in double quotes
- **Symbols**: Identifiers that represent themselves
- **Vectors**: Fixed-size arrays
- **Pairs and Lists**: Linked data structures

### Type Annotations (Optional)

```scheme
;; Function with type annotations
(: add-integers (-> integer integer integer))
(define (add-integers x y)
  (+ x y))

;; Inline type annotations
(define (multiply [x : float] [y : float]) : float
  (* x y))
```

## Step-by-Step Tutorial: Temperature Converter

Let's create a simple temperature converter program:

1. Create a file named `temperature.esk`:
   ```scheme
   ;; Type declarations
   (: celsius->fahrenheit (-> float float))
   (: fahrenheit->celsius (-> float float))
   
   ;; Convert Celsius to Fahrenheit
   (define (celsius->fahrenheit c)
     (+ (* c (/ 9 5)) 32))
   
   ;; Convert Fahrenheit to Celsius
   (define (fahrenheit->celsius f)
     (* (- f 32) (/ 5 9)))
   
   ;; Main function
   (define (main)
     (display "Temperature Converter")
     (newline)
     (display "Enter temperature in Celsius: ")
     (let ((celsius (read)))
       (let ((fahrenheit (celsius->fahrenheit celsius)))
         (display celsius)
         (display "°C = ")
         (display fahrenheit)
         (display "°F")
         (newline))))
   ```

2. Compile the program:
   ```bash
   eshkol compile temperature.esk -o temperature
   ```

3. Run the program:
   ```bash
   ./temperature
   ```

4. Enter a temperature when prompted, and see the conversion result.

## Next Steps

Now that you've created your first Eshkol programs, you can explore more advanced features:

- Learn about [Memory Management](MEMORY_MANAGEMENT.md)
- Explore the [Type System](TYPE_SYSTEM.md)
- Understand [Function Composition](FUNCTION_COMPOSITION.md)
- Try out [Automatic Differentiation](AUTODIFF.md) for scientific computing

For more examples, check out the [examples directory](examples/) in the documentation.
