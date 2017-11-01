//Student List
//allows user to enter Names, id, and GPA's of student to add them to a list. User can also print list, delete students, and quit
//Author: Kian Patton
//Date: 11/1/17
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//declare variables
bool running = true;
char command[7];
struct student {
  char first[25];
  char last[25];
  int id;
  float gpa;
} ;

//method to add students. Prompts user for information and reads them into new student struct
void addStudent(vector<student*> *studentpoint) {

  student* nstudent = new student();
  cout << "Enter student's first name." << endl;
  cin >> nstudent->first;
  cout << "Enter student's last name." << endl;
  cin >> nstudent->last;
  cout << "Enter student's ID number." << endl;
  cin >> nstudent->id;
  cout << "Enter student's GPA." << endl;
  cin >> nstudent->gpa;
  studentpoint->push_back(nstudent);
}

//method to print list of students. Iterates through vector, printing out each value of each struct
void printList(vector<student*> *studentpoint) {
  for (vector<student*>::iterator i = studentpoint->begin(); i != studentpoint->end(); i++) {
    student* nstudent = *i;
    cout << nstudent->first << " " << nstudent->last << ", ID:" << nstudent->id << ", GPA:" << fixed << setprecision(2) << nstudent->gpa << endl;
  }
}

//method to delete students. Takes input of student id and iterates through the vector to find the struct with matching id then deletes the struct and pointer
void deleteStudent(vector<student*> *studentpoint) {
  int inid;
  int x = -1;
  cout << "Enter student ID of student you would like to delete." << endl;
  cin >> inid;
  for (vector<student*>::iterator i = studentpoint->begin(); i != studentpoint->end(); i++) {
    student* nstudent = *i;
    if (nstudent->id == inid) {
      x++;
      delete (*studentpoint->begin() + x);
      studentpoint->erase(studentpoint->begin() + x);
      cout << "Student deleted." << endl;
      break;
    }
    else if (nstudent->id != inid) {
      cout << "Invalid student ID." << endl;
      x++;
    }
  }
}

void inputWord(char input[7]){
  cin >> input;
}


//main method declaring vectors and reads in user commands
int main() {

  vector<student*> studentlist;
  vector<student*> *studentpoint = &studentlist;
  
    cout << "Type ADD to add a new student." << endl;
    cout << "Type PRINT to list all the student information." << endl;
    cout << "Type DELETE to delete a student from the list." << endl;
    cout << "Type QUIT to exit program." << endl;
  
  while (running == true) {
    inputWord(command);
    if (strcmp(command, "ADD") == 0) {
      addStudent(studentpoint);
      cout << "Student added to list." << endl;
    }
    else if (strcmp(command, "PRINT") == 0) {
      printList(studentpoint);
    }
    else if (strcmp(command, "DELETE") == 0) {
      deleteStudent(studentpoint);
    }
    else if (strcmp(command, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please input a valid command." << endl;
    }
  }
  return 0;
}
