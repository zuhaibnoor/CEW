/*Write a C program to merge two sorted singly linked lists into a single sorted linked list.*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to merge two sorted linked lists into a single sorted linked list
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            mergedList = insertAtEnd(mergedList, list1->data);
            list1 = list1->next;
        } else {
            mergedList = insertAtEnd(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // If there are remaining nodes in list1 or list2, append them to the merged list
    while (list1 != NULL) {
        mergedList = insertAtEnd(mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        mergedList = insertAtEnd(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    list1 = insertAtEnd(list1, 1);
    list1 = insertAtEnd(list1, 3);
    list1 = insertAtEnd(list1, 5);
    list2 = insertAtEnd(list2, 2);
    list2 = insertAtEnd(list2, 4);
    list2 = insertAtEnd(list2, 6);

    mergedList = mergeSortedLists(list1, list2);

    printf("Merged List:\n");
    printList(mergedList);

    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}

