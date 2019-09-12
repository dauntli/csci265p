#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
class Student
{
     private:
     std::string name;
     float* grades;
     public:
     Student(std::string name, std::string* stringgrade, int size);
     Student();
     ~Student();
     Student(std::string name);
     std::string nameGet();
 
};

#endif
