#include <iostream>
#include <cstdio>
#define RED   true
#define BLACK false
using namespace std;

struct RBNode {
    int key;
    RBNode* p;
    RBNode* left;
    RBNode* right;
    bool color;
} *RBRoot;

#define NIL &sentinel
RBNode sentinel = { 0, NIL, NIL, NIL, BLACK };

RBNode* newNode(int k) {
    RBNode* node = new RBNode();
    node->key = k;
    node->p = NIL;
    node->left = NIL;
    node->right = NIL;
    node->color = BLACK;
    return node;
}
void RBVisit(RBNode* x) {
    if (x != NIL) {
        RBVisit(x->left);
        cout << x->key << " ";
        RBVisit(x->right);
    }
}
RBNode* search(RBNode* T, int k) {
    if (T->key == k) return T;
    else {
        if (T->key < k)
            return search(T->right, k);
        else
            return search(T->left, k);
    }
}
RBNode* findMax(RBNode* T) {
    while (T->right != NIL)
        T = T->right;
    return T;
}
RBNode* findMin(RBNode* T) {
    while (T->left != NIL)
        T = T->left;
    return T;
}
void leftRotate(RBNode* &T, RBNode* x) {
    RBNode* y = x->right; /// set y
    x->right = y->left;   /// turn y's left subtree into x's right tree
    if (y->left != NIL) {
        y->left->p = x;
    }
    y->p = x->p; /// link x's parent to y
    if (x->p == NIL) {
        RBRoot = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else x->p->right = y;
    y->left = x; /// put x on y's left
    x->p = y;
}
void rightRotate(RBNode* &T, RBNode* x){
    RBNode* y = x->left;
    x->left = y->right;
    if (y->right != NIL) {
        y->right->p = x;
    }
    y->p = x->p;
    if (x->p == NIL) {
        RBRoot = y;
    } else if (x == x->p->right) {
        x->p->right = y;
    } else x->p->left = y;
    y->right = x;
    x->p = y;
}
void RBInsertFixup(RBNode* &T, RBNode* z) {
    while(z->p->color == RED) {
        if (z->p == z->p->p->left) {
            RBNode* y = z->p->p->right;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                if (z == z->p->right) {
                    z = z->p;
                    leftRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(T, z->p->p);
            }
        } else {
            RBNode* y = z->p->p->left;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                if (z == z->p->left) {
                    z = z->p;
                    rightRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(T, z->p->p);
            }
        }
    }
    RBRoot->color = BLACK;
}
void RBInsert(RBNode* &T, RBNode* z) {
    RBNode* y = NIL;
    RBNode* x = RBRoot;
    while (x != NIL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x ->right;
    }
    z->p = y;
    if (y == NIL) {
        RBRoot = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else y->right = z;
    z->left = NIL;
    z->right = NIL;
    z->color = RED;
    RBInsertFixup(T, z);
}

void RBTransplant(RBNode* &T, RBNode* u, RBNode* v){
    if (u->p == NIL)
        RBRoot = v;
    else {
        if (u == u->p->left)
            u->p->left = v;
        else u->p->right = v;
    }
    v->p = u->p;
}
void RBDeleteFixup(RBNode* &T, RBNode* x) {
    while (x != RBRoot && x->color == BLACK) {
        if (x == x->p->left) {
            RBNode* w = x->p->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                leftRotate(T, x->p);
                w = x->p->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->p;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(T, w);
                    w = w->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                leftRotate(T, x->p);
                x = RBRoot;
            }
        } else {
            RBNode* w = x->p->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                rightRotate(T, x->p);
                w = x->p->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->p;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(T, w);
                    w = w->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rightRotate(T, x->p);
                x = RBRoot;
            }
        }
    }
    x->color = BLACK;
}
void RBDelete(RBNode* &T, RBNode* z) {
    RBNode* y = z;
    /// yo: y-origin-color
    RBNode* yO = y;
    RBNode* x;
    if (z->left == NIL) {
        x = z->right;
        RBTransplant(T, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        RBTransplant(T, z, z->left);
    } else {
        y = findMin(z->right);
        ///
        yO->color = y->color;
        x = y->right;
        if (x->p == z)
            x->p = y;
        else {
            RBTransplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        RBTransplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }
    if (yO->color == BLACK)
        RBDeleteFixup(T, x);
}
void RBInsertTest() {
    RBNode *z;
    z = newNode(1);
    RBInsert(RBRoot, z);
    z = newNode(2);
    RBInsert(RBRoot, z);
    z = newNode(3);
    RBInsert(RBRoot, z);
    z = newNode(9);
    RBInsert(RBRoot, z);
    z = newNode(-10);
    RBInsert(RBRoot, z);
    z = newNode(0);
    RBInsert(RBRoot, z);
}
void DeleteTest() {
    cout << endl;
    cout << "delete 1" << endl;
    RBDelete(RBRoot, search(RBRoot, 1));
    RBVisit(RBRoot);
    cout << endl << endl;
    cout << "delete 3" << endl;
    RBDelete(RBRoot, search(RBRoot, 3));
    RBVisit(RBRoot);
    cout << endl << endl;
    cout << "delete 2" << endl;
    RBDelete(RBRoot, search(RBRoot, 2));
    RBVisit(RBRoot);
    cout << endl << endl;
    cout << "delete -10" << endl;
    RBDelete(RBRoot, search(RBRoot, -10));
    RBVisit(RBRoot);
    cout << endl << endl;
    cout << "delete 0" << endl;
    RBDelete(RBRoot, search(RBRoot, 0));
    RBVisit(RBRoot);
}
int main() {
    RBRoot = NIL; /// Init RBTree
    RBInsertTest();
    cout << " ---------------------- " << endl;
    RBVisit(RBRoot);
    cout << "\n --------------------- " << endl;
    DeleteTest();
    return 0;
}
