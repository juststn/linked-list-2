//Student class functions

#include<iostream>
#include "student.h"
#include <iomanip>

using namespace std;

//constructor
Student::Student(){
  firstname[0] = '\0';
  lastname[0] = '\0';
  id = 0;
  gpa = 0;
}

//deconstructor
Student::~Student(){
}

//return firstname
string Student::getFN(){
  return firstname;
}

//return lastname
string Student::getLN(){
  return lastname;
}

//return ID
int Student::getID(){
  return id;
}

//return GPA
float Student::getGPA(){
  return gpa;
}

//create a student
void Student::makeStudent(){
  cin.ignore();
  cout<<"Enter first Name"<<endl;
  cin.getline(firstname, 100);
    
  cout << "Enter last name" << endl;
  cin.getline(lastname, 100);
  
  cout << "Enter id" << endl;
  cin >> id;
  cin.ignore();
  
  cout << "Enter gpa" << endl;
  cin >> gpa;
  cin.ignore();
}

//print out student
void Student::printStudent(){
    cout<<firstname<<" "<<lastname<<", "<<id<<", ";

    // set precision to 2 digits after the decimal point
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<gpa<<endl;
}
