#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *create() {
    int x;
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter data (or -1 to stop): ");
    scanf("%d", &x);
    if (x == -1) {
        return NULL;
    }
    newnode->data = x;
    printf("Enter left number for %d: ", x);
    newnode->left = create();
    printf("Enter right number for %d: ", x);
    newnode->right = create();
    return newnode;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node *root;
    printf("Create binary tree:\n");
    root = create();
    printf("\nInorder traversal of the binary tree: ");
    inorder(root);
    printf("\n");
    return 0;
}

