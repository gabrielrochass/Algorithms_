// how to implement dictionaries in bst

#include "iostream"

using namespace std;

// define bstNode
typedef struct bstNode {
    int key;
    int element;
    bstNode *left;
    bstNode *right;
}BstNode;

// create bstNode
BstNode *createBstNode(int key, int element) {
    BstNode* n = new BstNode;// new btsNode
    n->key = key;
    n->element = element;
    n->left = n->right = NULL;
    return n;
}

// define bst
typedef struct bst {
    BstNode *root;
    int nodeCount;
}Bst;

// create bst
Bst *createBst() {
    Bst *tree = new Bst;
    tree->root = NULL;
    tree->nodeCount = 0;
    return tree;
}

// to find

int findHelp(BstNode *rt, int key) {
    if (rt == NULL) {
        return 0;
    } else if (rt->key > key) {
        return findHelp(rt->left, key);
    } else if (rt->key == key) {
        return rt->element;
    } else {
            return findHelp(rt->right, key);
        }
    }

int find(Bst *tree, int key) {
    return findHelp(tree->root, key);
}

BstNode *insertHelp(BstNode *rt, int key, int element) {
    if (rt == NULL) {
        return createBstNode(key, element);
    } else if (rt->key > key) {
        rt->left = insertHelp(rt->left, key, element);
    } else {
        rt->right = insertHelp(rt->right, key, element);
    }
    return rt;
}

void insert(Bst *tree, int key, int element) {
    tree->root = insertHelp(tree->root, key, element);
    tree->nodeCount++;
}

BstNode *getMin(BstNode *rt) {
    if (rt->left == NULL) {
        return rt;
    }
    return getMin(rt->left);
}

BstNode *deleteMin(BstNode *rt) {
    if (rt->left == NULL) {
        return rt->right;
    }
    rt->left = deleteMin(rt->left);
    return rt;
}

BstNode *removeHelp(BstNode *rt, int k) {
    if (rt == NULL) {
        return NULL;
    }
    if (rt->key > k) {
        rt->left = removeHelp(rt->left, k);
    } else if (rt->key < k) {
        rt->right = removeHelp(rt->right, k);
    } else {
        if (rt->left == NULL) {
            return rt->right;
        } else if (rt->right == NULL) {
            return rt->left;
        } else {
            BstNode *temp = getMin(rt->right);
            rt->element =temp->element;
            rt->key = temp->key;
            rt->right = deleteMin(rt->right);
        }
        return rt;
    }
}

void preOrder(BstNode *rt) {
    if (rt != NULL) {
        cout << " " << rt->key;
        preOrder(rt->left);
        preOrder(rt->right);
    }
}

void inOrder(BstNode *rt) {
    if (rt != NULL) {
        inOrder(rt->left);
        cout << " " << rt->key;
        inOrder(rt->right);
    }
}

void posOrder(BstNode *rt) {
    if (rt != NULL) {
        posOrder(rt->left);
        posOrder(rt->right);
        cout << " " << rt->key;

    }
}

int main(){
    int operations;
    cin >> operations;

    Bst *tree = createBst();
    int num;
    for (int i = 0; i < operations; ++i) {
        cin >> num;
        insert(tree, num, num);
    }

    cout << "Pre order :";
    preOrder(tree->root);
    preOrder(tree->root);
    cout << endl;

    cout << "In order  :";
    inOrder(tree->root);
    cout << endl;

    cout << "Post order:";
    posOrder(tree->root);


    return 0;
}

