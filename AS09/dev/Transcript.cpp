/*-----------------------------------------------------------
Assignment 9
Module: Derived Classes and Resources
Filename: Transcript.h
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/30  Ready for submission
-----------------------------------------------------------
I used ChatGPT for final debugging after compiling and understanding the related concepts.
I followed the instructions step by step and have completed all header files 
and all function implementations on my own.
-----------------------------------------------------------*/
#include "Transcript.h"
#include "Utils.h"
#include <iostream>
using namespace std;

namespace seneca {

Transcript::Transcript(const char* name, unsigned int number){
    ut.alocpy(m_name,name);
    m_number = number;
}
    
Transcript::Transcript(const Transcript& t)
:Marks(t){
    ut.alocpy(m_name,t.m_name);
    m_number = t.m_number;
}

Transcript& Transcript::operator=(const Transcript& t){
    if(this != &t){
        Marks::operator=(t);
        ut.alocpy(m_name, t.m_name);
        m_number = t.m_number;
    }
    return *this;
}

      
Transcript::~Transcript(){
    delete [] m_name;
 }

std::ostream& Transcript::display(std::ostream& ostr)const {
    if (m_name) {
         ostr << m_name;
      }

      ostr << " (" << m_number << ')' << std::endl;
      ostr << "--------------------------------------------------------------------------"
           << std::endl;

      return Marks::display(ostr);
   }

}
