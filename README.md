# Push_Swap

A sorting algorithm project that sorts numbers using two stacks (stack A and stack B) with a limited set of operations. This implementation uses the K-Sort algorithm for efficient sorting.

## Author

Ryan Makoni

## Description

Push_swap is a program that calculates and displays the smallest program, made of Push_swap language instructions, that sorts the integers received as arguments.

## Requirements

- GCC compiler
- Make

## Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/Raainshe/push_swap.git
cd push_swap
make
```

## Usage

The program can be used in two ways:

1. With arguments separated by spaces:
```bash
./push_swap 1 3 5 23
```

2. With arguments as a single string in quotes:
```bash
./push_swap "1 3 5 32"
```

The program will output the list of operations needed to sort the numbers in ascending order.

## Visualizer

To better understand how the program works, you can use the Push_swap visualizer:

1. Clone the visualizer repository:
```bash
git clone https://github.com/o-reo/push_swap_visualizer.git
```

2. Create and navigate to build directory:
```bash
cd push_swap_visualizer
mkdir build
cd build
```

3. Generate build files and compile:
```bash
cmake ..
make
```

4. Copy your push_swap executable into the visualizer's root directory:
```bash
cp /path/to/your/push_swap ../
```

5. Run the visualizer:
```bash
./bin/visualizer
```

The visualizer provides a graphical representation of how the stacks are manipulated during the sorting process.

## Algorithm

This implementation uses the K-Sort algorithm, which:
- Divides numbers into chunks based on their value ranges
- Efficiently moves numbers between stacks A and B
- Optimizes the number of operations needed for sorting

## Operations

The following operations are used to sort the stacks:
- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: execute sa and sb simultaneously
- `pa`: push the first element of stack B onto stack A
- `pb`: push the first element of stack A onto stack B
- `ra`: rotate stack A (first element becomes last)
- `rb`: rotate stack B (first element becomes last)
- `rr`: execute ra and rb simultaneously
- `rra`: reverse rotate stack A (last element becomes first)
- `rrb`: reverse rotate stack B (last element becomes first)
- `rrr`: execute rra and rrb simultaneously

## Error Handling

The program handles various error cases:
- Duplicate numbers
- Non-numeric input
- Numbers outside the integer range

## Clean Up

To remove object files and executable:
```bash
make clean
```

To remove all generated files:
```bash
make fclean
```

To recompile:
```bash
make re
```

## License

This project is released under the [MIT License](LICENSE).
