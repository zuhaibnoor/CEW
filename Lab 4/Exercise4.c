/*Write a C program that removes elements with odd indices from a singly linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
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

// Function to remove elements with odd indices from the linked list
struct Node* removeOddIndices(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // Nothing to remove if the list is empty or has only one element
        return head;
    }

    struct Node* current = head;
    struct Node* nextNode = NULL;
    struct Node* prev = NULL;
    int index = 1;

    while (current != NULL) {
        if (index % 2 == 0) {
            // Even index, keep the node
            prev = current;
            current = current->next;
        } else {
            // Odd index, remove the node
            nextNode = current->next;
            free(current);

            if (prev == NULL) {
                // If removing the first node, update the head
                head = nextNode;
            } else {
                prev->next = nextNode;
            }

            current = nextNode;
        }

        index++;
    }

    return head;
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
    struct Node* linkedList = NULL;

    // Populate the linked list
    for (int i = 1; i <= 6; i++) {
        linkedList = insertAtEnd(linkedList, i);
    }

    printf("Original Linked List:\n");
    printList(linkedList);

    // Remove elements with odd indices
    linkedList = removeOddIndices(linkedList);

    printf("Linked List after removing elements with odd indices:\n");
    printList(linkedList);

    // Free the memory used by the linked list
    freeList(linkedList);

    return 0;
}
