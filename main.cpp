/*Justin He-
Linked lists part 2, 
this program is a Student List program that uses linked lists/nodes and recursion

COMMANDS:
ADD- add an entry for a student
PRINT- prints out all stored students
DELETE-removes student node from linked list, by searching for id number. 
AVERAGE- print the average GPA of all stored students (2 decimal places)
QUIT- exit the program
*/

#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

//function prototypes
void addStudent(Node* &head, Node* n);
void printAll(Node* head);
void printAverage(Node* n);
void deleteStudent(Node* &head, int id);

int main(){

  Node* Head = NULL;
  
  int running = 1;

  string in;
   int id = 0;

   //loop until a quit command
    while(running == 1){
    
    cout<<"enter command:[ADD,PRINT,DELETE,AVERAGE,QUIT] "<<endl;
    cin>>in;
    if(in=="ADD"){
      
      Student* s = new Student;
      s -> makeStudent();
      Node* n = new Node;
      n->setStudent(s);  // add s to node n
      
      addStudent(Head,n); 
    }
    if(in=="PRINT"){
      printAll(Head);
    }
    if(in=="DELETE"){
      if (Head == NULL)
	cout << "No student in list." << endl;
      else
      {	
         cout<<"Input ID number to delete: "<<endl;
         cin>>id;
         cin.ignore();

         deleteStudent(Head,id);
      }
      
    }
    if(in=="AVERAGE"){
      printAverage(Head);
    }
    if(in=="QUIT"){
      running = 0;
    }
    
  }
}

//addStudent, add a student
void addStudent(Node* &head, Node* n){

  if(head == NULL){
    head = n;
    return;
  }

  if(n->getStudent()->getID() < head->getStudent()->getID()){
    n->setNext(head);
    head = n;
  }

  //recursive call
  else{
    Node* next = head->getNext();
    addStudent(next, n);
    head->setNext(next);
  }
  
}

//deleteStudent, remove stored students
void deleteStudent(Node* &head, int id){
  //Node* temp;

  if(head == NULL){
    // cout<< "invalid id"<<endl;
    return;
  }
  
  //if the scanned id is equal to the searched id, the node will be deleted.
  if(head->getStudent()->getID()==id){
    
    Node *temp = head;
    head = head->getNext();

    delete temp->getStudent();   // deconstruct
    cout<<"Student " << id<<" deleted."<<endl;

    deleteStudent(head, id);  // recursive call
    
    return;
  }
  
  //recursion to cycle through list until if statement found.
  else{
    Node* temp = head->getNext();
    deleteStudent(temp, id);      // recursive call
    head ->setNext(temp);
  }
}

//printAll, prints all information of students sorted by student id number (least to greatest) with recursion
void printAll(Node* head){
  if(head==NULL){
    cout << endl;
    return;
  }
  else{
    head->getStudent()->printStudent();
    printAll(head->getNext());

  }
}

//printAverage, prints average of all added GPAs
void printAverage(Node* n){
  
   float sum = 0;
   int count = 0;
   float avg = 0;
   
   Node* temp = n;

   if(temp == NULL){
     cout << "No students"<<endl;
     return;
   }

   //while the head isnt null, add gpa of each student
   while(temp!=NULL){
     sum = sum + temp->getStudent()->getGPA();
     count++;
     temp = temp->getNext();
   }

   avg = sum/count;
   cout<< "Average = ";
   cout.setf(ios::fixed);
   cout.precision(2);
   cout<<avg<<endl;
   
    return;
}
