/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Shape.cpp
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
#include "Shape.h"

namespace seneca {

   Shape::~Shape() {
   }

   std::ostream& operator<<(std::ostream& os, const Shape& s) {
      s.draw(os);
      return os;
   }

   std::istream& operator>>(std::istream& is, Shape& s) {
      s.getSpecs(is);
      return is;
   }

}