#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {            // Define the structure of a node
    int data;            // Data stored in the node
    struct Node* next;   // Pointer to the next node
};

// Function to remove duplicates of a specific key from the linked list
void removeDuplicates(struct Node** head_ref, int key) {
    bool firstOccurrence = false;               // To track the first occurrence of the key
    struct Node* current = *head_ref;           // Start with the head of the list
    struct Node* previous = NULL;               // To keep track of the previous node

    while (current != NULL) {                       // Iterate through each node in the list
        if (current->data == key) {                 // Check if the current node's data is the key
            if (!firstOccurrence) {                 // If it's the first occurrence
                firstOccurrence = true;             // Mark first occurrence
                previous = current;                 // Move previous to current
            } else {                                // If it's not the first occurrence
                if (previous != NULL) {             // Check if previous is not null
                    previous->next = current->next; // Remove the duplicate occurrence
                } else {
                    *head_ref = current->next;      // Update head if the first node is a duplicate
                }
                struct Node* temp = current;     // Temporary node to free memory
                current = current->next;        // Move to the next node
                free(temp);                     // Free the memory of the removed node
                continue;                       // Skip the rest of the loop
            }
        } else {                // If current.data is not the key
            previous = current; // Move previous to current
        }
        current = current->next; // Move to the next node
    }
}

// Function to push a new node to the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));          // Allocate memory for the new node
    new_node->data = new_data;                      // Set the data
    new_node->next = (*head_ref);                   // Link the new node to the head
    (*head_ref) = new_node;                         // Update the head to point to the new node
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {                  // Iterate through each node
        printf("%d -> ", node->data);       // Print the data of the current node
        node = node->next;                  // Move to the next node
    }
    printf("NULL\n");                       // Indicate the end of the list
}   

int main() {
    struct Node* head = NULL; // Initialize the head of the list

    // Add nodes to the linked list
    push(&head, 5);
    push(&head, 4);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);

    printf("Original List:\n");
    printList(head);

    removeDuplicates(&head, 2); // Remove duplicates of the key '2'

    printf("List after removing duplicates of key 2:\n");
    printList(head); // Print the list after removing duplicates

    return 0;
}
