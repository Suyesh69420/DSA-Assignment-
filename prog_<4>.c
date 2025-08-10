#include <stdio.h>
#include <stdlib.h>

struct DNode { int val; struct DNode *prev, *next; };

void attachAfter(struct DNode *pos, int v) {
    if (!pos) return;
    struct DNode *n = malloc(sizeof(*n)); n->val=v;
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

int main() {
    struct DNode *head = malloc(sizeof(*head)); head->val=1; head->prev=head->next=NULL;
    attachAfter(head,2); attachAfter(head->next,3);
    printf("Before delete: "); printList(head);
    unlinkNode(&head, head->next); /* delete 2 */
    printf("After delete: "); printList(head);
    return 0;
}
