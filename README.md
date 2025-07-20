# Push_swap

## 📖 Project Description
The Push Swap project is an algorithmic challenge where the goal is to sort a stack of integers using a limited set of instructions and two stacks (named a and b). The project requires writing a C program called push_swap that calculates and displays the shortest sequence of operations to sort the stack in ascending order. The challenge lies in optimizing the number of operations to meet strict performance benchmarks.

## Key Features
- Supports operations like sa, sb, pa, pb, ra, rb, rra, and rrb.
- Validates input for errors (e.g., non-integer values, duplicates).
- Aims to sort 100 numbers in under 700 operations and 500 numbers in under 5500 operations for full validation.

## 🛠 Installation and Compilation

### Prerequisites
- C Compiler (`cc`/`gcc`/`clang`)
- GNU Make

### Compilation
1, Clone the repository
```bash
git clone https://github.com/your-username/push_swap.git
cd push_swap
make
```

## 🚀 Usage
Run the push_swap program with a list of integers as arguments

### Basic execution
```bash
  ./push_swap [integer_sequence]
```

### Example
```bash
./push_swap 3 1 4 2 5
```
The program outputs the optimal sequence of operations to sort the stack, followed by the final sorted stack for verification.

### Output checker
(Here comes the checker)

## Visualizer
The sorting can be visualized using the [Visualizer](https://github.com/o-reo/push_swap_visualizer) created by [o-reo](https://github.com/o-reo)

## Automated Testing
For a comprehensive testing, [the Push_swap_tester](https://github.com/LeoFu9487/push_swap_tester) created by [LeoFu9487](https://github.com/LeoFu9487)
