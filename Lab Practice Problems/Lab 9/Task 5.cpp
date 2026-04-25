/*Question #5
Scenario: A system uses a Binary Search Tree to act as a priority queue for background tasks. The
keys in the tree represent the priority levels of the tasks. When a task is completed, it must be
removed from the system.
 Task: Implement a BST Deletion function. Specifically, handle the complex case where a
task node with two children needs to be deleted by replacing it with its Inorder Successor
(the smallest element in its right subtree) to maintain the tree&#39;s integrity.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int priority;
    string taskName;
    Node* left;
    Node* right;
};

Node* createNode(int priority, string name) {
    Node* newNode = new Node;
    newNode->priority = priority;
    newNode->taskName = name;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int priority, string name) {
    if (root == NULL) return createNode(priority, name);
    if (priority < root->priority)
        root->left = insert(root->left, priority, name);
    else
        root->right = insert(root->right, priority, name);
    return root;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteTask(Node* root, int priority) {
    if (root == NULL) return root;

    if (priority < root->priority)
        root->left = deleteTask(root->left, priority);
    else if (priority > root->priority)
        root->right = deleteTask(root->right, priority);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->priority = temp->priority;
        root->taskName = temp->taskName;
        root->right = deleteTask(root->right, temp->priority);
    }
    return root;
}

void displayTasks(Node* root) {
    if (root != NULL) {
        displayTasks(root->left);
        cout << root->priority << " " << root->taskName << endl;
        displayTasks(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50, "SystemUpdate");
    root = insert(root, 30, "VirusScan");
    root = insert(root, 70, "DataBackup");
    
    displayTasks(root);
    root = deleteTask(root, 30);
    cout << "After deletion:" << endl;
    displayTasks(root);

    return 0;
}
