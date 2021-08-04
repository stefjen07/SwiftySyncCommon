#ifndef HELPER_H
#define HELPER_H

#define UUID_SIZE 36

#include <string>

std::string create_uuid();

std::string create_uuid() {
    const char *v = "0123456789abcdef";
    const bool dash[] = {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0};

    std::string res;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) res += "-";
        res += v[rand() % 16];
        res += v[rand() % 16];
    }
    return res;
}

#endif