#ifndef HUMAN_MATH_H
#define HUMAN_MATH_H

extern "C" {
    const char* dot_add(const char* a, const char* b);
    const char* dot_sub(const char* a, const char* b);
    const char* dot_mul(const char* a, const char* b);
    const char* dot_div(const char* a, const char* b);
    const char* dot_mod(const char* a, const char* b);
    void free_string(char* str);
}

#endif