# Q8 — Random integers + Sorting (user choice)

## Behavior
- Generate N random integers in [1,1000] (N from user).
- Ask user to choose sorting algorithm (Bubble, Selection, Insertion, Merge).
- Print before & after arrays, and count comparisons & swaps (swaps not meaningful for merge).

## Functions
- `bubbleSort`, `selectionSort`, `insertionSort`, `mergeSort` (with counters).
- `sortFlow` — dispatcher that resets counters and runs chosen sort.

## Sample run 
Enter N (max 100): 8
Before Sorting:
52 378 68 566 775 663 59 111
Choose Algorithm: 1.Bubble 2.Selection 3.Insertion 4.Merge
1
After Sorting:
52 59 68 111 378 566 663 775
Comparisons: 28
Swaps: 11
