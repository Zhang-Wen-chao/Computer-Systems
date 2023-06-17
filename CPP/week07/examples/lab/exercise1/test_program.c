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
