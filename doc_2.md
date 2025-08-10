# Q2 — Infix to Postfix & Evaluation

## Data structures
- Operator stack (array based).
- Postfix output buffer (string).

## Functions
- `precedence` — precedence of operators.
- `isOp` — checks operator.
- `scanExpr` — converts infix string to postfix (handles parentheses).
- `evalPost` — evaluates postfix expressions (single-digit operands in this implementation).

## main()
- Demonstrates conversion and evaluation on `3+(2*4)-5`.

## Sample Output
Infix: 3+(2*4)-5
Postfix: 324*+5-
Evaluation: 6
