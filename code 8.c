#include<stdio.h>
#include<stdlib.h>
//node-structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int x=0,y=0;
//creating nodes
struct node* insertnode(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=0;
    return temp;
};
//function to count leaf nodes
void countleaf(struct node *root)
{
    if(root==0)
        return;
    countleaf(root->left);
    countleaf(root->right);
    if(root->left==0&&root->right==0)
    {
        x++;
    }
    else
    {
        y++;
    }
}
int main()
{
    struct node *root=0;
    root=insertnode(10);
    root->left=insertnode(20);
    root->right=insertnode(30);
    root->left->left=insertnode(40);
    root->left->right=insertnode(50);
    countleaf(root);
    printf("leaf nodes are %d non-leaf nodes are %d",x,y);
}

