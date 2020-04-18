#include<stdio.h>
#include<stdlib.h>
//double ended queue using doubly linked list
struct node
{
    int a;
    struct node *prev;
    struct node *next;
};
struct node *frontend=0,*rear=0,*temp;
//enqueue element
void enque()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=0;
    printf("enter data : ");
    scanf("%d",&newnode->a);
    if(rear==0)
    {
        frontend=newnode;
        newnode->prev=0;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
//dequeue element
void dequeue()
{
    if(frontend==0&&rear==0)
    {
        printf("queue is empty\n");
    }
    else if(frontend==rear)
    {
        frontend=rear=0;
    }
    else
    {
        temp=frontend;
        frontend=frontend->next;
        frontend->prev=0;
        free(temp);
    }
}
//display elements of queue
void display()
{
    temp=frontend;
    while(temp!=0)
    {
        printf("%d ",temp->a);
        temp=temp->next;
    }
    printf("\n");
}
void main()
{
    int n,choice=1;
    while(choice)
    {
       printf("enter 1-enqueue 2-dequeue 3-display : ");
       scanf("%d",&n);
       switch(n)
       {
       case 1:
           enque();
           break;
       case 2:
        dequeue();
        break;
       case 3:
        display();
        break;
       }
       printf("enter 1 to cont.  : ");
       scanf("%d",&choice);
    }
}

