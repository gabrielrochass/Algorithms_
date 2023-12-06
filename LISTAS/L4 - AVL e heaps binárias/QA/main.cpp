#include <iostream>
#include <vector>

using namespace std;


typedef struct bstNode {
    int key;
    int element;
    bstNode *left;
    bstNode *right;
    int height;
}BstNode;

BstNode *createBstNode(int k, int e) {
    BstNode *n = new BstNode;
    n->height = 0;
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

typedef struct bst {
    BstNode *root;
    int nodeCount;
}Bst;

Bst *createBst() {
    Bst *tree = new Bst;
    tree->root = NULL;
    tree->nodeCount = 0;
    return tree;
}


int h(BstNode *rt) {
    if (rt == NULL) {
        return -1;
    }
    return rt->height;
}

int getBalance(BstNode *rt) {
    if (rt == NULL) {
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

BstNode *rightRotate(BstNode* rt) {
    BstNode *l = rt->left;
    BstNode* lr = l->right;

    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    return l;
}

BstNode* leftRotate(BstNode *rt) {
    BstNode *r = rt->right;
    BstNode *rl = r->left;

    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    return r;
}

BstNode *insertHelp(BstNode *rt, int k, int e) {
    if (rt == NULL) {
        return createBstNode(k,e);
    }
    if (rt->key > k) {
        rt->left = insertHelp(rt->left, k, e);
    } else {
        rt->right = insertHelp(rt->right, k, e);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (balance < -1 and k >= rt->right->key) {
        return leftRotate(rt);
    }
    if (balance > 1 and k < rt->left->key) {
        return rightRotate(rt);
    }
    if (balance > 1 and k >= rt->left->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 and k < rt->right->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}


void insert(Bst *tree, int k, int e) {
    tree->root = insertHelp(tree->root, k, e);
    tree->nodeCount++;
}


int inOrder(BstNode *rt, vector<int> arr) {
    if (rt != NULL) {
        inOrder(rt->left, arr);
        arr.push_back(rt->key);
        inOrder(rt->right, arr);
    }

}

int findHelp(BstNode *rt, int k) {
    if (rt == NULL) {
        return NULL;
    }
    if (rt->key > k) {
        return findHelp(rt->left, k);
    } else if (rt->key == k){
        return rt->element;
    } else {
        return findHelp(rt->right, k);
    }
}

int find(Bst *tree, int k) {
    return findHelp(tree->root, k);
}


int main() {

    Bst *tree = createBst();

//    int cases, operation, element;
//    cin >> cases;
//
//    for (int i = 0; i < cases; ++i) {
//        cin >> operation;
//
//        if (operation == 1) {
//            cin >> element;
//            insert(tree, element, element);
//        } else {
// yumn´p]; trfvb/]çj
//   =
//        }
//    }

    vector<int> arr;

    insert(tree, 3, 3);
    insert(tree, 2, 2);
    insert(tree, 4, 4);

//    arr = inOrder(tree->root, arr);


    for (int i = 0; i < arr.size(); ++i) {
        vector<int>x = inOrder(tree->root, arr);
        cout << x.at(i) << " ";
    }

//    cout << inOrder(tree->root, arr);
    return 0;
}
