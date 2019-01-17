//Student Class definitions

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

//definition of Student class
class Student{
 public:
  Student();
  ~Student();

  //functions
  string getFN();
  string getLN();
  int getID();
  float getGPA();
  void makeStudent();
  void printStudent();
  
private:
  //variables
  char firstname[100];
  char lastname[100];
  int id;
  float gpa;
  
};
#endif
