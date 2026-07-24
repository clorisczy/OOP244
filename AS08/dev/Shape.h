/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: Shape.h
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
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {

   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw(std::ostream& os)const = 0;

      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(std::istream& is) = 0;

      // Virtual destructor to ensure proper cleanup of derived class objects
      virtual ~Shape();
   };

   // Operator overload to handle output stream, relies on draw function
   std::ostream& operator<<(std::ostream& os, const Shape& s);

   // Operator overload to handle input stream, relies on getSpecs function
   std::istream& operator>>(std::istream& is, Shape& s);
}
   

#endif // !SENECA_SHAPE_H
