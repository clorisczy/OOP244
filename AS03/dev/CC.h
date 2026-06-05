// Zeyi Cai
// zcai25@myseneca.ca
// 124719253
// oop244 NBB
// 2026.6.3
// I have done all the coding by myself and only copied the code that 
// my professor provided to complete my assignments.

#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* a_name;
      unsigned long long a_no;
      short a_cvv;
      short a_expMon;
      short a_expYear;
      void aloCopy(const char* name);
      void deallocate();
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      bool validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const;
      void prnNumber(unsigned long long no) const;

   public:
      void set();
      bool isEmpty() const;
      void set(const char* name, 
         unsigned long long no, 
         short cvv, 
         short expMon, 
         short expYear);
      void display() const;
      CC();
      CC(const char* name,
         unsigned long long no,
         short cvv,
         short expMon = 12, 
         short expYear = 26);
      ~CC();
   };

}
#endif // !SENECA_CC_H_


