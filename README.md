![Banner sorting Algorithms](assets/sorting_algorithms.png)

# Sorting Algorithms – Holberton School  

## Authors

This project was developed collaboratively using pair programming.

- **GwenP88**  
  GitHub: https://github.com/GwenP88

- **Ali731-Amb**  
  GitHub: https://github.com/Ali731-Amb

## Introduction

This repository contains the implementation of several classic sorting algorithms as part of the Holberton School low-level programming curriculum.  
The goal of this project is to understand, implement, compare, and analyze multiple sorting techniques while applying strict C coding standards and producing traceable algorithmic output.

Sorting is a core skill in computer science: it builds algorithmic thinking, Big O analysis, pointer manipulation, and disciplined debugging.  
All mandatory tasks were completed collaboratively in a two-student team following the Holberton School pair-programming methodology.

---

## Pair Programming Workflow

This project was completed in a 2-student group using the following collaboration model:

- Alternating task assignment (even vs odd tasks) while ensuring **joint architectural decisions**.  
- Permanent communication on:
  - Code logic  
  - Big O complexity reasoning  
  - Edge cases and input validation  
  - Git commits, branches, and merges  
- Live review of each function before pushing.  
- Pair debugging sessions for segmentation faults, pointer issues, and list manipulation errors.  
- Both students fully understand **all** parts of the code, regardless of who typed them.

This mirrors real-world collaborative development: shared responsibility, consistent style, and synchronized progress.

---

## What Was Learned Through This Project

- Implementation of four+ different sorting algorithms  
- Understanding the characteristics of each algorithm:  
  - Time complexity (best / average / worst)  
  - Stability  
  - Space complexity  
  - Practical use cases  
- Evaluation of algorithms using **Big O notation**  
- How to select the optimal sorting strategy depending on input constraints  
- Manipulation of arrays and doubly linked lists  
- Implementing swaps (values vs node re-linking)  
- Writing traceable sorting functions that print intermediate states  
- Implementing the **Lomuto partition scheme** for Quick Sort  
- Strict use of Holberton C style (Betty), modular file structure, header guards  
- GitHub collaboration for a shared repository  

---

## Project Requirements

- Editors allowed: `vi`, `vim`, `emacs`
- Compilation on Ubuntu 20.04 LTS with:  
  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style mandatory  
- No global variables  
- Maximum 5 functions per file  
- Forbidden: standard library functions such as `printf`, `puts`, ...  
- Mandatory `README.md`  
- All prototypes declared in `sort.h` with include guards  
- List considered sorted if size < 2  
- One repository per group  
- Must use provided `print_array` and `print_list` utilities

---

## Data Structures

### Doubly Linked List Node
```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

--- 

## Tasks Overview

Below is the structured list of mandatory tasks, with description, expected behavior, constraints, and learning objectives.

---

### **0. Bubble Sort**  
**File:** `0-bubble_sort.c`, `0-O`

**Description**  
Sorts an array of integers in ascending order using the Bubble Sort algorithm.

**Expected Behavior**  
- Swap adjacent elements until the array is fully sorted.  
- Print the array after each swap.

**Constraints**  
- Use the provided `print_array` function.  
- If `size < 2`, no action is required.

**Learning Objectives**  
- Understand repeated comparison/swapping logic.  
- Observe instability and inefficiency of Bubble Sort.  
- Produce Big O notation for:  
  - Best case  
  - Average case  
  - Worst case  

---

### **1. Insertion Sort (Doubly Linked List)**  
**File:** `1-insertion_sort_list.c`, `1-O`

**Description**  
Sorts a doubly linked list of integers in ascending order using Insertion Sort.

**Expected Behavior**  
- Swap entire nodes, not integer values.  
- Carefully manipulate `prev` and `next` pointers.  
- Print the list after each node movement.

**Constraints**  
- Integer `n` inside each node cannot be modified.  
- Must maintain correct bidirectional linkage.

**Learning Objectives**  
- Master node manipulation within a doubly linked list.  
- Understand stable sorting behavior.  
- Perform time complexity analysis (best / average / worst).

---

### **2. Selection Sort**  
**File:** `2-selection_sort.c`, `2-O`

**Description**  
Sorts an array in ascending order using the Selection Sort algorithm.

**Expected Behavior**  
- Locate the smallest element in the remaining unsorted portion.  
- Swap it with the first unsorted element.  
- Print the array after each swap.

**Constraints**  
- Must use the provided `print_array` function.

**Learning Objectives**  
- Understand why Selection Sort is not stable.  
- Learn how to identify and extract the minimal element.  
- Evaluate Big O performance.

---

### **3. Quick Sort (Lomuto Partition)**  
**File:** `3-quick_sort.c`, `3-O`

**Description**  
Sorts an array in ascending order using Quick Sort with the Lomuto partition scheme.

**Expected Behavior**  
- Use the last element of the partition as the pivot.  
- Recursively apply Quick Sort on left and right partitions.  
- Print the array after each swap.

**Constraints**  
- Correct implementation of Lomuto partitioning required.  
- Must prevent infinite recursion on small partitions.

**Learning Objectives**  
- Master divide-and-conquer logic.  
- Understand recursion depth and pivot impact.  
- Analyze best, average, and worst-case complexities.  
- Observe Quick Sort’s instability.

---

## Conclusion

This project provided solid foundations in understanding and implementing sorting algorithms across arrays and doubly linked lists.  
Time complexity analysis, stability considerations, and algorithm selection were central learning components.  
Working in a pair reinforced communication, shared debugging, architectural decision-making, and real-world collaboration dynamics.

Sorting algorithms are essential pillars for future advanced topics such as trees, heaps, priority queues, pathfinding, and graph processing.  
Successfully completing this project strengthens both algorithmic maturity and low-level C programming skills, preparing the team for more complex and performance-oriented challenges.
