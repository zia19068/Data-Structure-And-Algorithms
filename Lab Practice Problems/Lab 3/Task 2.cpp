/*Task # 02:
A Bookstore wants to maintain a list of books available in its store using a singly linked list.
Each book record contains:
 Book ID
 Book Title
 Author Name
The system should support the following operations:
 Insert a new book at the beginning of the list.
 Insert a new book at the end of the list.
 Insert a new book at a specific position in the list (any point).
 Delete a book from the beginning of the list.
 Delete a book from the end of the list.
 Delete a book from a specific position in the list (any point).
 Search for a book by its ID and display its details.*/
#include<iostream>
using namespace std;

class Node{
public:
    string Booktitle;
    string Authorname;
    int Id;
    Node* nextptr;

    Node(string title,string nam, int no){
        Booktitle=title;
        Authorname=nam;
        Id=no;
        nextptr=NULL;
    }
};

class Linklist{
public:
    Node* head;
    Node* tail;

    Linklist(){
        head = tail = NULL;
    }

    void addatstart(string title,string nam,int no){
        Node* newnode = new Node(title,nam,no);

        if(head==NULL){
            head=tail=newnode;
            return;
        }

        newnode->nextptr=head;
        head=newnode;
    }

    void addatend(string title,string nam,int no){
        Node* newnode = new Node(title,nam,no);

        if(head==NULL){
            head=tail=newnode;
            return;
        }

        tail->nextptr=newnode;
        tail=newnode;
    }

    void addatanyposition(int pos,string title,string nam,int no){
        if(pos < 0){
            cout<<"Invalid Position"<<endl;
            return;
        }

        if(pos==0){
            addatstart(title,nam,no);
            return;
        }

        Node* temp=head;
        int count=0;

        while(temp!=NULL && count<pos-1){
            temp=temp->nextptr;
            count++;
        }

        if(temp==NULL){
            cout<<"Invalid Position"<<endl;
            return;
        }

        Node* newnode = new Node(title,nam,no);
        newnode->nextptr=temp->nextptr;
        temp->nextptr=newnode;

        if(newnode->nextptr==NULL)
            tail=newnode;
    }

    void deletestart(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp=head;
        head=head->nextptr;
        delete temp;

        if(head==NULL)
            tail=NULL;
    }

    void deleteend(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node* temp=head;

        while(temp->nextptr!=tail){
            temp=temp->nextptr;
        }

        delete tail;
        temp->nextptr=NULL;
        tail=temp;
    }

    void deleteatanyposition(int pos){
        if(pos < 0 || head==NULL){
            cout<<"Invalid Position"<<endl;
            return;
        }

        if(pos==0){
            deletestart();
            return;
        }

        Node* temp=head;
        int count=0;

        while(temp!=NULL && count<pos-1){
            temp=temp->nextptr;
            count++;
        }

        if(temp==NULL || temp->nextptr==NULL){
            cout<<"Invalid Position"<<endl;
            return;
        }

        Node* delNode=temp->nextptr;
        temp->nextptr=delNode->nextptr;

        if(delNode==tail)
            tail=temp;

        delete delNode;
    }
    void display(){
    if(head == NULL){
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "\nBook List:\n";
    while(temp != NULL){
        cout << "-------------------------" << endl;
        cout << "Book Title  : " << temp->Booktitle << endl;
        cout << "Author Name : " << temp->Authorname << endl;
        cout << "Book ID     : " << temp->Id << endl;
        temp = temp->nextptr;
    }
    cout << "-------------------------" << endl;
    }
    void searchById(int id){
    if(head == NULL){
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    while(temp != NULL){
        if(temp->Id == id){
            cout << "\nBook Found:\n";
            cout << "-------------------------" << endl;
            cout << "Book Title  : " << temp->Booktitle << endl;
            cout << "Author Name : " << temp->Authorname << endl;
            cout << "Book ID     : " << temp->Id << endl;
            cout << "-------------------------" << endl;
            return;
        }
        temp = temp->nextptr;
    }

    cout << "Book with ID " << id << " not found." << endl;
    }  
  };
  int main() {
    Linklist library;

    library.addatend("C++ Easy", "Ali Raza", 101);
    library.addatend("Data Structures", "Zia Ur Rehman", 102);
    library.addatstart("Algorithms", "Shaheer Ejaz", 100);
    library.addatanyposition(2, "Operating Systems", "Hammas Allaudin", 103);

    cout << "Initial Library:" << endl;
    library.display();

    cout << "\nDeleting book at start..." << endl;
    library.deletestart();
    library.display();

    cout << "\nDeleting book at end..." << endl;
    library.deleteend();
    library.display();

    cout << "\nDeleting book at position 1..." << endl;
    library.deleteatanyposition(1);
    library.display();

    cout << "\nSearching for book with ID 102:" << endl;
    library.searchById(102);

    cout << "\nSearching for book with ID 999:" << endl;
    library.searchById(999);

    cout << "\nAdding new book at end..." << endl;
    library.addatend("Database Systems", "Junaid Khan", 104);
    library.display();

    return 0;
}

