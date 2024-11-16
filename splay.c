#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int key)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = key;
    p->right = p->left = NULL;
    return p;
}
struct node *rightrotate(struct node *x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
struct node *splay(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
    {
        if (root->left == NULL)
        {
            return root;
        }
        if (key < root->left->data)
        {
            root = rightrotate(root);
            if (root->right == NULL)
                return root;
            root = rightrotate(root);
        }
        else if (key > root->left->data)
        {
            root->left = leftrotate(root->left);
            root = rightrotate(root);
        }
    }
    else
    {

        if (root->right == NULL)
            return root;

        if (key > root->right->data)
        {
            root = leftrotate(root);
            if (root->left == NULL)
                return root;
            root = leftrotate(root);
        }
        else if (key < root->right->data)
        {
            root->right = rightrotate(root->right);
            root = leftrotate(root);
        }
    }
    return root;
}
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return newnode(key);

    root = splay(root, key);

    if (root->data == key)
        return root;

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = key;

    if (key < root->data)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return newnode;
}
struct node* search(struct node* root, int key) {
    return splay(root, key);
}

void inorder(struct node* root) {
    if (root == NULL) 
    return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("inorder traversal ");
    inorder(root);
    printf("\n");

    root = search(root, 20);
    printf("Inorder traversal after splay : ");
    inorder(root);
    printf("\n");

    return 0;
}