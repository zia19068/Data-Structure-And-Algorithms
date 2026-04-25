/*Question #2
Scenario: A modern file system organizes directories such that every level of the storage hierarchy
is fully filled, except possibly the last level, which is filled from left to right to maintain a Complete
Binary Tree structure.
 Task: Implement a Complete Binary Tree to represent this file system. Use a Post-order
Traversal (traversing left child, then right child, then the parent) to calculate the total storage
space used by a directory and its sub-directories.
 Average Complexity: O(n) for visiting all nodes in the tree.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string dirName;
    int size;
    Node* left;
    Node* right;
};

Node* createNode(string name, int size) {
    Node* newNode = new Node;
    newNode->dirName = name;
    newNode->size = size;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int calculateStorage(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSpace = calculateStorage(root->left);
    int rightSpace = calculateStorage(root->right);

    int total = root->size + leftSpace + rightSpace;

    cout << "Directory: " << root->dirName << "  Total: " << total << " MB" << endl;
    
    return total;
}

int main() {
    Node* root = createNode("Root_Karachi", 50);

    root->left = createNode("Ahmed_Docs", 120);
    root->right = createNode("Zubair_Data", 200);

    root->left->left = createNode("Photos", 300);
    root->left->right = createNode("Work", 150);
    cout << "File System Storage Analysis" << endl;
    int grandTotal = calculateStorage(root);
    cout << "Final Storage Used: " << grandTotal << " MB" << endl;

    return 0;
}
