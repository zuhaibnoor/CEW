#ifndef LINKED_H_INCLUDED
#define LINKED_H_INCLUDED

struct Node* createNode(int data);
struct Node* insertBegining(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);
struct Node* searchNode(struct Node* head, int data);
void freeList(struct Node* head);
void printList(struct Node* head);

#endif // LINKED_H_INCLUDED
