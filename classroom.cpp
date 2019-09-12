#include <iostream>
#include "classroom.h"

classroom::classroom()
{
    numberofstudents = 0;
    studentclass = new Student[numberofstudents];
}
classroom::~classroom()
{
   delete[] studentclass;
}
void classroom::addStudent(Student newstudent)
{
    studentclass[numberofstudents] = newstudent;
    numberofstudents++;
    studentclass = resize(studentclass);
}
Student* classroom::resize(Student* currentClass)
{
    Student* output = new Student[numberofstudents];
    for(int i = 0; i < numberofstudents; i++)
    {
        output[i] = currentClass[i];
    }
    return output;
}
void classroom::attendance()
{
    std::cout << "Roll call: " << std::endl;
    for(int i = 0; i <= numberofstudents; i++)
    {
        std::cout << studentclass[i].nameGet() << " " ;
    }
    std::cout << std::endl;
}
void classroom::reportCardAll()
{}
float* classroom::gpa()
{}
std::string classroom::letterGrade()
{
}
void classroom::setMaxmark(float* input, int maxmarksize)
{
    this -> maxmark = input; 
    this -> maxmarksize = maxmarksize;
    std::cout << "Maxmark is: ";
    for(int i = 0; i < maxmarksize-1; i++)
    {
        std::cout << this -> maxmark[i] << " ";
    }
    std::cout << std::endl;
}
void classroom::setWeight(float* input, int weightsize)
{
    this -> weight = input;
    this -> weightsize = weightsize;
    std::cout << "Weight is: ";
    for(int i = 0; i < weightsize-1; i++)
    {
        std::cout << this -> weight[i] << " ";
    }
    std::cout << std::endl;
}
