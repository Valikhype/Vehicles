#pragma once
#include "Registration.h"
#include <cstring>

bool Registration::areEqual(const char* str1) const {
	return strcmp(str1, num) == 0;
}
bool Registration::IsEmpty(const char* str) {
    if (str[0] == '\0') return 1;
    return 0;
}
bool Registration::IsValid(const char* str) {
    if (strlen(str) < 7 || strlen(str) > 8) return 0;
    if (strlen(str) == 7) {
        if (str[0] < 'A' || str[0] > 'Z') return 0;
        for (size_t i = 1; i < 5; i++) {
            if (str[i] < '0' || str[i] > '9') return 0;
        }
        if (str[5] < 'A' || str[5] > 'Z') return 0;
        if (str[6] < 'A' || str[6] > 'Z') return 0;
    }
    if (strlen(str) == 8) {
        if (str[0] < 'A' || str[0] > 'Z') return 0;
        if (str[1] < 'A' || str[1] > 'Z') return 0;
        for (size_t i = 2; i < 6; i++) {
            if (str[i] < '0' || str[i] > '9') return 0;
        }
        if (str[6] < 'A' || str[6] > 'Z') return 0;
        if (str[7] < 'A' || str[7] > 'Z') return 0;
    }
    return 1;
}
Registration::Registration(const char* str) {
    if (IsValid(str)) {
        strcpy(num, str);
    }
}
Registration& Registration::operator=(const char* str) {

    if (IsValid(str)) {
        if (!IsEmpty(num)) {
            for (size_t i = 0; i < 9; i++)
            {
                num[i] = '\0';
            }
        }
        strcpy(num, str);
    }
    return *this;
}

bool Registration::operator==(const Registration& rhs) const {
    return(areEqual(rhs.num));
}
const char* Registration::toString() const {
    return num;
}
