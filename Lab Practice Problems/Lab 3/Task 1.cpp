/*Task # 01:

A university wants to maintain a dynamic list of students registering for a course. Each student
has a roll number, name, and department.
Implement a singly linked list to store student data.
Write functions to:
1. Add a new student at the end of the list.
2. Delete a student by roll number.
3. Display all registered students.
Question: Implement the above scenario in C++.*/
#include<iostream>
using namespace std;
class Node{
	public:
	string department;
	string name;
	int rollnumber;
	Node* nextptr;
	Node(string dept,string nam, int no){
		department=dept;
		name =nam;
		rollnumber=no;
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
    void add_student(string dept, string nam, int no){
    Node* newnode = new Node(dept, nam, no);

    if(head == NULL){
        head = tail = newnode;
        return;
    }

    tail->nextptr = newnode;
    tail = newnode;
}
	void display(){
        if(head == NULL){
            cout << "No students in the list." << endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            cout << "Department: " << temp->department << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Roll Number: " << temp->rollnumber << endl;
            cout << "-------------------------" << endl;
            temp = temp->nextptr;
        }
    }
    void delete_student(int roll){
    	Node* temp = head;
    	Node* temp1 ;
    	int idx=0;
    	while(temp->rollnumber !=roll){
    		temp=temp->nextptr;
    		idx++;
    		}
    	if(head->rollnumber==roll){
    		temp = head;
    		temp1=temp->nextptr;
	     	head=temp1;
	    	delete temp;
	    	return;
		}
    	int i;
    	temp = head;
    	for(i=0;i<idx-1;i++){
		temp=temp->nextptr;
	    }
	    temp1=temp->nextptr;
		temp->nextptr=temp1->nextptr;
		delete temp1;
	}
	
	
};
int main(){
    Linklist students;
    students.add_student("Computer Science", "Jawad", 101);
    students.add_student("Electrical Engineering", "Saim", 102);
    students.add_student("Mechanical Engineering", "Ahmed", 103);
    students.add_student("Software Engineering", "Fatima", 104);

    cout << "Student List:\n";
    cout << "=========================\n";
    students.display();
    students.delete_student(101);
    students.delete_student(103);
    cout << endl;
    cout << "Updated Student List:\n";
    cout << "=========================\n";
    students.display();
    students.add_student("Applied Physics", "Junaid", 105);
    students.add_student("Computer Science", "Zaid", 106);
    students.add_student("Data Science", "Nawaz", 107);
    cout << endl;
    cout << "Updated Student List:\n";
    cout << "=========================\n";
    students.display();
    students.delete_student(106);
    cout << endl;
    cout << "Updated Student List:\n";
    cout << "=========================\n";
    students.display();
    

    return 0;

}
