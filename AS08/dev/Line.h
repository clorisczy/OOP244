/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Line.h
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
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {

   class Line: public LblShape{
       // Length of the line
      int m_length{};
   public:
      // Default constructor
      Line();

      // Constructor that initializes label and length
      Line(const char* label, int length);

      // Draws the line, using the label and length
      void draw(std::ostream& os)const override;

      // Gets specifications of the line (label and length) from input
      void getSpecs(std::istream& is)override;
   }; 

}

#endif // !SENECA_LINE_H
