Define a function that swaps two values of integers. Write a test program to call the function and display the result.

You are required to compile the function into a static library “libswap.a”, and then compile and run your program with this static library.








To create a static library "libswap.a" containing a function that swaps two integer values, you need to follow these steps:

1. Write the swap function in a source file, for example, "swap.cpp":

```cpp
#include "swap.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

2. Create a header file "swap.h" to declare the swap function:

```cpp
#ifndef SWAP_H
#define SWAP_H

void swap(int& a, int& b);

#endif
```

3. Compile the source file into an object file using the following command:

```shell
g++ -c swap.cpp -o swap.o
```

4. Create the static library "libswap.a" using the object file:

```shell
ar rcs libswap.a swap.o
```

Now, you have the static library "libswap.a" that contains the swap function.

To write a test program that calls the swap function and displays the result, follow these steps:

1. Write the test program, for example, "main.cpp":

```cpp
#include <iostream>
#include "swap.h"

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    swap(a, b);

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}
```

2. Compile and link the test program with the static library:

```shell
g++ main.cpp -L. -lswap -o test_swap
```

The `-L.` flag specifies the current directory as the location to search for libraries, and the `-lswap` flag specifies the library name without the "lib" prefix and ".a" extension.

3. Run the test program:

```shell
./test_swap
```

You should see the output displaying the values before and after swapping.

Note: Make sure the "libswap.a" file and "swap.h" header file are in the same directory as your "main.cpp" file when compiling and linking the test program.