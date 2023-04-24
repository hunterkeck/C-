#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    void addHelper(Node* currNode, int val) {
        if (val < currNode->value) {
            if (currNode->left == nullptr) {
                currNode->left = new Node(val);
            }
            else {
                addHelper(currNode->left, val);
            }
        }
        else {
            if (currNode->right == nullptr) {
                currNode->right = new Node(val);
            }
            else {
                addHelper(currNode->right, val);
            }
        }
    }

    bool searchHelper(Node* currNode, int val) {
        if (currNode == nullptr) {
            return false;
        }
        if (currNode->value == val) {
            return true;
        }
        if (val < currNode->value) {
            return searchHelper(currNode->left, val);
        }
        else {
            return searchHelper(currNode->right, val);
        }
    }

    void inOrderHelper(Node* currNode) {
        if (currNode != nullptr) {
            inOrderHelper(currNode->left);
            cout << currNode->value << " ";
            inOrderHelper(currNode->right);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void add(int val) {
        if (root == nullptr) {
            root = new Node(val);
        }
        else {
            addHelper(root, val);
        }
    }

    bool search(int val) {
        return searchHelper(root, val);
    }

    void inOrder() {
        inOrderHelper(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(1);
    bst.add(9);
    bst.add(2);
    bst.add(8);

    bst.inOrder();

    cout << "Is 8 in the BST? " << (bst.search(8) ? "Yes" : "No") << endl;
    cout << "Is 4 in the BST? " << (bst.search(4) ? "Yes" : "No") << endl;

    return 0;
}
