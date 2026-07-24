/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: LblShape.cpp
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
#include "LblShape.h"
#include "Utils.h"

namespace seneca {

   LblShape::LblShape() {
   }

  
   LblShape::LblShape(const char* label) {
      ut.alocpy(m_label, label);
   }

   
   const char* LblShape::label() const {
      return m_label;
   }

  
   void LblShape::getSpecs(std::istream& is) {
      char temp[81]{};
      is.getline(temp, 81, ',');
      ut.alocpy(m_label, temp);
   }

   
   LblShape::~LblShape() {
      delete[] m_label;
   }

}