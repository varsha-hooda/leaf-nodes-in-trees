
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int countLeafNodes(Node* root) {

    // Condition 1: Empty node
    if (root == NULL) {
        return 0;
    }

    // Condition 2: Leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Count left subtree leaves
    int leftCount = countLeafNodes(root->left);

    // Count right subtree leaves
    int rightCount = countLeafNodes(root->right);

    return leftCount + rightCount;
}

int main() {

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Total Leaf Nodes = "
         << countLeafNodes(root);

    return 0;
}