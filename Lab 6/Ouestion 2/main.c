#include <stdio.h>
#include <stdlib.h>
#include "linklist.c"
int main()
{
    struct Node* head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);
    printf("Linked List: ");
    printList(head);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    int searchValue = 4;
    struct Node* foundNode = searchNode(head, searchValue);
    if (foundNode != NULL) {
        printf("Node with value %d found\n", searchValue);
    } else {
        printf("Node with value %d not found\n", searchValue);
    }
    int deleteValue = 2;
    head = deleteNode(head, deleteValue);
    printf("Linked List after deletion: ");
    printList(head);
    freeList(head);
    return 0;


}
