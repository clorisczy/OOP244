/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
 

   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }

   Account::operator bool() const {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0 && m_holderName[0] != '\0';
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   Account::operator const char* () const {
      return m_holderName;
   }

   char& Account::operator[](int index) {
      if (index < 0) index = 0;
      return m_holderName[index % NameMaxLen];
   }

   const char Account::operator[](int index) const {
      if (index < 0) index = 0;
      return m_holderName[index % NameMaxLen];
   }

   Account& Account::operator=(int number) {
      if (m_number != -1) {
         if (m_number == 0) {
            if (isValidNumber(number)) {
               m_number = number;
            }
            else {
               m_number = -1;
               m_balance = 0.0;
               m_holderName[0] = '\0';
            }
         }
      }
      return *this;
   }

   Account& Account::operator=(double balance) {
      if (*this) {
         if (balance >= 0.0) {
            m_balance = balance;
         }
         else {
            m_number = -1;
            m_balance = 0.0;
            m_holderName[0] = '\0';
         }
      }
      return *this;
   }

   Account& Account::operator+=(double value) {
      if (*this && value >= 0.0) {
         m_balance += value;
      }
      return *this;
   }

   Account& Account::operator-=(double value) {
      if (*this && value >= 0.0 && m_balance >= value) {
         m_balance -= value;
      }
      return *this;
   }

   Account& Account::operator<<(Account& other) {
      if (*this && other && this != &other) {
         m_balance += other.m_balance;
         other.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& other) {
      if (*this && other && this != &other) {
         other.m_balance += m_balance;
         m_balance = 0.0;
      }
      return *this;
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account& Account::operator++() {
      if (*this) {
         ++m_balance;
      }
      return *this;
   }

   Account Account::operator++(int) {
      Account origin = *this;
      if (*this) {
         m_balance++;
      }
      return origin;
   }

   Account& Account::operator--() {
      if (*this && m_balance >= 1.0) {
         --m_balance;
      }
      return *this;
   }

   Account Account::operator--(int) {
      Account origin = *this;
      if (*this && m_balance >= 1.0) {
         m_balance--;
      }
      return origin;
   }
}