#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a specified position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node at the beginning of the linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    for (int i = 0; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to delete a node at the end of the linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Function to search for a node with a specific value in the linked list
struct Node* search(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // Node with the specified value found
        }
        current = current->next;
    }
    return NULL; // Node with the specified value not found
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Linked list after insertion at the beginning: ");
    display(head);

    // Insert at a specified position
    insertAtPosition(&head, 40, 1);

    printf("Linked list after insertion at position 1: ");
    display(head);

    // Insert at the end
    insertAtEnd(&head, 50);

    printf("Linked list after insertion at the end: ");
    display(head);

    // Delete at the beginning
    deleteAtBeginning(&head);

    printf("Linked list after deletion at the beginning: ");
    display(head);

    // Delete at a specified position
    deleteAtPosition(&head, 1);

    printf("Linked list after deletion at position 1: ");
    display(head);

    // Delete at the end
    deleteAtEnd(&head);

    printf("Linked list after deletion at the end: ");
    display(head);

    // Search for a node with a specific value
    int searchValue = 10;
    struct Node* searchResult = search(head, searchValue);

    if (searchResult != NULL) {
        printf("Node with value %d found\n", searchValue);
    } else {
        printf("Node with value %d not found\n", searchValue);
    }

    return 0;
}
