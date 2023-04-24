/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include <string>
#include <iostream>
#include "student.h"

class University
{
    public:
    University(std::string, float, float, float, float); // Constructor with parameters except country parameter
    University(std::string, float, float, float, float, std::string); // Constructor with all parameters
    
    // There is nowhere to use getters, for this example it is unnecessary to write getters.

    // To call a const object, function must be const member function
    void evaluate_student(const Student&) const; 

    private:
    const std::string name = "";
    const float w_GPA;
    const float w_GRE;
    const float w_TOEFL;
    const float bias;
    const std::string country = "";

};