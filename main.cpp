#include "avl.h"
#include <iostream>


int main() {
    AVL avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(15);
    avlTree.insert(5);

    std::cout << "In-order traversal before removal: ";
    avlTree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Pre-order traversal before removal: ";
    avlTree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Post-order traversal before removal: ";
    avlTree.postorderTraversal();
    std::cout << std::endl;

    std::cout << "Tree height before removal: " << avlTree.getHeight() << std::endl;

    avlTree.remove(20);

    std::cout << "In-order traversal after removal: ";
    avlTree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Pre-order traversal after removal: ";
    avlTree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Post-order traversal after removal: ";
    avlTree.postorderTraversal();
    std::cout << std::endl;

    std::cout << "Tree height after removal: " << avlTree.getHeight() << std::endl;


    int keyToSearch = 15;
    Node* foundNode = avlTree.search(keyToSearch);
    if (foundNode) {
        std::cout << "Node with key " << keyToSearch << " found in the tree." << std::endl;
    } else {
        std::cout << "Node with key " << keyToSearch << " not found in the tree." << std::endl;
    }

    Node* minNode = avlTree.getMin();
    Node* maxNode = avlTree.getMax();

    std::cout << "Minimum element in the tree: " << minNode->key << std::endl;
    std::cout << "Maximum element in the tree: " << maxNode->key << std::endl;

    return 0;
}