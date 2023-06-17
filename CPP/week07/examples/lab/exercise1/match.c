#include <string.h>

const char* match(const char* s, char ch) {
    const char* pos = strchr(s, ch);
    return pos;
}
