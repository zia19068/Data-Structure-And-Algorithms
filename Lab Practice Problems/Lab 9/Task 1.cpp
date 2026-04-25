/*Question #1
Scenario: A software company is developing a digital phonebook that needs to store and retrieve
contact names efficiently. You are tasked with implementing a Binary Search Tree where each
node contains a contact name (string) as its key.
 Task: Write a function to search for a specific name in the BST. Ensure that the search
follows the property where names &quot;lesser&quot; than the root are searched in the left subtree and
those &quot;greater&quot; are searched in the right.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;
};

Node* createNode(string name) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, string name) {
    if (root == NULL) {
        return createNode(name);
    }
    
    if (name < root->name) {
        root->left = insert(root->left, name);
    } else if (name > root->name) {
        root->right = insert(root->right, name);
    }
    
    return root;
}

bool searchContact(Node* root, string target) {
    if (root == NULL) {
        return false;
    }

    if (root->name == target) {
        return true;
    }

    if (target < root->name) {
        return searchContact(root->left, target);
    } else {
        return searchContact(root->right, target);
    }
}

int main() {
    Node* root = NULL;
    string query;

    root = insert(root, "Kashif");
    root = insert(root, "Ahmed");
    root = insert(root, "Zubair");
    root = insert(root, "Bakhtawar");
    root = insert(root, "Saad");
    cout << "Digital Phonebook Search" << endl;

    cout << "Enter name to search: ";
    cin >> query;

    if (searchContact(root, query)) {
        cout << "Result: Contact '" << query << "' found" << endl;
    } else {
        cout << "Result: Contact '" << query << "' not found" << endl;
    }

    return 0;
}
