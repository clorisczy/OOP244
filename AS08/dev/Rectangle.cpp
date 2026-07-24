/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Rectangle.cpp
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
#include "Rectangle.h"
#include <cstring>

namespace seneca {

   Rectangle::Rectangle() {
   }

   Rectangle::Rectangle(const char* label, int width, int height)
   :LblShape(label),
   m_width(width),
   m_height(height){
        if (m_height < 3)
            m_height = 3;
        int labelLength = strlen(label);
        if (m_width < labelLength + 2){
            m_width = labelLength + 2;
        }
   }
   

   void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1000, ',');
        is >> m_height;
        is.ignore(1000, '\n');
   }



   void Rectangle::draw(std::ostream& os) const {
        if(m_width > 0 && m_height > 0 && label()!=nullptr){
            os << '+';
            for (int i = 0; i < m_width - 2; i++){
                os << '-';
            }
            os << '+' << std::endl;
            os << '|';
            os.setf(std::ios::left);
            os.width(m_width - 2);
            os << label();
            os << '|' << std::endl;

            for (int i = 0; i < m_height - 3; i++){
                os << '|';
                for (int j = 0; j < m_width - 2; j++){
                    os << ' ';
                }
                os << '|' << std::endl;
            }
            os << '+';

            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }

            os << '+';

        }
   }

}
