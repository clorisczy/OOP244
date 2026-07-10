/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
Assignment 6
Module: Classes and resources, IO operators
Filename: Numbers.h
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/9  Ready for submission
-----------------------------------------------------------
I used ChatGPT for final debugging after compiling and understanding the related concepts.
I have done all the codings by myself to complete my work for function implenmentation. 
-----------------------------------------------------------
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
#include <fstream>
namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      int numberCount()const;
   public:
      Numbers();
      Numbers(const char* filename);
      ~Numbers();
      Numbers(const Numbers& n);
      Numbers& operator=(const Numbers& n);
      double average()const;
      double max()const;
      double min()const;
      bool load();
      void save();
      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& ostr) const;
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}

#endif // !SENECA_NUMBERS_H_

