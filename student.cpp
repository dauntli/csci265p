#include <iostream>
#include <string>
#include "student.h"
Student::Student()
{
    this -> name = "";
}
Student::Student(std::string name, std::string* stringgrade, int size)
{
     this -> name = name;
     this -> size = size;
     float* grades = new float[size];
     std::cout << "Instantiating new student with name of " << name << " and data of: ";
     for (int i = 0; i < size-1; i ++)
     {   
         grades[i] = std::stof(stringgrade[i]);
         std::cout << grades[i] << " ";
     }
     std::cout<<"\n";
}
Student::Student(std::string name)
{
     this -> name = name;
     std::cout <<"declaring new student with name of "<< name << std::endl;
}
std::string Student::nameGet()
{
    return name;
}
Student::~Student()
{
   delete [] grades;  
   grades = 0; 
}
float Student::gradeGet(int index)
{ 
    return grades[index];
}
float Student::operator[] (int i)
{
   return grades[i];
}
