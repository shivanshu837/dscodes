#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
}
struct node* insertnode(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=0;
    return temp;
};
int main()
{
    struct node *root=0;
    root=insertnode(10);
    root->left=insertnode(20);
    root->right=insertnode(30);
    root->left->left=insertnode(40);
    root->left->right=insertnode(50);
    inorder(root);
}

