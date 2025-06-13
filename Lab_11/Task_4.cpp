#include <iostream>
using namespace std;
struct Node {
    int code;
    Node* left;
    Node* right;
};

Node* createNode(int code) {
    Node* newNode = new Node();
    newNode->code = code;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int code) {
    if (root == nullptr)
        return createNode(code);
    if (code < root->code)
        root->left = insert(root->left, code);
    else if (code > root->code)
        root->right = insert(root->right, code);

    return root;
}
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    if (root->left == nullptr)
        return root->code;
    return findMin(root->left);
}

int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1; 
    }
    if (root->right == nullptr)
        return root->code;
    return findMax(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}