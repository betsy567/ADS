#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void delete();
void display();
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insert_begin(int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp;
    if(newNode==NULL)
    {
        printf("Overflow");
    }
    else
    {
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
void delete()
{
    struct Node* temp=head;
    if(head==NULL)
    {
        printf("Underflow");
    }
    if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
    }
}
void search()
{
    int flag=1,i=0,value;
    struct Node* temp=head;
    printf("Enter value to be searched:");
    scanf("%d",&value);
    if(temp==NULL)
    {
        printf("Empty list\n");
    }
    if(head->data==value)
    {
        printf("value found at %d",i+1);
        flag=0;
    }
    else{
        while (temp->next!=head)
        {
            if(temp->data==value)
            {
                printf("value found at location %d\n",i+1);
                flag=0;  
                break;      
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->next;            
        }
    }
    if(flag!=0){
        printf("item not found");
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
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&value);
                insert_begin(value);
                break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter value to be deleted:");
            scanf("%d",&value);
            delete(value);
            break;
        case 4:
           
            search();
            break;
        case 5:exit(0);
        default:
                printf("Invalid choice\n");
        } 
    }
    
}