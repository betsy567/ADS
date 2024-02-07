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
    if (newNode == NULL) 
    {
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

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specified position\n");
        printf("3. Insert at the end\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at a specified position\n");
        printf("6. Delete at the end\n");
        printf("7. Search for a value\n");
        printf("8. Display the linked list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 6:
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                struct Node* result = search(head, data);
                if (result != NULL) {
                    printf("Node with value %d found\n", data);
                } else {
                    printf("Node with value %d not found\n", data);
                }
                break;
            case 8:
                display(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
