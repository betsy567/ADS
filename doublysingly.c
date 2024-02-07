#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void display();
struct Node{
    int data;
    struct Node* next;
}
struct Node* head=NULL;
void insert_begin(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    if(newNode==NULL)
    {
        printf("Overflow");
    }
    else{
        newNode->data=value;
        if (head==NULL)
        {
            head=newNode;
            newNode->next=head;
        }
        else{
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newNode->next=head;
            temp->next=newNode;
            newNode=head;
        }
    }
}
void display(){
    struct Node*temp=head;
    printf("The list is:");
    while (temp->next!=head){
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int ch,value;
    while (1)
    {
        printf("Circular Singly Linked List\n");
        printf("\n1.Insert\n2.Display\n3.Exit\n");
        printf("Enter yuor choice:");
        switch(ch){
            case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&value);
                insert_begin(value);
                break;
        case 2:
            display();
            break;
        }
        
    }
    
}