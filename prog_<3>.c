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

void freeList(struct Node *head){
    while(head){ struct Node *t=head; head=head->next; free(t); }
}

int main() {
    struct Node *h = NULL;
    pushNode(&h, 10); pushNode(&h, 20); pushNode(&h, 30); /* list is 30->20->10 */
    printf("List forward: ");
    for (struct Node *p=h; p; p=p->next) printf("%d ", p->val);
    printf("\nReverse traversal: ");
    walkBack(h);
    printf("\n");
    freeList(h);
    return 0;
}
