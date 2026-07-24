/*-----------------------------------------------------------
Assignment 8
Module: Virtual Functions and Abstract Base Classes
Filename: LblShape.h
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
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"

namespace seneca {

   class LblShape : public Shape  {
      // Dynamically allocated label for the shape
      char* m_label = nullptr;
   protected:
      // Returns the label string for derived classes to access
      const char* label() const;
   public:
      // Default constructor
      LblShape();
      
      // Constructor with label initialization
      LblShape(const char* label);

      // Copy constructor and assignment operator are deleted to prevent copying
      LblShape(const LblShape&) = delete;
      LblShape& operator=(const LblShape&) = delete;

      // Reads label specifications from input stream
      void getSpecs(std::istream& is) override;   

      // Destructor to release dynamically allocated memory
      ~LblShape();
   };
}

#endif // !SENECA_LABELEDSHAPE_H
