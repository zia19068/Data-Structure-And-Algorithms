#include <iostream>
#include <string>
using namespace std;

struct Node {
    string text;
    Node* left;
    Node* right;
};

Node* createNode(string text) {
    Node* newNode = new Node;
    newNode->text = text;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printDiagnosisPath(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << "Step: " << root->text << endl;
    printDiagnosisPath(root->left);
    printDiagnosisPath(root->right);
}

int main() {
    Node* root = createNode("Does the patient have a fever?");
    root->left = createNode("Is there a persistent cough?");
    root->right = createNode("Is there any joint pain?");
    root->left->left = createNode("Diagnosis: Possible Flu");
    root->left->right = createNode("Diagnosis: Common Cold");
    root->right->left = createNode("Diagnosis: Possible Arthritis");
    root->right->right = createNode("Diagnosis: Muscle Strain");
    cout << " AI Diagnosis Decision Tree" << endl;
    cout << "Full Traversal of Diagnostic Logic:" << endl;
    printDiagnosisPath(root);
    return 0;
}
