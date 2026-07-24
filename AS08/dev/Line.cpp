/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Line.cpp
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/23  Ready for submission
-----------------------------------------------------------
I used ChatGPT for final debugging after compiling and understanding the related concepts.
I followed the instructions step by step and have completed all header files 
and all function implementations on my own.
-----------------------------------------------------------*/
#include "Line.h"
#include <cstring>

namespace seneca {

   Line::Line() {
   }

   Line::Line(const char* label, int length)
      : LblShape(label),
        m_length(length) {
        int labelLength = strlen(label);
        if (m_length < labelLength) {
            m_length = labelLength;
        }
   }

   void Line::getSpecs(std::istream& is) {
      
      LblShape::getSpecs(is);
      is >> m_length;
      is.ignore(1000, '\n');

   }

   void Line::draw(std::ostream& os) const {
        if(m_length > 0 && label()!= nullptr){
            os << label() << std::endl;
            for (int i = 0; i < m_length; i++){
                os << '=';
            }
        }
   }

}