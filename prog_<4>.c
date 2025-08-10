#include <stdio.h>
#include <stdlib.h>

struct DNode { int val; struct DNode *prev, *next; };

void attachAfter(struct DNode *pos, int v);
void unlinkNode(struct DNode **head, struct DNode *del);
void printList(struct DNode *head);

int main() { printf("Q4 skeleton ready.\n"); return 0; }
