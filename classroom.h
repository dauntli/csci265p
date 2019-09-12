#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <iostream>
#include "student.h"

class classroom
{
  private:
  int numberofstudents;
  Student* studentclass;
  float* maxmark;
  float* weight;
  int weightsize;

  public:
  classroom();
  ~classroom();
  void addStudent(Student newstudent);
  void attendance();
  void reportCardAll();
  float* gpa();
  std::string letterGrade();
  void setMaxmark(float* input);
  void setWeight(float* input, int weightsize);

  protected:
  Student* resize(Student* currentClass);
  




};
#endif
