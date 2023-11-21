/*Write a C program that removes elements with odd indices from a singly linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* removeOddIndices(struct Node* head) {
    if (head == NULL || head->next == NULL) {
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

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

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

    for (int i = 1; i <= 6; i++) {
        linkedList = insertAtEnd(linkedList, i);
    }

    printf("Original Linked List:\n");
    printList(linkedList);

    linkedList = removeOddIndices(linkedList);

    printf("Linked List after removing elements with odd indices:\n");
    printList(linkedList);

    freeList(linkedList);

    return 0;
}
