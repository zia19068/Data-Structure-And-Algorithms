#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

struct QueueNode {
    Node* treeNode;
    QueueNode* next;
};

class Queue {
    QueueNode *front, *rear;
public:
    Queue() { front = rear = NULL; }
    
    void enqueue(Node* n) {
        QueueNode* temp = new QueueNode;
        temp->treeNode = n;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    
    Node* dequeue() {
        if (front == NULL) return NULL;
        QueueNode* temp = front;
        Node* n = temp->treeNode;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        return n;
    }
    
    bool isEmpty() { return front == NULL; }
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
    newNode->left = newNode->right = NULL;
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
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) return rightRotate(node);
    if (balance < -1 && data > node->right->data) return leftRotate(node);
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

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;
    Queue q;
    q.enqueue(root);
    while (!q.isEmpty()) {
        Node* current = q.dequeue();
        cout << current->data << " ";
        if (current->left != NULL) q.enqueue(current->left);
        if (current->right != NULL) q.enqueue(current->right);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    
    // 5 Insertions
    int inputs[] = {10, 20, 30, 40, 50};
    for(int i=0; i<5; i++) root = insert(root, inputs[i]);
    
    cout << "Level Order after insertions: ";
    printLevelOrder(root);

    // 2 Deletions
    root = deleteNode(root, 10);
    root = deleteNode(root, 30);

    cout << "Level Order after deletions (10, 30): ";
    printLevelOrder(root);

    return 0;
}
