/* prog_4.c - Commit 3 (final) */
#include <stdio.h>
#include <stdlib.h>

struct DNode { int val; struct DNode *prev, *next; };

struct DNode* makeNode(int v) {
    struct DNode *n = malloc(sizeof(*n)); n->val=v; n->next=n->prev=NULL; return n;
}

void attachAfter(struct DNode *pos, int v) {
    if (!pos) return;
    struct DNode *n = makeNode(v);
    n->next = pos->next; n->prev = pos; pos->next = n;
    if (n->next) n->next->prev = n;
}

void unlinkNode(struct DNode **head, struct DNode *del) {
    if (!del || !head) return;
    if (*head == del) *head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}

void printList(struct DNode *head) {
    for (struct DNode *p=head; p; p=p->next) printf("%d ", p->val);
    printf("\n");
}

void freeList(struct DNode *head) {
    while(head){ struct DNode *t=head; head=head->next; free(t);}
}

int main() {
    struct DNode *head = makeNode(1);
    attachAfter(head, 2);
    attachAfter(head->next, 3); // list: 1 2 3
    printf("Before delete: "); printList(head);
    unlinkNode(&head, head->next); // delete node with value 2
    printf("After delete: "); printList(head);
    freeList(head);
    return 0;
}

