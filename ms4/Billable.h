/* Final Project Milestone 4:
Filename: Billable.h
Version 4.0
Author: Zeyi Cai, StNo: 124719253, Email: zcai25@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/8/3  Personal Work
2026/8/3  Revision 
-----------------------------------------------------------
I have followed the instruction step by step and have done all the work myself
for the first version as a practice.
However, I used ChatGPT to clarify some requirements and revised my code before 
compiling. Finally, I debugged with the help of ChatGPT.
-----------------------------------------------------------*/
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

   class Billable {
      char* m_name{};
      double m_price{};

   protected:
      void price(double value);
      void name(const char* name);

   public:
    // Constructors and Destructor:
      Billable();
      Billable(const Billable& B);
      Billable& operator=(const Billable& B);
      virtual ~Billable();
     // Virtual Methods:
      virtual double price() const;
    // Pure Virtual Methods
      virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
      virtual bool order() = 0;
      virtual bool ordered() const = 0;
      virtual std::ifstream& read(std::ifstream& file) = 0;
    // Conversion Operator 
      operator const char*() const;
   };
   // Operator Overloads:
   double operator+(double money, const Billable& B);
   double& operator+=(double& money, const Billable& B);

}

#endif
