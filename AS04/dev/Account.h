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
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
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