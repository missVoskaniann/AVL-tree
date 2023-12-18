#ifndef AVL_H
#define AVL_H

class Node {
public:
    Node* left;
    Node* right;
    int key;
    int height;

    Node(int k);
}; 

class AVL {
public:
    AVL();
    void inorderTraversal();
    void postorderTraversal();
    void preorderTraversal();

    void insert(int k);
    void remove(int k);
    Node* search(int k);
    Node* getMin();
    Node* getMax();
    int getHeight();

  
private:
    Node* root;

    void inorderTraversal(Node* r);
    void postorderTraversal(Node* r);
    void preorderTraversal(Node* r);
    void insert(Node*& r, int k);
    void remove(Node*& r, int k);
    Node* search(Node* n, int k);
    Node* getMin(Node* x);
    Node* getMax(Node* x);
    int getHeight(Node* x);

    int balanceFactor(Node* x);
    void updateHeight(Node* x);
    Node* rotateRight(Node* x);
    Node* rotateLeft(Node* x);
    void balance(Node*& x);
};
#endif