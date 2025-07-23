# Push_swap
[![Build Status](https://github.com/mtelek/push_swap/actions/workflows/build.yml/badge.svg?cache_buster=1)](https://github.com/mtelek/push_swap/actions)
[![Code Size](https://img.shields.io/github/languages/code-size/mtelek/push_swap?style=flat-square)](https://github.com/mtelek/push_swap)
![Project Score](https://img.shields.io/badge/Push_swap-95%25-brightgreen)

## 📖 Project Description
The Push Swap project is an algorithmic challenge where the goal is to sort a stack of integers using a limited set of instructions and two stacks (named a and b). The project requires writing a C program called push_swap that calculates and displays the shortest sequence of operations to sort the stack in ascending order. The challenge lies in optimizing the number of operations to meet strict performance benchmarks.

## Key Features
- Supports operations like sa, sb, pa, pb, ra, rb, rra, and rrb.
- Validates input for errors (e.g., non-integer values, duplicates).
- Aims to sort 100 numbers in under 700 operations and 500 numbers in under 5500 operations for full validation.

## Operations

| Operation | Description |
|-----------|-------------|
| sa        | Swap the first two elements of stack a |
| sb        | Swap the first two elements of stack b |
| ss        | Perform sa and sb simultaneously |
| pa        | Push the first element of stack b to stack a |
| pb        | Push the first element of stack a to stack b |
| ra        | Rotate stack a (shift all elements up by 1, first becomes last) |
| rb        | Rotate stack b (shift all elements up by 1, first becomes last) |
| rr        | Perform ra and rb simultaneously |
| rra       | Reverse rotate stack a (shift all elements down by 1, last becomes first) |
| rrb       | Reverse rotate stack b (shift all elements down by 1, last becomes first) |
| rrr       | Perform rra and rrb simultaneously |

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

## 🧮 Output Checker

The project includes a checker program to verify that the push_swap operations correctly sort the stack. The checker reads operations from stdin and validates the result.

### Basic Usage
```bash
ARG="3 1 4 2 5"; ./push_swap $ARG | ./checker_OS $ARG
```

### Expected Outputs:
OK - If the operations correctly sort the stack  
KO - If the operations don't sort the stack  
Error - If there are invalid operations or input errors (printed to stderr)

## 🌈 Visualizer
The sorting can be visualized using the [Visualizer](https://github.com/o-reo/push_swap_visualizer) created by [o-reo](https://github.com/o-reo)

## 🧪 Automated Testing
For comprehensive testing, two tests are currently available  
[the Push_swap_tester](https://github.com/LeoFu9487/push_swap_tester) created by [LeoFu9487](https://github.com/LeoFu9487)  
[Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester) created by [gemartin99](https://github.com/gemartin99)  
