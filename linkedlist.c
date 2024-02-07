#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *newnode,*temp;
void create();
void display();
int main()
{
    int ch;
    printf("Linked List");
    while(1){
        printf("\n1.Create\n2.Display\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:display();
            break;
            case 3:exit(0);
            default:
                printf("INVALID CHOICE");
        }  
    }
}
void create()
{
    int ans;
    
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    head=newnode;
    printf("Any more nodes(0-no/1-yes):");
    scanf("%d",&ans);
    while (ans==1)
    {
        temp=newnode;
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        printf("Any more nodes(0-no/1-yes):");
        scanf("%d",&ans);
    }    
}
void display()
{
    if(head == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else{
        printf("Linked List: "); 
        // as linked list will end when Node is Null
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
    
