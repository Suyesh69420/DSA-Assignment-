# Q4 — Doubly Linked List

## Data structure
- `DNode { int val; DNode *prev, *next; }` — doubly linked node.

## Functions
- `makeNode` — allocate and init node.
- `attachAfter(pos, v)` — insert new node with `v` after `pos`.
- `unlinkNode(&head, del)` — remove `del` node, update head if needed.
- `printList` / `freeList`.

## main()
- Builds list 1->2->3, deletes middle node, prints before/after.

## Sample Output:
Before delete: 1 2 3 
After delete: 1 3
