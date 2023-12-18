#include "avl.h"
#include <iostream>
#include <algorithm>

Node::Node(int k) : left{nullptr}, right{nullptr}, key{k}, height{0} {}

AVL::AVL() : root{nullptr} {}

int AVL::getHeight(Node* x) {
    if (!x) {
        return -1;
    }
    return x->height;
}

int AVL::getHeight() {
    return getHeight(root);
}

int AVL::balanceFactor(Node* x) {
    return getHeight(x->left) - getHeight(x->right);
}

void AVL::updateHeight(Node* x) {
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
}

Node* AVL::rotateRight(Node* x) {
    Node* y = x->left;
    Node* z = x->right;
    
    y->right = x;
    x->left = z;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void AVL::balance(Node*& x) {
    if (!x) {
        return;
    }
    updateHeight(x);
    int balance = balanceFactor(x);
    if (balance > 1) {
        if (balanceFactor(x->left) < 0) {
            x->left = rotateLeft(x->left);
        }
        x = rotateRight(x);
    } else if (balance < -1) {
        if (balanceFactor(x->right) > 0) {
            x->right = rotateRight(x->right);
        }
        x = rotateLeft(x);
    }
}

void AVL::insert(Node*& r, int k) {
    if (r == nullptr) {
        r = new Node(k);
    } else if (k < r->key) {
        insert(r->left, k);
    } else {
        insert(r->right, k);
    }

    balance(r);
}

void AVL::insert(int k) {
    insert(root, k);
}

void AVL::inorderTraversal(Node* r) {
    if (r != nullptr) {
        inorderTraversal(r->left);
        std::cout << r->key << " ";
        inorderTraversal(r->right);
    }
}

void AVL::inorderTraversal() {
    inorderTraversal(root);
}

void AVL::preorderTraversal(Node* r) {
    if (r != nullptr) {
        std::cout << r->key << " ";
        preorderTraversal(r->left);
        preorderTraversal(r->right);
    }
}

void AVL::preorderTraversal() {
    preorderTraversal(root);
}

void AVL::postorderTraversal(Node* r) {
    if (r != nullptr) {
        postorderTraversal(r->left);
        postorderTraversal(r->right);
        std::cout << r->key << " ";
    }
}

void AVL::postorderTraversal() {
    postorderTraversal(root);
}

Node* AVL::search(Node* n, int k) {
    while (n != nullptr && k != n->key) {
        if (k < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    return n;
}

Node* AVL::search(int k) {
    return search(root, k);
}

Node* AVL::getMin(Node* x) {
    if (!x) {
        return nullptr;
    }
    while (x->left) {
        x = x->left;
    }
    return x;
}

Node* AVL::getMin() {
    return (root);
}

Node* AVL::getMax(Node* x) {
    if (!x) {
        return nullptr;
    }
    while (x->right) {
        x = x->right;
    }
    return x;
}

Node* AVL::getMax() {
    return getMax(root);
}

void AVL::remove(Node*& r, int k) {
    if (r == nullptr) {
        return;
    }
    if (k < r->key) {
        remove(r->left, k);
    } else if (k > r->key) {
        remove(r->right, k);
    } else {
        if (r->left == nullptr || r->right == nullptr) {
            Node* tmp = (r->left != nullptr) ? r->left : r->right;
            if (tmp == nullptr) {
                tmp = r;
                r = nullptr;
            } else {
                *r = *tmp;
            }
            delete tmp;
        } else {
            Node* successor = getMin(r->right);
            r->key = successor->key;
            remove(r->right, successor->key);
        }
    }
    balance(r);
}

void AVL::remove(int k) {
    remove(root, k);
}