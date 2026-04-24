#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node* left;
    Node* right;

    Node(int v) {
        d = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* insert(Node* node, int v) {
        if (node == NULL) {
            return new Node(v);
        }
        if (v < node->d) {
            node->left = insert(node->left, v);
        } else {
            node->right = insert(node->right, v);
        }
        return node;
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->d << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->d << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->d << " ";
    }

    bool search(Node* node, int k) {
        if (node == NULL) return false;
        if (node->d == k) return true;
        if (k < node->d) return search(node->left, k);
        return search(node->right, k);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    Node* remove(Node* node, int k) {
        if (node == NULL) return NULL;

        if (k < node->d) {
            node->left = remove(node->left, k);
        } else if (k > node->d) {
            node->right = remove(node->right, k);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->d = temp->d;
            node->right = remove(node->right, temp->d);
        }
        return node;
    }
};

int main() {
    BinaryTree bt;
    bt.root = bt.insert(bt.root, 50);
    bt.insert(bt.root, 30);
    bt.insert(bt.root, 70);
    bt.insert(bt.root, 20);
    bt.insert(bt.root, 40);

    cout << "Inorder: ";
    bt.inorder(bt.root);
    cout << endl;

    cout << "Search 40: " << (bt.search(bt.root, 40) ? "Found" : "Not Found") << endl;

    bt.root = bt.remove(bt.root, 30);
    cout << "Inorder after deleting 30: ";
    bt.inorder(bt.root);
    cout << endl;

    return 0;
}
