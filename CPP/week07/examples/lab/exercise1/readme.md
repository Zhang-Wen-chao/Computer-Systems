Define a function whose prototype is const char* match(const char* s, char ch);
s is a C-style string, ch is a character. If the ch is in the s, return the position of s at ch; if the ch is not in the s, return NULL.
Write a test program to call the function and show the result. The output samples are as follows:

You are required to compile the function into a shared library “libmatch.so”, and then compile and run your program with this shared library.

To define a function with the given prototype `const char* match(const char* s, char ch)`, you can use the following code:

```c
#include <string.h>

const char* match(const char* s, char ch) {
    const char* pos = strchr(s, ch);
    return pos;
}
```

Explanation:
- The `strchr` function from the `<string.h>` library is used to search for the character `ch` within the string `s`.
- If `ch` is found in `s`, `strchr` returns a pointer to the first occurrence of `ch` in `s`.
- If `ch` is not found in `s`, `strchr` returns a NULL pointer.
- The function `match` simply returns the result of `strchr`.

To compile the function into a shared library named "libmatch.so" using gcc, you can use the following command:

```
gcc -shared -o libmatch.so -fPIC match.c
```

Once the shared library is created, you can write a test program to call the function and display the result. Here's an example:

```c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    // Load the shared library
    void* lib = dlopen("./libmatch.so", RTLD_LAZY);
    if (!lib) {
        fprintf(stderr, "Failed to load the library: %s\n", dlerror());
        return 1;
    }

    // Get the function pointer
    typedef const char* (*MatchFunc)(const char*, char);
    MatchFunc match = (MatchFunc)dlsym(lib, "match");
    const char* error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "Failed to get the function: %s\n", error);
        dlclose(lib);
        return 1;
    }

    // Test the function
    const char* s = "Hello, World!";
    char ch = 'W';
    const char* result = match(s, ch);
    if (result != NULL) {
        printf("Character '%c' found at position %ld in the string '%s'\n", ch, result - s, s);
    } else {
        printf("Character '%c' not found in the string '%s'\n", ch, s);
    }

    // Unload the shared library
    dlclose(lib);

    return 0;
}
```

Ensure that both the shared library "libmatch.so" and the test program are in the same directory. Then, compile and run the test program using the following command:

```
gcc -o test_program test_program.c -ldl
./test_program
```

This will load the shared library, call the `match` function, and display the result based on the provided sample.