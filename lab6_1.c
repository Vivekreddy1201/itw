#include <stdio.h>
#include <stdlib.h>
typedef enum { RED, BLACK } nodeColor;
typedef struct Node {
char data;
nodeColor color;
struct Node *left, *right, *parent;
} Node;
Node *root = NULL;
Node* createNode(char data) {
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->color = RED;
newNode->left = newNode->right = newNode->parent = NULL;
return newNode;
}
void rotateLeft(Node **root, Node *x) {
Node *y = x->right;
x->right = y->left;
if (y->left != NULL) y->left->parent = x;
y->parent = x->parent;
if (x->parent == NULL) *root = y;
else if (x == x->parent->left) x->parent->left = y;
else x->parent->right = y;
y->left = x;
x->parent = y;
}
void rotateRight(Node **root, Node *x) {
Node *y = x->left;
x->left = y->right;
if (y->right != NULL) y->right->parent = x;
y->parent = x->parent;
if (x->parent == NULL) *root = y;
else if (x == x->parent->right) x->parent->right = y;
else x->parent->left = y;
y->right = x;
x->parent = y;
}
void fixViolation(Node **root, Node *z) {
while (z != *root && z->parent->color == RED) {
if (z->parent == z->parent->parent->left) {
Node *y = z->parent->parent->right;
if (y != NULL && y->color == RED) {
z->parent->color = BLACK;
y->color = BLACK;
z->parent->parent->color = RED;
z = z->parent->parent;
} else {
if (z == z->parent->right) {
z = z->parent;
rotateLeft(root, z);
}
z->parent->color = BLACK;
z->parent->parent->color = RED;
rotateRight(root, z->parent->parent);
}
} else {
Node *y = z->parent->parent->left;
if (y != NULL && y->color == RED) {
z->parent->color = BLACK;
y->color = BLACK;
z->parent->parent->color = RED;
z = z->parent->parent;
} else {
if (z == z->parent->left) {
z = z->parent;
rotateRight(root, z);
}
z->parent->color = BLACK;
z->parent->parent->color = RED;
rotateLeft(root, z->parent->parent);
}
}
}
(*root)->color = BLACK;
}
void insert(Node **root, char data) {
Node *z = createNode(data);
Node *y = NULL;
Node *x = *root;
while (x != NULL) {
y = x;
if (z->data < x->data) x = x->left;
else x = x->right;
}
z->parent = y;
if (y == NULL) *root = z;
else if (z->data < y->data) y->left = z;
else y->right = z;
fixViolation(root, z);
}
void inorderTraversal(Node *root) {
if (root == NULL) return;
inorderTraversal(root->left);
printf("%c ", root->data);
inorderTraversal(root->right);
}
int main() {
char keys[] = {'F', 'S', 'Q', 'K', 'C', 'L', 'H', 'T', 'V', 'W', 'M',
'R', 'N', 'P', 'A', 'B', 'X', 'Y', 'D', 'Z', 'E'};
int n = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < n; i++) {
insert(&root, keys[i]);
}
printf("Inorder Traversal of Created RB Tree:\n");
inorderTraversal(root);
printf("\n");
return 0;
}