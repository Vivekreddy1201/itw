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
