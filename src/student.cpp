/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include "student.h"

// Constructors with login message

Student:: Student()
{
   std::cout<< name << " logged in to the system."<<std::endl;    
} // Default constructor

Student::Student(std::string name, float GPA, float GRE, float TOEFL)
:name(name), GPA(GPA), GRE(GRE), TOEFL(TOEFL)
{
    std::cout<< name << " logged in to the system."<<std::endl;
} // Constructor with parameters

Student:: Student( const Student& originalStudent)
:name(originalStudent.name), GPA(originalStudent.GPA), GRE(originalStudent.GRE), TOEFL(originalStudent.TOEFL)
{
   std::cout<< name << " logged in to the system."<<std::endl;    
} // Copy constructor 

// Getters

std::string Student::get_name() const
{
    return this->name;
}

float Student::get_GPA() const
{
    return this->GPA;
}

float Student::get_GRE() const
{
    return this->GRE;
}

float Student::get_TOEFL() const
{
    return this->TOEFL;
}

int Student::get_num_of_application() const
{
    return this->num_of_application;
}

// Setters

void Student::set_name(std::string name)
{
    this->name = name;
}

// This function is const, because evenfor const objects we should increase this variable.
void Student::set_num_of_application(int num_of_application) const 
{
    this->num_of_application = num_of_application;
}

// Destructor with logout message
Student::~Student()
{
      std::cout<< this-> name << " logged out of the system with "<< this->num_of_application<<" application(s)."<<std::endl;
}