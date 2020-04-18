#include<stdio.h>
#include<stdlib.h>
//node structure
struct node
{
    char a;
    struct node *left,*right;
};
//creating node
struct node* newnode(char data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->a=data;
  temp->left=0;
  temp->right=0;
  return temp;
}
struct node* create(struct node* root, char item)
{
    if(root==0)
        return newnode(item);
    else if(item<root->a)
    {
        root->left=create(root->left,item);
    }
     else if(item>root->a)
    {
        root->right=create(root->right,item);
    }
}
//in-order traversal
void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
        inorder(root->left);
        printf("%c ",root->a);
        inorder(root->right);
}
//post-order traversal
void postorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->a);
}
//pre-order traversal
void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
        printf("%c ",root->a);
        preorder(root->left);
        preorder(root->right);

}
void main()
{
    struct node *root;
    root=0;
   root=create(root,'a');
    create(root,'z');
    create(root,'s');
    create(root,'g');
    create(root,'o');
    create(root,'j');
    create(root,'l');
    printf("inorder is : ");
    inorder(root);
    printf("\n");
    printf("postorder is : ");
    postorder(root);
    printf("\n");
    printf("preorder is : ");
    preorder(root);
}

