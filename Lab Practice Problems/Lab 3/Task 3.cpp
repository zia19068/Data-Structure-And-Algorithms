#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
Node(int val) : data(val), next(NULL) {}};

Node* segregateEvenOdd(Node* head) {
    if (!head) return NULL;

    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* oddStart = NULL;
    Node* oddEnd = NULL;

    Node* curr = head;

    while (curr != NULL) {
        int val = curr->data;

        if (val % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = curr;
                evenEnd = evenStart;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = curr;
                oddEnd = oddStart;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }
     if (evenStart == NULL || oddStart == NULL) {
        return head;
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    return evenStart;
}
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        append(&head, value);
    }

    cout << "\nOriginal List: " << endl;
    printList(head);

    head = segregateEvenOdd(head);

    cout << "\nModified Linked List (Even before Odd): " << endl;
    printList(head);

    return 0;
}
