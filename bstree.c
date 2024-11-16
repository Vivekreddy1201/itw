#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create(int data)
{
    struct node *t;
    t = malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
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
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct node *search(struct node*root,int key){
    struct node*t=root;
    if(key=root->data){
        return t;
    }
    else if(key<root->data){
        return search(t=t->left,key);
    }
    else if(key>root->data){
        return search(t=t->right,key);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    printf("inorder sequence is ");
    inorder(root);
    printf("\npreorder sequence is " );
    preorder(root);
    printf("\npostorder sequence is ");
    postorder(root);
    printf("\n");
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
    return 0;
}
