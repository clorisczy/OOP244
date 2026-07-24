/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Rectangle.h
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
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      int m_width{};
      // Height of the rectangle
      int m_height{};
   public:
      // Default constructor
      Rectangle();

      // Constructor that initializes label, width, and height
      Rectangle(const char* label, int width, int height);

      // Draws the rectangle using the label, width, and height
      void draw(std::ostream& os)const override;

      // Gets specifications of the rectangle (label, width, height) from input
      void getSpecs(std::istream& is)override;
   };

}

#endif // !SENECA_RECTANGLE_H
