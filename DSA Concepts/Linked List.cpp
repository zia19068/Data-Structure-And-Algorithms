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

class Linklist {
public:
    Node* head;

    Linklist() {
        head = NULL;
    }

    void add_start(string d, string n, int r) {
        Node* newNode = new Node(d, n, r);
        newNode->next = head;
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
    }

    void add_at_pos(string d, string n, int r, int pos) {
        if (pos <= 1) {
            add_start(d, n, r);
            return;
        }
        Node* newNode = new Node(d, n, r);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void del_start() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
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
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void del_at_pos(int pos) {
        if (head == NULL) return;
        if (pos == 1) {
            del_start();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void search(int roll) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->r == roll) {
                cout << "Found " << temp->n << " at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "[" << temp->r << "|" << temp->n << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Linklist l;
    l.add_end("CS", "A", 1);
    l.add_end("IT", "B", 2);
    l.add_end("EE", "C", 3);
    l.display();

    l.add_at_pos("ME", "New", 99, 2);
    l.display();

    l.del_at_pos(3);
    l.display();

    l.search(99);

    return 0;
}
