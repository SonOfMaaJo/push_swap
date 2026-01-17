*This project has been created as part of the 42 curriculum by vnaoussi.*

# Push_swap

## Description

The **Push_swap** project is a significant algorithmic challenge from the 42 curriculum. The objective is simple: sort a stack of integers using a limited set of instructions (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) and a secondary stack, while minimizing the total number of operations.

This project introduces the concept of complexity and requires implementing an efficient sorting algorithm capable of handling various datasets (random, sorted, reversed) with strict constraints on the number of moves.

## Instructions

### Compilation

Use the `Makefile` provided at the root of the repository to compile the project:

```bash
make
```

This will generate the `push_swap` executable.

### Execution

Run the program by passing a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the list of operations required to sort the stack.

**Examples:**

```bash
# Sort a small list
./push_swap 5 2 3 1 4

# Handle negative numbers
./push_swap -10 50 -2 0

# Check instruction count (if you have wc)
./push_swap 90 23 4 81 12 0 -5 100 55 7 | wc -l
```

### Error Management

The program displays "Error" followed by a newline on standard error if:
- Arguments are not integers.
- Arguments exceed the integer limits (`INT_MAX`, `INT_MIN`).
- There are duplicates.

## Algorithm Explained: The "Turk" Algorithm

For this project, I implemented an optimized version of the **"Mechanical Turk"** (or Turk Algorithm). It is a "greedy" algorithm that focuses on making the locally optimal move at each step to minimize operations.

### Overview

1.  **Push to B (The Dump):** 
    - Initially, push elements from Stack A to Stack B until only 3 elements remain in A.
    - *Optimization:* During this phase, we try to push smaller elements to the bottom of B and larger ones to the top to pre-sort B roughly in descending order.

2.  **Sort 3:**
    - The 3 remaining elements in Stack A are sorted using a hardcoded, highly optimized logic (max 2 operations).

3.  **Calculate & Push Back (The "Mechanical" Part):**
    - This is the core of the algorithm. For **every single element** currently in Stack B, we calculate the "cost" to move it to its correct position in Stack A.
    - **Target Position:** The correct position in A for a number `n` from B is defined as the position of the smallest number in A that is greater than `n`. If no such number exists (i.e., `n` is the new maximum), the target is the absolute minimum of A.
    - **Cost Calculation:** The cost is the sum of rotations needed for Stack B (to get `n` to the top) + rotations needed for Stack A (to get the target position to the top). We optimize by using simultaneous rotations (`rr` or `rrr`) whenever possible.
    - **Execution:** The element with the **absolute lowest cost** is selected. The rotations are executed, and the element is pushed to A (`pa`).

4.  **Final Rotation:**
    - Once Stack B is empty and all elements are in Stack A, the list is sorted but likely shifted (e.g., `3, 4, 5, 1, 2`).
    - A final rotation (`ra` or `rra`) brings the minimum element to the top of the stack.

### Complexity

This algorithm performs extremely well against the project benchmarks:
- **100 random numbers:** Consistently under 700 operations (often ~600).
- **500 random numbers:** Consistently under 5500 operations (often ~4500-5000).

## Resources

*   **Subject:** 42 Push_swap Subject PDF (Version 10.1).
*   **Documentation:**
    *   [Sorting Algorithms and Complexity](https://en.wikipedia.org/wiki/Sorting_algorithm)
    *   [Turk Algorithm Logic](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) (A common reference for this specific greedy approach).

### AI Usage

This project was developed with the assistance of an AI coding agent. The AI was used for:
1.  **Debugging:** Identifying segmentation faults and logic errors in the circular linked list implementation (specifically infinite loops in target finding).
2.  **Refactoring:** Helping to split large functions to comply with the 42 "Norm" (25 lines max per function).
3.  **Testing:** Generating test cases (random lists, edge cases like `INT_MAX`, duplicates) to verify robustness.
4.  **Documentation:** Drafting the structure of this README based on the project constraints.

All logic, particularly the choice of the Turk algorithm and the pointer manipulation implementation, was validated and understood by the developer.
