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
     float gradeGet(int index);
     float operator[] (int i);
};
#endif
