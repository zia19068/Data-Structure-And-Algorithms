/*Question #3
Scenario: You are building an auto-complete feature for a search engine. Words are added to a
dictionary as users type them.
 Task: Implement a BST Insertion function that adds new words to the dictionary while
maintaining the BST property: the left subtree must have keys less than or equal to the
parent, and the right subtree must have keys greater than or equal to the parent.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* left;
    Node* right;
};

Node* createNode(string word) {
    Node* newNode = new Node;
    newNode->word = word;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertWord(Node* root, string word) {
    if (root == NULL) {
        return createNode(word);
    }

    if (word <= root->word) {
        root->left = insertWord(root->left, word);
    } else {
        root->right = insertWord(root->right, word);
    }

    return root;
}

void displayDictionary(Node* root) {
    if (root != NULL) {
        displayDictionary(root->left);
        cout << root->word << endl;
        displayDictionary(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, i;
    string userWord;

    cout << "Auto complete dictionary        " << endl;

    cout << "How many words to add? ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter word " << i + 1 << ": ";
        cin >> userWord;
        root = insertWord(root, userWord);
    }

    cout << "\nDictionary (Sorted Order):" << endl;
    displayDictionary(root);

    return 0;
}
