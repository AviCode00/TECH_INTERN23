/*
Name       : Avijit Mondal
Department : Masters of Computer Applications(MCA)
College    : Dr. B. C. Engineering College , Durgapur
Level      : 4
Questionn  : Assume that you have a binary search tree (BST) with unique integer values stored in each node. 
			 Write a C++ or C program to find the maximum width of the tree, which is the maximum
			 number of nodes that can appear at any level in the tree. The program should have a time complexity of O(n),
			 where n is the number of nodes in the tree.
*/
#include <iostream>
#include <queue>

// Structure of a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node with given data
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find the maximum width of the binary search tree
int maxWidth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int maxWidth = 0;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int width = q.size();
        maxWidth = std::max(maxWidth, width);

        for (int i = 0; i < width; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

    return maxWidth;
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(13);
    root->right->right = newNode(18);

    std::cout << "Maximum width of the binary search tree is " << maxWidth(root) << std::endl;

    return 0;
}

