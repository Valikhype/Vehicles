#pragma once
#include "Registration.h"
#include "Vehicle.h"
#include <cstring>

Vehicle::Vehicle(const Vehicle& other) : regnum(other.regnum) {
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}
Vehicle::Vehicle(char* str) : regnum(str) {

}

Vehicle::~Vehicle() {
    delete[] description;
}
