#include <stdio.h>
#include <stdlib.h>

struct Node { int val; struct Node *next; };

void pushNode(struct Node **head, int v);
void walkBack(struct Node *head); /* reverse traversal */

int main() {
    printf("Q3 skeleton ready.\n");
    return 0;
}
