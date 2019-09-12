#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "student.h"
#include "classroom.h"

const std::string title_const = "TITLE";
const std::string maxmark_const = "MAXMARK";
const std::string cat_const = "CATEGORY";
const std::string weight_const = "WEIGHT";
const std::string rule_const = "RULE";
const std::string comment_const = "#";



float* stringtofloat(std::string* input, int size);
std::string* trimmer(std::string untrimmed, int &size);
void printStringArray(std::string* input, int size);
std::string* categorySetter(std::string* input, int size,  int &numberofcategories);
void showTime();



int main(int argv, char *argc[])
{
     showTime();
     std::string title_input;
     std::string cat_input;
     std::string maxmark_input;
     std::string weight_input; 
     std::string path = "";
     int numberofstudents = 0;
     int numberofcategories = 0;
     classroom myclassroom;

     //Student* classroom = new Student[numberofstudents];
    

     //if they gave an argument for the path, it will be stored in the path variable
     if(argc[1] != NULL)
     {
          path = argc[1];
     }else 
     {
         std::cout<<"Please enter a filename"<< std::endl;
         std::cin >> path;
     }




     //going through the file and checking the first word with if statements. if first word 
     //is one of the constants, it will save the data in the respective string. checks
     //for whitespace and blank lines and the default case is to make a new student. 
     std::ifstream inputFile(path);
     std::string c;
       while (std::getline(inputFile, c))
       {
         std::string copy = c;
         std::string firstword = copy.substr(0, copy.find(' '));
	 if (firstword == title_const)
         {
             title_input = c;
	 } else if (firstword == cat_const)
         {
             cat_input = c;
	 } else if (firstword == maxmark_const)
         {
             maxmark_input = c;
	 } else if (firstword == weight_const)
         {
             weight_input = c;
	 } else if (firstword == rule_const)
         {
             std::cout << "Rule detected" << std::endl;
         }else if (firstword == comment_const || firstword == " " || c.length() == 0)
         {
         } else 
         {
             int studentsize;
             //std::cout << "Make a new student called " << firstword << " with data of \n";
             std::string* studentdata =  trimmer(c, studentsize);
             //printStringArray(studentdata, studentsize);
             //classroom[numberofstudents] = Student(firstword, studentdata, studentsize);
             numberofstudents ++;
             myclassroom.addStudent(Student(firstword, studentdata, studentsize));
         }
        }
 
       myclassroom.attendance();
       
       inputFile.close();

       int maxmark_size, weight_size, title_size, cat_size;
       std::string* maxmark = trimmer(maxmark_input, maxmark_size);
       //std::string* weight = trimmer(weight_input, weight_size);
       std::string* title = trimmer(title_input, title_size);
       std::string* cat = trimmer(cat_input, cat_size);

       printStringArray(maxmark, maxmark_size);
       printStringArray(title, title_size);
       //printStringArray(weight, weight_size);
       std::string* validcategories = categorySetter(cat, cat_size, numberofcategories);
       printStringArray(validcategories, numberofcategories); 

       float* weight = stringtofloat(trimmer(weight_input, weight_size), weight_size);
       //myclassroom.setWeight(weight, weight_size); 
}
std::string* trimmer(std::string untrimmed, int &size)
{
     std::istringstream mystream;
     mystream.str(untrimmed);
     std::string x;
     int ctr = 0;
     while(mystream >> x)
     {  
         ctr++;   
     }
     std::string* data = new std::string[ctr];
     std::istringstream secondstream;
     secondstream.str(untrimmed);
     std::string x2;
     int y = 0;
     secondstream >> x2;
     while(secondstream >> x2)
     {  
           data[y] = x2;
           y++;   
     } 
     size = ctr;
     return data;
}
void printStringArray(std::string* input, int size)
{
     for (int i = 0; i < size; i++)
       {
            std::cout << input[i] << " ";
       }
     std::cout << "\n";

}
std::string* categorySetter(std::string* input, int size,  int &numberofcategories)
{
     int category = 0;
     std::string* copy = new std::string[size];
     for(int i = 0; i < size; i++)
     {
         bool alreadyexists = false;
         for(int j = 0; j < size; j++)
         {
             if(input[i] == copy[j])
             {
                 alreadyexists = true;
             }
           
         }
         if(alreadyexists == false)
         {
             category ++;   
             copy[category-1] = input[i]; 
         }

     }
     numberofcategories = category;
     return copy;
} 
void showTime()
{ 
  //had to get help with finding out about time structs
  time_t mytime;
  struct tm * timeinfo;
  time (&mytime);
  std::cout << asctime(localtime(&mytime));
}
float* stringtofloat(std::string* input, int size)
{ 
   float* output = new float[size];
   for(int i = 0; i < size; i++)
   {
      output[i] = std::stof(input[i]);
   }
   return output;
}
