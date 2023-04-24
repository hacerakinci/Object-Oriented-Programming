/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include <string>
#include <iostream>


class Student
{
    public:
    Student(); // Default constructor
    Student(const Student&); // Copy constructor    
    Student(std::string, float, float, float); // Constructor with parameters
    ~Student(); // Destructor

    // Getters
    std::string get_name() const;
    float get_GPA() const;
    float get_GRE() const;
    float get_TOEFL() const;
    int get_num_of_application() const;
    
    // Setters
    void set_name(std::string);
    void set_num_of_application(int) const;
    // According to main.cpp file another setter funcion is not required. 

    private:
    std::string name = "";
    const float GPA = 0;
    const float GRE = 0;
    const float TOEFL = 0;
    mutable int num_of_application = 0; // To make changes in the evaluate_student function for a const object, this variable must be mutable

};