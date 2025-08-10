# Q6 — Build Min & Max Heaps

## Approach
- `heapify` (sift-down) used for both max and min heaps (flag `isMax`).
- `forgeHeap` builds heap in O(n) by calling `heapify` from n/2-1 downto 0.

## main()
- Demonstrates building both heaps from sample array.

## Sample Output
Max Heap: 10 5 3 4 1 
Min Heap: 1 4 3 5 10
