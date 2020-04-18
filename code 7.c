#include<stdio.h>
#include<stdlib.h>
//node-structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int t=0;
//creating nodes
struct node* insertnode(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=0;
    return temp;
};
//function to count nodes
void countnode(struct node *root)
{
    if(root==0)
    {
        return;
    }
    countnode(root->left);
    t++;
    countnode(root->right);
}
int main()
{
    struct node *root=0;
    root=insertnode(10);
    root->left=insertnode(20);
    root->right=insertnode(30);
    root->left->left=insertnode(40);
    root->left->right=insertnode(50);
    countnode(root);
    printf("%d",t);
}
