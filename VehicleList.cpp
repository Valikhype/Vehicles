#pragma once
#include"Registration.h"
#include"Vehicle.h"
#include"VehicleList.h"

#include <cstring>   


VehicleList::VehicleList(size_t capacity1) :capacity(capacity1) {
    vehicles = new Vehicle * [capacity];
    size = 0;
}
VehicleList::~VehicleList() {
    for (size_t i = 0; i < size; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}
VehicleList::VehicleList(VehicleList& other) :capacity(other.capacity), size(other.size) {
    vehicles = new Vehicle * [capacity];
    for (size_t i = 0; i < size; i++) {
        vehicles[i] = new Vehicle(*other.vehicles[i]);
    }
}
bool VehicleList::IsValidIn(Vehicle& other) {
    for (size_t i = 0; i < size; i++) {
        if (other.regnum == (vehicles[i])->regnum) {
            return 0;
        }
    }
    return 1;
}
bool VehicleList::IsValidInStr(char* str) {
    for (size_t i = 0; i < size; i++) {
        if ((vehicles[i])->regnum.areEqual(str)) {
            return 0;
        }
    }
    return 1;
}
void VehicleList::insert(Vehicle& other) {

    if (size == capacity || IsValidIn(other)) {
        return;//nqkva greshka 
    }
    vehicles[size] = new Vehicle(other);
    size++;
}
const Vehicle& VehicleList::at(size_t index) const {
    if (index < size) {
        return *(vehicles[index]);
    }

}
const Vehicle& VehicleList::operator[](size_t pos) const {
    return *(vehicles[pos]);
}
bool VehicleList::empty() const {
    if (size == 0) return 1;
    return 0;
}
size_t VehicleList::getcapacity() const {
    return capacity;
}
size_t VehicleList::getsize() const {
    return size;
}
const Vehicle* VehicleList::find(const Registration& regnum) const {
    for (size_t i = 0; i < size; i++) {
        if (regnum == (vehicles[i])->regnum) {
            return (vehicles[i]);
        }
    }
    return nullptr;
}
