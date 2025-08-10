#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} CharStack;

void initBox(CharStack *s) {
    s->top = -1;
}

bool isBoxEmpty(CharStack *s) {
    return s->top == -1;
}

bool isBoxFull(CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

void pushBox(CharStack *s, char ch) {
    if (!isBoxFull(s)) {
        s->arr[++(s->top)] = ch;
    }
}

char popBox(CharStack *s) {
    if (!isBoxEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

// Partial — just prints incoming characters
bool checkPairing(const char *expr) {
    printf("Expression received: %s\n", expr);
    return true;
}

int main() {
    char test[] = "a + (b - c)";
    checkPairing(test);
    return 0;
}
