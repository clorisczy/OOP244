/* Final Project Milestone 4:
Filename: Ordering.h
Version 4.0
Author: Zeyi Cai, StNo: 124719253, Email: zcai25@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/8/3  Personal Work
2026/8/3  Revision 
-----------------------------------------------------------
I have followed the instruction step by step and try to do all the functions myself
for the first version as a practice. Then, I asked ChatGPT to give me some hints 
about the coding implementation and help me clarify some requirements 
and revised my code before compiling. Finally, I debugged with the help of ChatGPT.
-----------------------------------------------------------*/
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"

namespace seneca {

   class Ordering {
      // Billable, Food, and Drink Counters
      size_t m_noOfFoods{};
      size_t m_noOfDrinks{};
      size_t m_noOfBillItems{};
      size_t m_billNo{1}; // starting from 1
      // Food and Drink Dynamic Arrays
      Food* m_foods{};
      Drink* m_drinks{};
      // Billable Array of Pointers
      Billable* m_billItems[MaximumNumberOfBillItems]{};
      // Bill Title Print
      void printBillTitle(std::ostream& ostr) const;
      // Print Totals
      void printTotals(std::ostream& ostr, double total) const;
      // calculates the number of records in a file by counting the newline characters
      size_t countRecords(const char* f) const;

   public:
      // constructed using two C-strings representing the drinks and foods data file names
      Ordering(const char* df, const char* ff);

      Ordering(const Ordering&) = delete;
      Ordering& operator=(const Ordering&) = delete;
      // Destructor
      ~Ordering();
      // Boolean Conversion Operator Overload
      operator bool() const;
      // Number of Bill Items
      size_t noOfBillItems() const;
      // Has Unsaved Bill
      bool hasUnsavedBill() const;
      // List Food Method (does not modify the class)
      void listFoods() const;
      // List Drinks Method (does not modify the class)
      void listDrinks() const;
      // Order Food Method
      void orderFood();
      // Order Drink Method
      void orderDrink();
      // Print Bill Method (does not modify the class)
      void printBill(std::ostream& ostr = std::cout) const;
      // Reset Bill
      void resetBill();
   };

}

#endif