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
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name
      char* m_name{};
      // unsigned integer or size_t student number
      unsigned int m_number{};
   public:
      // Constructor
      Transcript(const char* name, unsigned int number);
      // Rule of Three
      Transcript(const Transcript& t);
      Transcript& operator=(const Transcript& t);

      // Destructor
      ~Transcript();

      std::ostream& display(std::ostream& ostr = std::cout)const;

   };
}
#endif // !SENECA_TRANSCRIPT_H


