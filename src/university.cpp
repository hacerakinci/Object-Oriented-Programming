/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include "university.h"


University:: University(std::string name, float w_GPA, float w_GRE, float w_TOEFL, float bias) 
:name(name), w_GPA(w_GPA), w_GRE(w_GRE), w_TOEFL(w_TOEFL), bias(bias) {}
// Constructor with parameters except country parameter

University:: University(std::string name, float w_GPA, float w_GRE, float w_TOEFL, float bias, std::string country)
:name(name), w_GPA(w_GPA), w_GRE(w_GRE), w_TOEFL(w_TOEFL), bias(bias), country(country) {}
// Constructor with all parameters


void University::evaluate_student(const Student &student) const
{
    // Add all multiplication of student feature inputs with their weights, and add bias of university
    float sum = (this->w_GPA)*(student.get_GPA()) + (this->w_GRE)*(student.get_GRE()) + (this->w_TOEFL)*(student.get_TOEFL()) + this->bias;

    // Check if the student is selected or not (activation step)
    if(sum >= 0)
    {
        std::cout<< student.get_name() << " is admitted to "<< this->name<<"."<<std::endl;
        
    }
    else
    {
         std::cout<< student.get_name() << " is rejected from "<< this->name<<"."<<std::endl;
    }

    // Increase the number of applications  
    student.set_num_of_application(student.get_num_of_application() + 1);
}
