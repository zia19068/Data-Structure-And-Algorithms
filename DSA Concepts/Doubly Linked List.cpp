#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string d;
    string n;
    int r;
    Node* next;
    Node* prev;

    Node(string dept, string name, int roll) {
        d = dept;
        n = name;
        r = roll;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    void add_start(string d, string n, int r) {
        Node* newNode = new Node(d, n, r);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void add_end(string d, string n, int r) {
        Node* newNode = new Node(d, n, r);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void add_at_pos(string d, string n, int r, int pos) {
        if (pos <= 1) {
            add_start(d, n, r);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            add_end(d, n, r);
            return;
        }
        Node* newNode = new Node(d, n, r);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void del_start() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
    }

    void del_end() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void del_at_pos(int pos) {
        if (head == NULL) return;
        if (pos == 1) {
            del_start();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) return;
        if (temp->next == NULL) {
            del_end();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int roll) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->r == roll) {
                cout << "Found: " << temp->n << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "<-[" << temp->r << "| " << temp->n << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dl;
    dl.add_end("CS", "A", 1);
    dl.add_end("IT", "B", 2);
    dl.add_start("EE", "C", 3);
    dl.add_at_pos("ME", "D", 4, 2);
    dl.display();
    
    dl.del_at_pos(2);
    dl.display();
    
    dl.search(1);
    return 0;
}
