/*-----------------------------------------------------------
Assignment 10
Module: Function Templates
Filename: dynaCopy.h
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/8/3  Ready for submission
-----------------------------------------------------------
I followed the instructions step by step and have completed the header file
on my own. Note: I used ChatGPT for understanding the related concepts.
-----------------------------------------------------------*/
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

#include <iostream>

namespace seneca {
    // Two-Argument dynaCopy
    template <typename T>
    T* dynaCopy(const T* src, int size) {
        T* newArray = nullptr;

        if (src != nullptr && size > 0) {
            newArray = new T[size];

            for (int i = 0; i < size; i++) {
                newArray[i] = src[i];
            }
        }

        return newArray;
    }

    // Three-Argument dynaCopy
    template <typename T>
    T* dynaCopy(T* & des, const T* src, int size) {
        delete[] des;
        des = nullptr;

        des = dynaCopy(src, size);

        return des;
    }
    // prnArray
    template <typename T>
    void prnArray(const T* array, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << array[i];

            if (i < size - 1) {
                std::cout << ", ";
            }
        }

        std::cout << std::endl;
    }

}

#endif