#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "Registration.h"
class Vehicle {
public:
    const Registration regnum;
    char* description;

    Vehicle() = delete;
    Vehicle& operator=(Vehicle& other) = delete;
    Vehicle(const Vehicle& other);
    Vehicle(char* str);
    ~Vehicle();
};