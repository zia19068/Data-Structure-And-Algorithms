/*Question # 01
Scenario: A company has a legacy database where user IDs were stored in a standard Binary Search
Tree (BST). Over time, the tree has become highly skewed (like a linked list), making search
operations inefficient. Lab Task: Write a C++ function balanceExistingBST(Node* root) that
follows the manual&#39;s approach:
1. Perform an inorder traversal of the skewed tree and store the values in a ListNode linked
list.
2. Implement the recursive buildBalancedTree function to take that linked list and reconstruct
a balanced BST by picking the middle element as the root for each subtree.
3. Demonstrate the difference in tree height before and after the conversion.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct ListNode {
    int val;
    ListNode* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

ListNode* createListNode(int val) {
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void inorderToLinkedList(Node* root, ListNode*& head, ListNode*& tail) {
    if (root == NULL) return;
    inorderToLinkedList(root->left, head, tail);
    
    ListNode* newNode = createListNode(root->data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    
    inorderToLinkedList(root->right, head, tail);
}

Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

int getHeight(Node* root) {
    if (root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

Node* balanceExistingBST(Node* root) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    inorderToLinkedList(root, head, tail);

    int temp[100];
    int count = 0;
    ListNode* curr = head;
    while (curr != NULL) {
        temp[count++] = curr->val;
        curr = curr->next;
    }

    return sortedArrayToBST(temp, 0, count - 1);
}

int main() {
    Node* root = createNode(10);
    root->right = createNode(20);
    root->right->right = createNode(30);
    root->right->right->right = createNode(40);
    root->right->right->right->right = createNode(50);

    cout << "Height before balancing: " << getHeight(root) << endl;

    root = balanceExistingBST(root);

    cout << "Height after balancing: " << getHeight(root) << endl;

    return 0;
}
