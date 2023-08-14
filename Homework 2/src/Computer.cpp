/* @Author
 * Student Name:  Hacer Akıncı
 * Student ID : 150200007
 */

#include "Computer.h"

//Computer

// Default constructor of Computer
Computer::Computer()
{
    std::cout << "Computer is ready" << std::endl;
}

CPU Computer::getAttachedCPU()
{
    return *this->attachedCPU;
}

GPU Computer::getAttachedGPU()
{
    return *this->attachedGPU;
}

// operator overload for CPU
void Computer::operator+(const CPU& newCPU)
{
    if (this->attachedCPU != NULL)
    {
        std::cout << "There is already a CPU" << std::endl;
    }
    else
    {
        this->attachedCPU = (&newCPU);
        std::cout << "CPU is attached" << std::endl;
    }
}

// operator overloadi for GPU
void Computer::operator+(const GPU& newGPU)
{
    if (this->attachedGPU != NULL)
    {
        std::cout << "There is already a GPU" << std::endl;
    }
    else
    {
        this->attachedGPU = &newGPU;
        std::cout << "GPU is attached" << std::endl;
    }
}

void Computer::execute(const std::string operation)
{
    // CPU operations    
    if (operation == "add" || operation == "subtract" || operation == "multiply")
    {
       int res = getAttachedCPU().execute(operation);
       std::cout << res << std::endl;
    }

    // GPU operations
    else if (operation == "render" || operation == "trainModel")
    {
       std::string res = getAttachedGPU().execute(operation);
       std::cout << res << std::endl;
    }
    
}

// CPU

// CPU constructor with parameter
CPU::CPU(const int numPerCores): myALU{numPerCores}
{
    std::cout << "CPU is ready" << std::endl;
}

int CPU::execute(const std::string operation)
{
    std::cout << "Enter two integers" << std::endl;

    int x, y, res = 0; // res keeps the result of ALU operation
    std::cin >> x >> y;     

    if (operation == "add")
    {
        res = myALU.add(x, y);
    }
    else if (operation == "subtract")
    {
        res = myALU.subtract(x ,y);
    }
    else if (operation == "multiply")
    {
        res = myALU.multiply(x ,y);
    }

    return res;
}

// GPU

// GPU constructor with parameter
GPU::GPU(const int numCores): myCUDA{numCores}
{
    std::cout << "GPU is ready" << std::endl;
}

std::string GPU::execute(const std::string operation)
{
    std::string res = ""; // keeps the result string
    
    if(operation == "render")
    {
        res = myCUDA.render();
    }
    else if(operation == "trainModel")
    {
        res = myCUDA.trainModel();
    }

    return res;
}

// ALU

// ALU constructor with parameter
ALU::ALU(const int num):numPerCores{num}
{
    std::cout << "ALU is ready" << std::endl;
}

int ALU::add(const int x, const int y) const
{
    return x + y;
}

int ALU::subtract(const int x, const int y) const
{
    return x - y;
}

int ALU::multiply(const int x, const int y) const
{
    return x * y;
}

// CUDA

// CUDA constructor with parameter
CUDA::CUDA(const int num):numCores{num}
{
    std::cout << "CUDA is ready" << std::endl;
}

std::string CUDA::render() const
{
    return "Video is rendered";
}

std::string CUDA::trainModel() const
{
    return "AI Model is trained";
}