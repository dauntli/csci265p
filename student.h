#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
class Student
{
     private:
     std::string name;
     float* grades;
     int size;

     public:
     Student(std::string name, std::string* stringgrade, int size);
     Student();
     ~Student();
     Student(std::string name);
     std::string nameGet();
<<<<<<< HEAD
     float gradeGet(int index);
     float operator[] (int i);

=======
 
>>>>>>> parent of a76b9df... problem with the math of the grades, cannot access each students grade in classroom::gpa
};

#endif
