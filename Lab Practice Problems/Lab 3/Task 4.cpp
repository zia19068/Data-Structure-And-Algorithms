/*Task # 04:

A text editor stores each character of a word in a singly linked list, where each node contains a
single character.
The editor needs to check whether the word entered by the user is a Palindrome (a string that
reads the same forwards and backwards, e.g. madam, level).
Tasks:
1. Implement a singly linked list to store the characters of the word.
2. Write a function to check whether the linked list forms a palindrome.
3. Display an appropriate message:
 If the word is a palindrome → display true
 Otherwise → display false*/
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
