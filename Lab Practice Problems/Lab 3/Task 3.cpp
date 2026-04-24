/*Task # 03:

Solve the following problem using a Singly Linked List:
Given a Linked list of integers (input by user), write a function to modify the linked list such that
all even numbers appear before all the odd numbers in the modified linked list. Also, keep the
order of even and odd numbers same.
Examples:
Input: 17 -> 15 -> 8 -> 12 -> 10 -> 5 -> 4 -> 1 -> 7 -> 6 -> NULL
Output: 8 -> 12 -> 10 -> 4 -> 6 -> 17 -> 15 -> 5 -> 1 -> 7 -> NULL

Input: 8 -> 12 -> 10 -> 5 -> 4 -> 1 -> 6 -> NULL
Output: 8 -> 12 -> 10 -> 4 -> 6 -> 5 -> 1 -> NULL

 If all numbers are EVEN then do not change the list
Input: 8 -> 12 -> 10 -> NULL
Output: 8 -> 12 -> 10 -> NULL

 If all numbers are ODD then do not change the list
Input: 1 -> 3 -> 5 -> 7 -> NULL
Output: 1 -> 3 -> 5 -> 7 -> NULL*/
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
