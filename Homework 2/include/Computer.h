/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include <string>
#include <iostream>

class ALU 
{
    public:
    ALU(const int);
    int add(const int, const int) const;
    int subtract(const int, const int) const;
    int multiply(const int, const int) const;
    
    private:
    const int numPerCores = 0;

};

class CUDA
{
    public:
    CUDA(const int);
    std::string render() const;
    std::string trainModel() const;

    private:
    const int numCores = 0;

};


class CPU  
{
    public:
    CPU (const int);
    int execute(const std::string);
    
    private:
    const ALU myALU;

};

class GPU
{
    public:
    GPU (const int);
    std::string execute(const std::string);
    
    private:
    const CUDA myCUDA;

};

class Computer
{
    public:
    Computer();

    // Getters for private members
    CPU getAttachedCPU();
    GPU getAttachedGPU();

    // Overloading '+' operator for CPU and GPU classes
    void operator+(const CPU&);
    void operator+(const GPU&);

    // call CPU or GPU execute function according to given string
    void execute(const std::string);

    private:
    // the relationship is aggregation, so Computer class has addresses of its members (CPU, GPU) 
    const CPU* attachedCPU = NULL;
    const GPU* attachedGPU = NULL;
    // Computer object can see CPU and GPU object

};
