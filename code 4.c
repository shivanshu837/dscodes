#include<stdio.h>
//double ended queue using array
int que[5];
int frnt=-1,rear=-1;
//enqueue element
void enque()
{
    int x;
    if((rear+1)%5==frnt)
    {
        printf("queue is full\n ");
    }
    else if(frnt==-1&&rear==-1)
    {
    printf("enter the no : ");
    scanf("%d",&x);
        frnt++;
        rear++;
        que[rear]=x;
    }
    else
    {
    printf("enter the no : ");
    scanf("%d",&x);
        rear=(rear+1)%5;
        que[rear]=x;
    }
}
//dequeue element
void dequeue()
{
    if(frnt==rear)
    {
        frnt=rear=-1;
    }
    else if(frnt==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else{
        frnt=(frnt+1)%5;;
    }
}
//displaying elements of queue
//queue follows FIFO principle
void display()
{
    int temp=frnt;
    do
    {
        printf("%d ",que[temp]);
        temp=(temp+1)%5;
    }while(temp!=(rear+1)%5);
}
void main()
{
    int choice=1,n;
    while(choice)
    {
        printf("enter 1 for enqueue 2 for dequeue and 3 for display : ");
        scanf("%d",&n);
        switch(n){
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
        printf("enter 1 to continue : ");
        scanf("%d",&choice);
    }
}


