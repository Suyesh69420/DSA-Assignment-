# Q1 — Balanced Parentheses Checker

## Data Structure
- `CharBox` implements a stack using an array and `top` index.

## Functions
- `initBox` — initialize stack.
- `isFull`, `isEmpty` — stack checks.
- `pushBox`, `popBox` — push/pop characters.
- `pairCheck` — verify opening/closing match.
- `isBalanced` — scan expression and use stack logic.

## main()
- Runs three test expressions and prints whether each is balanced.

## Sample Output 
Expression: a + (b - c) * (d
 Not Balanced
-----------------
Expression: m + [a - b * (c + d * {m})]
 Balanced
-----------------
Expression: a + (b - c)
 Balanced
-----------------

