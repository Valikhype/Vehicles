
#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include"Registration.h"
#include"Vehicle.h"
#include"VehicleList.h"

#include <iostream>
#include <cstring>    



int main()
{
    Registration a("\0");
    size_t  vehicleNumber;
    std::cin >> vehicleNumber;
    std::cin.ignore();
    VehicleList List(vehicleNumber);

    for (size_t i = 0; i < vehicleNumber; ++i) {

        char str[9];
        std::cin.get(str, 9);
        std::cin.ignore();
        if (a.IsValid(str) && List.IsValidInStr(str)) {
            List.vehicles[i] = new Vehicle(str);
            List.size++;
        }
        else {
            std::cout << "probvai pak" << std::endl;
           i--;
        }
    }
   
   std::cout<<"size`a: " << (List.getsize()) << std::endl;
    char str[9];
    std::cin.get(str, 9);
    if (a.IsValid(str)) {
        for (size_t i = 0; i < vehicleNumber; i++) {
            if (List.vehicles[i]->regnum.areEqual(str)) { std::cout << "vutre e" << std::endl; return 0; };
        }
        std::cout << "mai go nyama ve brat" << std::endl;
    }



}

