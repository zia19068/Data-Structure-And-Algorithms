#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string d;
    string n;
    int r;
    Node* next;

    Node(string dept, string name, int roll) {
        d = dept;
        n = name;
        r = roll;
        next = NULL;
    }
};

class CircularList {
public:
    Node* head;

    CircularList() {
        head = NULL;
    }

    void add_start(string d, string n, int r) {
        Node* newNode = new Node(d, n, r);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void add_end(string d, string n, int r) {
        Node* newNode = new Node(d, n, r);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void add_at_pos(string d, string n, int r, int pos) {
        if (pos <= 1 || head == NULL) {
            add_start(d, n, r);
            return;
        }
        Node* newNode = new Node(d, n, r);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void del_start() {
        if (head == NULL) return;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }

    void del_end() {
        if (head == NULL) return;
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void del_at_pos(int pos) {
        if (head == NULL) return;
        if (pos == 1) {
            del_start();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void search(int roll) {
        if (head == NULL) return;
        Node* temp = head;
        do {
            if (temp->r == roll) {
                cout << "Found: " << temp->n << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not found" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << "[" << temp->r << "|" << temp->n << "]->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularList cl;
    cl.add_end("CS", "A", 1);
    cl.add_end("IT", "B", 2);
    cl.add_start("EE", "C", 3);
    cl.add_at_pos("ME", "D", 4, 2);
    cl.display();

    cl.del_at_pos(2);
    cl.display();

    cl.search(1);
    cl.del_start();
    cl.del_end();
    cl.display();

    return 0;
}
