#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
class Assignment 
{
     private:
     std::string title;
     std::string category;
     float mark;
     float maxmark;
     float weight;
     Assigment(std::string title, std::string category, float mark, float maxmark, float weight)
     {
          title = title;
          category = category;
          mark = mark;
          maxmark = maxmark;
          weight = weight;
     }
};
class Student
{
     private:
     std::string name;
     float* grades;
     public:
     Student(std::name, std::string stringgrade, int size)
     {
         name = name;
         float* grades = new float[size];
         for (int i = 0; i < size; i ++)
         {
             grades[i] = float(stringgrade[i]);
         }
     }
};
#endif
