/*Write a C program that converts a singly linked list into an array and returns it.*/

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

int* linkedListToArray(struct Node* head, int* arraySize) {
    // Count the number of elements in the linked list
    int size = 0;
    struct Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    // Allocate memory for the array
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy elements from the linked list to the array
    current = head;
    for (int i = 0; i < size; i++) {
        array[i] = current->data;
        current = current->next;
    }

    // Set the output parameter for the array size
    *arraySize = size;

    return array;
}

void printArray(int* array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
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

    linkedList = insertAtEnd(linkedList, 1);
    linkedList = insertAtEnd(linkedList, 2);
    linkedList = insertAtEnd(linkedList, 3);
    linkedList = insertAtEnd(linkedList, 4);

    int arraySize;
    int* array = linkedListToArray(linkedList, &arraySize);

    printArray(array, arraySize);

    freeList(linkedList);
    free(array);

    return 0;
}
