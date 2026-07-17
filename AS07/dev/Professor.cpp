/*-----------------------------------------------------------
Assignment 7
Module: Derived Classes & Custom I/O Operators
Filename: Professor.cpp
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
#include <iostream>
#include "Professor.h"
#include "Utils.h"
#include "Employee.h"

using namespace std;
namespace seneca {
    Professor::Professor(const char* name, const char* subject, int sections, 
        size_t employeeNo, double salary): Employee(name, employeeNo, salary) {
        ut.alocpy(m_subject, subject);
        m_sections = sections;
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    double Professor::devPay() const {
        return salary() * 0.01 * m_sections;
    }

    istream& Professor::read(istream& istr){
        Employee::read(istr);
        istr.ignore();
        char buffer[1025]{};
        istr.getline(buffer, 1025, ',');
        ut.alocpy(m_subject, buffer);
        istr >> m_sections;
        istr.ignore();
        return istr;
    }

    ostream& Professor:: write(ostream& ostr)const{
        char name3print[21]{};
        if(m_subject) ut.strcpy(name3print, m_subject, 20);
        Employee::write(ostr);
        ostr << " ";
        ostr.width(20);
        ostr.fill(' ');
        ostr.setf(ios::left);
        ostr << name3print << " | ";
        ostr.unsetf(ios::left);
        ostr.width(5);
        ostr.setf(ios::right);
        ostr << m_sections << " | ";
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr.width(8);
        ostr << devPay() << " |";
        ostr.unsetf(ios::right);
        return ostr;
    }

    ostream& Professor::title(ostream& ostr)const{
        Employee::title(ostr);
        // debug by ChatGPT (the space width issue)
        ostr << " ";
        ostr.width(20);
        ostr.fill(' ');
        ostr.setf(ios::left);
        ostr << "Teaching Subject";
        ostr.unsetf(ios::left);
        ostr << " | Sec # | $Dev Pay |";
        return ostr; 
    }

    ostream& operator<<(ostream& ostr, const Professor& P ){
        return P.write( ostr );
    }

    istream& operator>>(istream& istr, Professor& P ){
        return P.read( istr );
    }


}
