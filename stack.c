#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
int peek();
void display();

#define n 5
int top = -1;
int stack[n];

int main() {
    int ch;
    while (1) {
        printf("\n1. push\n2. pop\n3. peek\n4. display\n5. exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: printf("Top element: %d\n", peek()); break;
            case 4: display(); break;
            case 5: exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void push() {
    int el;
    if (top == n - 1) {
        printf("Stack is full\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &el);
        top = top + 1;
        stack[top] = el;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top = top - 1;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // or any suitable value indicating error
    }
    return stack[top];
}

void display() {
    int i;
    if (top >= 0) {
        printf("Stack is:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("Stack is empty\n");
    }
}
