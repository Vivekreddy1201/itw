#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
    int height;
};
struct node *create(int data)
{
    struct node *t;
    t = malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    t->height=1;
    return t;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = create(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *insertnew(struct node*root,int key){
    if(root==NULL){
        root=malloc(sizeof(struct node));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(root->data>key){
        root->left=insertnew(root->left,key);
    }
    else if(root->data<key){
        root->right=insertnew(root->right,key);
    }
   return root;
}
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->right;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    printf("inorder sequence is ");
    
    insertnew(root,20);
    int h=height(root);
    printf("%d",h);
    return 0;
    
}
