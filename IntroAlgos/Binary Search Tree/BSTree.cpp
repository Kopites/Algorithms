#include <iostream>
#include <cstdio>

using namespace std;

struct BSTNode {
    int key;
    BSTNode* p;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int K) {
        key = K;
        p = NULL;
        left = NULL;
        right = NULL;
    }
} *root;

void visit(BSTNode* x) {
    if (x != NULL) {
        visit(x->left);
        cout << x->key << " ";
        visit(x->right);
    }
}
BSTNode* search(BSTNode* bst, int K) {
    if (bst->key == K)
        return bst;
    if (bst->key > K)
        return search(bst->left, K);
    else
        return search(bst->right, K);
}
BSTNode* findMax(BSTNode* bst) {
    while(bst->right != NULL)
        bst = bst->right;
    return bst;
}
BSTNode* findMin(BSTNode* bst) {
    while(bst->left != NULL)
        bst = bst->left;
    return bst;
}
BSTNode* succ(BSTNode* x) {
    if (x->right != NULL)
        return findMin(x->right);
    BSTNode* y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}
BSTNode* pred(BSTNode* x) {
    if (x->left != NULL)
        return findMax(x->left);
    BSTNode* y = x->p;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->p;
    }
    return y;
}
void TreeInsert(BSTNode* &bst, BSTNode* z) {
    BSTNode* y = NULL;
    BSTNode* x = root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }
    z->p = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;
}

void Transplant(BSTNode* &bst, BSTNode* u, BSTNode* v) {
    if (u->p == NULL)
        root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else u->p->right = v;
    if (v != NULL)
        v->p = u->p;
}
void TreeDelete(BSTNode* &bst, BSTNode* z) {
    if (z->left == NULL)
        Transplant(bst, z, z->right);
    else if (z->right == NULL)
        Transplant(bst, z, z->left);
    else {
        BSTNode* y = findMin(z->right);
        if (y->p != z) {
            Transplant(bst, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        Transplant(bst, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}
void TEST() {
    root = NULL;
    BSTNode* z;
    z = new BSTNode(9);
    TreeInsert(root, z);
    z = new BSTNode(4);
    TreeInsert(root, z);
    z = new BSTNode(20);
    TreeInsert(root, z);
    z = new BSTNode(17);
    TreeInsert(root, z);
    z = new BSTNode(2);
    TreeInsert(root, z);
    z = new BSTNode(3);
    TreeInsert(root, z);
    z = new BSTNode(13);
    TreeInsert(root, z);
    z = new BSTNode(18);
    TreeInsert(root, z);
    z = new BSTNode(6);
    TreeInsert(root, z);
    z = new BSTNode(15);
    TreeInsert(root, z);
    z = new BSTNode(7);
    TreeInsert(root, z);
    visit(root);
    cout << endl;
    cout << "succ (15) = " << succ(search(root, 15))->key << endl;
    cout << "succ (6) = " << succ(search(root, 6))->key << endl;
    cout << "succ (4) = " << succ(search(root, 4))->key << endl;
    cout << "pred (6) = " << pred(search(root, 6))->key << endl;
    cout << "remove(6), ";
    cout << "remove(15), remove(7): ";
    TreeDelete(root, search(root, 15));
    TreeDelete(root, search(root, 6));
    TreeDelete(root, search(root, 7));
    visit(root);
    cout << endl;
}
int main() {
    freopen("", "r", stdin);
    TEST();
    return 0;
}
