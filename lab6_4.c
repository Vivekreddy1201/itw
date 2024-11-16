#include <stdio.h>
#include <stdlib.h>
typedef enum { RED, BLACK } Color;
typedef struct Node {
int key;
Color color;
struct Node *left, *right, *parent;
} Node;
typedef struct RedBlackTree {
Node *root;
} RedBlackTree;
Node* createNode(int key) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->key = key;
newNode->color = RED;
newNode->left = newNode->right = newNode->parent = NULL;
return newNode;
}
RedBlackTree* createRedBlackTree() {
RedBlackTree* tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
tree->root = NULL;
return tree;
}
void leftRotate(RedBlackTree* tree, Node* x) {
Node* y = x->right;
x->right = y->left;
if (y->left != NULL)
y->left->parent = x;
y->parent = x->parent;
if (x->parent == NULL)
tree->root = y;
else if (x == x->parent->left)
x->parent->left = y;
else
x->parent->right = y;
y->left = x;
x->parent = y;
}
void rightRotate(RedBlackTree* tree, Node* y) {
Node* x = y->left;
y->left = x->right;
if (x->right != NULL)
x->right->parent = y;
x->parent = y->parent;
if (y->parent == NULL)
tree->root = x;
else if (y == y->parent->right)
y->parent->right = x;
else
y->parent->left = x;
x->right = y;
y->parent = x;
}
void fixInsert(RedBlackTree* tree, Node* k) {
while (k != tree->root && k->parent != NULL && k->parent->color ==
RED) {
if (k->parent == k->parent->parent->left) {
Node* uncle = k->parent->parent->right;
if (uncle != NULL && uncle->color == RED) {
k->parent->color = BLACK;
uncle->color = BLACK;
k->parent->parent->color = RED;
k = k->parent->parent;
} else {
if (k == k->parent->right) {
k = k->parent;
leftRotate(tree, k);
}
k->parent->color = BLACK;
k->parent->parent->color = RED;
rightRotate(tree, k->parent->parent);
}
} else {
Node* uncle = k->parent->parent->left;
if (uncle != NULL && uncle->color == RED) {
k->parent->color = BLACK;
uncle->color = BLACK;
k->parent->parent->color = RED;
k = k->parent->parent;
} else {
if (k == k->parent->left) {
k = k->parent;
rightRotate(tree, k);
}
k->parent->color = BLACK;
k->parent->parent->color = RED;
leftRotate(tree, k->parent->parent);
}
}
}
tree->root->color = BLACK;
}
void insert(RedBlackTree* tree, int key) {
Node* newNode = createNode(key);
Node* parent = NULL;
Node* current = tree->root;
while (current != NULL) {
parent = current;
if (newNode->key < current->key)
current = current->left;
else
current = current->right;
}
newNode->parent = parent;
if (parent == NULL) {
tree->root = newNode;
} else if (newNode->key < parent->key) {
parent->left = newNode;
} else {
parent->right = newNode;
}
newNode->left = newNode->right = NULL;
fixInsert(tree, newNode);
}
void printTree(Node* root, int space) {
const int COUNT_SPACES_PER_LEVEL = 10;
const int EXTRA_SPACE = 5;
if (root == NULL)
return;
space += COUNT_SPACES_PER_LEVEL;
if (root->parent == NULL) {
printTree(root->right, space + EXTRA_SPACE);
} else {
printTree(root->right, space);
}
printf("\n");
for (int i = COUNT_SPACES_PER_LEVEL; i < space; i++)
printf(" ");
printf("%d(%s)", root->key, root->color == RED ? "R" : "B");
printTree(root->left, space);
}
void visualizeRBTree(RedBlackTree *tree) {
printf("Red-Black Tree Structure:\n");
printTree(tree->root, 0);
printf("\n");
}
int main() {
RedBlackTree *tree = createRedBlackTree();
int values_to_insert[] = {30, 80, 40, 10, 25, 50};
int n_values_to_insert = sizeof(values_to_insert) /
sizeof(values_to_insert[0]);
for (int i = 0; i < n_values_to_insert; i++) {
insert(tree, values_to_insert[i]);
}
visualizeRBTree(tree);
return 0;
}