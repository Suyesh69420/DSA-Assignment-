#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} CharStack;

void initBox(CharStack *s) { s->top = -1; }
bool isBoxEmpty(CharStack *s) { return s->top == -1; }
bool isBoxFull(CharStack *s) { return s->top == MAX_SIZE - 1; }
void pushBox(CharStack *s, char ch) { if (!isBoxFull(s)) s->arr[++(s->top)] = ch; }
char popBox(CharStack *s) { return (!isBoxEmpty(s)) ? s->arr[(s->top)--] : '\0'; }

bool checkPairing(const char *expr) {
    CharStack s;
    initBox(&s);
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            pushBox(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isBoxEmpty(&s)) return false;
            char top = popBox(&s);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return isBoxEmpty(&s);
}

int main() {
    const char *expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m})]",
        "a + (b - c)"
    };
    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (checkPairing(expressions[i]))
            printf(" Balanced\n");
        else
            printf(" Not Balanced\n");
        printf("-----------------\n");
    }
    return 0;
}
