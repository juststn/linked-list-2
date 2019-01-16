//linked list project part 1, this program tests the functions in the Node and Student class

#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

//function prototypes
void addStudent(Node* &head, Node* n);
void printAll(Node* head);
void printAverage(Node* n);


int main(){

  Node* Head = NULL;
  
  int running = 1;

  string in;
  
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
     
    }
    if(in=="AVERAGE"){
      printAverage(Head);
    }
    if(in=="QUIT"){
      running = 0;
    }
    
  }
}

//addStudent, add a student using recursion
void addStudent(Node* &head, Node* n){

  if(head == NULL){
    head = n;
    return;
  }

  if(n->getStudent()->getID() < head->getStudent()->getID()){
    n->setNext(head);
    head = n;
  }
  
  else{
    Node* next = head->getNext();
    addStudent(next, n);
    head->setNext(next);
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
