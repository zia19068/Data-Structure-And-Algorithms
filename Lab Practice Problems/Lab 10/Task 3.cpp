/*Question # 03
Scenario: You are building a digital dictionary. Inserting certain word combinations creates a
&quot;double imbalance&quot; where a node&#39;s child is heavy on the opposite side of the parent&#39;s imbalance.
Lab Task:
1. Implement the insert function to handle the Left-Right (LR) and Right-Left (RL) cases.
2. Using the manual’s logic, write code that first performs a rotation on the child node and then
a second rotation on the original unbalanced node.
3. Verify the balance by inserting the sequence {13, 10, 11} and ensure the final root is 11.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    Node* root = NULL;
    int arr[] = {13, 10, 11};

    for (int i = 0; i < 3; i++) {
        root = insert(root, arr[i]);
    }

    if (root != NULL) {
        cout << "Final Root: " << root->data << endl;
        
        cout << "Left Child: ";
        if (root->left) cout << root->left->data; else cout << "NULL";
        cout << endl;

        cout << "Right Child: ";
        if (root->right) cout << root->right->data; else cout << "NULL";
        cout << endl;
    }

    return 0;
}
