/*-----------------------------------------------------------
Assignment 7
Module: Derived Classes & Custom I/O Operators
Filename: Professor.h
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/16  Ready for submission
-----------------------------------------------------------
I used ChatGPT for final debugging after compiling and understanding the related concepts.
I have done all the codings by myself and only refer to the functions in 
Employee.cpp and Employee.h to complete my work for function implenmentation. 
-----------------------------------------------------------*/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"
namespace seneca {
   class Professor : public Employee {
        char *m_subject{};
        int m_sections{};
        double devPay() const;  
    public:
    Professor() = default;
    Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary);
    ~Professor();
    std::istream& read(std::istream& istr = std::cin);
    std::ostream& write(std::ostream& ostr = std::cout) const;
    std::ostream& title(std::ostream& ostr = std::cout) const;
   };
    std::ostream& operator<<(std::ostream& ostr, const Professor& P );
    std::istream& operator>>(std::istream& istr, Professor& P );
}

#endif // !SENECA_PROFESSOR_H
