#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Function to display the BST
void display(struct Node* root, int level) {
    if (root != NULL) {
        display(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", root->data);
        display(root->left, level + 1);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 5:
                printf("Binary Search Tree:\n");
                display(root, 0);
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    
}
