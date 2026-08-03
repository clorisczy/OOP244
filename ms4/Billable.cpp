/* Final Project Milestone 4:
Filename: Billable.cpp
Version 4.0
Author: Zeyi Cai, StNo: 124719253, Email: zcai25@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/8/3  Personal Work
2026/8/3  Revision 
-----------------------------------------------------------
I have followed the instruction step by step and have done all the work myself
for the first version as a practice.
However, I used ChatGPT to clarify some requirements and revised my code before 
compiling. Finally, I debugged with the help of ChatGPT.
-----------------------------------------------------------*/
#include "Billable.h"
#include "Utils.h"

namespace seneca {

    Billable::Billable() {
        m_name = nullptr;
        m_price = 0.0;
    }

    Billable::Billable(const Billable& B) {
        m_price = 0.0;
        m_name = nullptr;
        *this = B;
    }

    Billable& Billable::operator=(const Billable& B) {
        if (this != &B) {
            ut.alocpy(m_name, B.m_name);
            m_price = B.m_price;
        }

        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
        m_name = nullptr;
    }

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char*() const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

}
