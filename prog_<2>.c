#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure for storing characters
struct CharBox {
    char items[MAX];
    int top;
};

void initBox(struct CharBox *box) {
    box->top = -1;
}

int isFull(struct CharBox *box) {
    return box->top == MAX - 1;
}

int isEmpty(struct CharBox *box) {
    return box->top == -1;
}

void pushBox(struct CharBox *box, char ch) {
    if (!isFull(box)) {
        box->items[++box->top] = ch;
    }
}

char popBox(struct CharBox *box) {
    if (!isEmpty(box)) {
        return box->items[box->top--];
    }
    return '\0';
}

int main() {
    printf("Q1 skeleton: Stack structure ready.\n");
    return 0;
}
