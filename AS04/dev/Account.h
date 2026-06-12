/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/* Citation and Sources
-----------------------------------------------------------
Assignment 4
Module: Whatever
Filename: Account.cpp
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/6/12  Ready for submission
-----------------------------------------------------------
With the help of ChatGPT for debugging and understanding the related concepts,
I have done all the coding by myself and copied the code 
that my professor provided to complete my work for function. 
-----------------------------------------------------------
*/
/////////////////////////////////////////////////////////////////
***********************************************************************
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;
      // Member Opeartors
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      // Subscription Member Opeartor
      char& operator[](int index);
      const char operator[](int index) const;
      // Binary Member Operators
      Account& operator=(int number);
      Account& operator=(double balance);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);
      // Unary Member Operators
      bool operator~() const;
      Account& operator++();
      Account operator++(int);
      Account& operator--();
      Account operator--(int);
   };
  

}
#endif // SENECA_ACCOUNT_H_