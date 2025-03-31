#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include"Registration.h"
#include"Vehicle.h"

#include <cstring>    
class VehicleList {
public:
    size_t size;
    const size_t capacity;
    Vehicle** vehicles;
    ~VehicleList();
    VehicleList& operator=(VehicleList& other) = delete;
    VehicleList(size_t capacity1);
    VehicleList(VehicleList& other);

    const Vehicle& operator[](size_t pos) const;
    const Vehicle& at(size_t index) const;
   
    bool IsValidIn(Vehicle& other);
    bool IsValidInStr(char* str);

    void insert(Vehicle& other);
    bool empty() const;
    const Vehicle* find(const Registration& regnum) const;
   
    size_t getcapacity() const;
    size_t getsize() const;
};