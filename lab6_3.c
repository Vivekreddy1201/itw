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
void replaceNode(Node **root, Node *u, Node *v) {
if (u->parent == NULL) {
*root = v;
} else if (u == u->parent->left) {
u->parent->left = v;
} else {
u->parent->right = v;
}
if (v != NULL) {
v->parent = u->parent;
}
}
Node* minimum(Node *x) {
while (x->left != NULL) {
x = x->left;
}
return x;
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
void fixDelete(Node **root, Node *x) {
while (x != *root && x->color == BLACK) {
if (x == x->parent->left) {
Node *w = x->parent->right;
if (w->color == RED) {
w->color = BLACK;
x->parent->color = RED;
rotateLeft(root, x->parent);
w = x->parent->right;
}
if ((w->left == NULL || w->left->color == BLACK) &&
(w->right == NULL || w->right->color == BLACK)) {
w->color = RED;
x = x->parent;
} else {
if (w->right == NULL || w->right->color == BLACK) {
if (w->left != NULL) w->left->color = BLACK;
w->color = RED;
rotateRight(root, w);
w = x->parent->right;
}
w->color = x->parent->color;
x->parent->color = BLACK;
if (w->right != NULL) w->right->color = BLACK;
rotateLeft(root, x->parent);
x = *root;
}
} else {
Node *w = x->parent->left;
if (w->color == RED) {
w->color = BLACK;
x->parent->color = RED;
rotateRight(root, x->parent);
w = x->parent->left;
}
if ((w->right == NULL || w->right->color == BLACK) &&
(w->left == NULL || w->left->color == BLACK)) {
w->color = RED;
x = x->parent;
} else {
if (w->left == NULL || w->left->color == BLACK) {
if (w->right != NULL) w->right->color = BLACK;
w->color = RED;
rotateLeft(root, w);
w = x->parent->left;
}
w->color = x->parent->color;
x->parent->color = BLACK;
if (w->left != NULL) w->left->color = BLACK;
rotateRight(root, x->parent);
x = *root;
}
}
}
x->color = BLACK;
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
void deleteNode(Node **root, Node *z) {
Node *y = z;
Node *x;
nodeColor yOriginalColor = y->color;
if (z->left == NULL) {
x = z->right;
replaceNode(root, z, z->right);
} else if (z->right == NULL) {
x = z->left;
replaceNode(root, z, z->left);
} else {
y = minimum(z->right);
yOriginalColor = y->color;
x = y->right;
if (y->parent == z) {
if (x != NULL) x->parent = y;
} else {
replaceNode(root, y, y->right);
y->right = z->right;
if (y->right != NULL) y->right->parent = y;
}
replaceNode(root, z, y);
y->left = z->left;
if (y->left != NULL) y->left->parent = y;
y->color = z->color;
}
free(z);
if (yOriginalColor == BLACK && x != NULL) {
fixDelete(root, x);
}
}
void inorderTraversal(Node *root) {
if (root == NULL) return;
inorderTraversal(root->left);
printf("%c ", root->data);
inorderTraversal(root->right);
}
void demoDeletionCases(Node **root, char key) {
Node *node = *root;
while (node != NULL && node->data != key) {
if (key < node->data) node = node->left;
else node = node->right;
}
if (node != NULL) {
printf("\nDeleting node %c...\n", key);
deleteNode(root, node);
} else {
printf("\nNode %c not found!\n", key);
}
}
int main() {
char keys[] = {'F', 'B', 'A', 'D', 'C', 'E', 'H', 'G', 'I', 'J', 'K',
'M', 'L', 'O', 'N', 'P', 'R', 'Q', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
'Z'};
int n = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < n; i++) {
insert(&root, keys[i]);
}
printf("Inorder Traversal of the Red-Black Tree:\n");
inorderTraversal(root);
printf("\n");
char deleteKeys[] = {'F', 'S', 'Q', 'C', 'K', 'Z'};
int deleteCount = sizeof(deleteKeys) / sizeof(deleteKeys[0]);
for (int i = 0; i < deleteCount; i++) {
demoDeletionCases(&root, deleteKeys[i]);
printf("Inorder Traversal After Deleting %c:\n", deleteKeys[i]);
inorderTraversal(root);
printf("\n");
}
return 0;
}
