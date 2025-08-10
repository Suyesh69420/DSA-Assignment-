#include <stdio.h>
#include <stdlib.h>

struct Node { int val; struct Node *next; };

void pushNode(struct Node **head, int v) {
    struct Node *n = malloc(sizeof(*n)); n->val=v; n->next=*head; *head=n;
}

void walkBack(struct Node *head) {
    if (!head) return;
    walkBack(head->next);
    printf("%d ", head->val);
}

int main() {
    struct Node *h = NULL;
    pushNode(&h, 10); pushNode(&h, 20); pushNode(&h, 30);
    printf("Reverse traversal: ");
    walkBack(h);
    printf("\n");
    return 0;
}
