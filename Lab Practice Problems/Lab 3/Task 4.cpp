#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char val) {
        data = val;
        next = NULL;  
    }
};

void append(Node** head_ref, char new_data) {
    Node* new_node = new Node(new_data);

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

bool isPalindrome(Node* head) {
    if (head == NULL)
        return true;

    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    char arr[100]; 
    temp = head;
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    for (int j = 0; j < count / 2; j++) {
        if (arr[j] != arr[count - j - 1])
            return false;
    }

    return true;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    char word[100];

    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < strlen(word); i++) {
        append(&head, word[i]);
    }

    cout << "\nLinked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "\ntrue" << endl;
    else
        cout << "\nfalse" << endl;

    return 0;
}
