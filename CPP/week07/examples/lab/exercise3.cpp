/*
Overload a function bool vabs(int * p, int n) which can compute the absolute value for every element of an array, the array can be int, float and double.

 Should n be int or size_t? what's the difference? Remember to check whether the pointer is valid.


Explanation:

The vabs function is overloaded for three different types: int*, float*, and double*. Each overload accepts a pointer to the respective array type and the number of elements in the array (n).
Inside each overload, we first check if the pointer is nullptr (i.e., not valid). If it is nullptr, we print an error message and return false.
For each element in the array, we calculate the absolute value using std::abs for int arrays and std::fabs for float and double arrays.
Finally, we demonstrate the usage of the overloaded vabs function by passing arrays of different types and printing the updated arrays.
*/


#include <iostream>
#include <cmath>

// Overload for int array
bool vabs(int* p, int n)
{
    if (p == nullptr)
    {
        std::cout << "Invalid pointer!" << std::endl;
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = std::abs(p[i]);
    }

    return true;
}

// Overload for float array
bool vabs(float* p, int n)
{
    if (p == nullptr)
    {
        std::cout << "Invalid pointer!" << std::endl;
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = std::fabs(p[i]);
    }

    return true;
}

// Overload for double array
bool vabs(double* p, int n)
{
    if (p == nullptr)
    {
        std::cout << "Invalid pointer!" << std::endl;
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = std::fabs(p[i]);
    }

    return true;
}

int main()
{
    int arr1[] = { -1, 2, -3, 4, -5 };
    float arr2[] = { -1.1f, 2.2f, -3.3f, 4.4f, -5.5f };
    double arr3[] = { -1.1, 2.2, -3.3, 4.4, -5.5 };

    vabs(arr1, sizeof(arr1) / sizeof(arr1[0]));
    vabs(arr2, sizeof(arr2) / sizeof(arr2[0]));
    vabs(arr3, sizeof(arr3) / sizeof(arr3[0]));

    // Print the updated arrays
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
