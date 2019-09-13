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
  int maxmarksize;
  float* weight;
  int weightsize;

  public:
  
  classroom();
  ~classroom();
  void addStudent(Student newstudent);
  void attendance();
  void reportCardAll();
  float gpa(Student curr);
  std::string letterGrade();
  void setMaxmark(float* input, int maxmarksize);
  void setWeight(float* input, int weightsize);

  protected:
  void resize();
  




};
#endif
