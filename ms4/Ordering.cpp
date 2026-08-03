/* Final Project Milestone 4:
Filename: Ordering.cpp
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
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

namespace seneca {

    void Ordering::printBillTitle(std::ostream& ostr) const {
      ostr << "Bill # ";

      ostr.fill('0');
      ostr.width(3);
      ostr << m_billNo;

      ostr.fill(' '); // recover the filling 
      ostr << " ============================="
           << std::endl;
   }
   void Ordering::printTotals(std::ostream& ostr, double total) const {
      double tax = total * Tax;
      double totalAndTax = total + tax;

      ostr.setf(std::ios::fixed);
      ostr.precision(2);

      ostr << "                     Total:";
      ostr.width(13); // count by AI
      ostr << total << std::endl;

      ostr << "                     Tax:";
      ostr.width(15); // count by AI
      ostr << tax << std::endl;

      ostr << "                     Total+Tax:";
      ostr.width(9); // count by AI
      ostr << totalAndTax << std::endl;

      ostr << "========================================" << std::endl;
   }

   size_t Ordering::countRecords(const char* f) const {
      size_t count = 0; // set a newline counter to zero
      char ch{};
      std::ifstream file(f); // open an ifstream using the file argument value

      while (file) { // while the file is not in a failure state
         file.get(ch); // read one character
        // if the file is not in failure state and character is a newline
         if (file && ch == '\n') {
            count++;
         }
      }

      return count;
   }

   Ordering::Ordering(const char* df, const char* ff) {
    // Count Records:
      size_t drinkRecords = countRecords(df);
      size_t foodRecords = countRecords(ff);
    // Open Files for Reading:
      std::ifstream drinks(df);
      std::ifstream foods(ff);
    // Reading Data:
      if (drinks && foods && drinkRecords > 0 &&
          foodRecords > 0) {
        // Dynamic Array Allocation:
         m_drinks = new Drink[drinkRecords];
         m_foods = new Food[foodRecords];

        size_t drinkReads = 0;
        size_t foodReads = 0;

        // for loop and call the read method on each element
        for (size_t i = 0; 
            i < drinkRecords && m_drinks[i].read(drinks); i++) {
            drinkReads++;
        }

        for (size_t i = 0;
            i < foodRecords && m_foods[i].read(foods); i++) {
            foodReads++;
        }

        if (drinkReads == drinkRecords && foodReads == foodRecords) {
            m_noOfDrinks = drinkReads;
            m_noOfFoods = foodReads;
        }
        else {
            // Cleanup
            delete[] m_drinks;
            delete[] m_foods;

            m_drinks = nullptr;
            m_foods = nullptr;

            m_noOfDrinks = 0;
            m_noOfFoods = 0;
         }
      }
   }

   Ordering::~Ordering() {
      delete[] m_foods;
      m_foods = nullptr;

      delete[] m_drinks;
      m_drinks = nullptr;

      for (size_t i = 0; i < m_noOfBillItems; i++) {
         delete m_billItems[i];
         m_billItems[i] = nullptr;
      }
   }

   Ordering::operator bool() const {
      return m_foods != nullptr && m_drinks != nullptr;
   }

   size_t Ordering::noOfBillItems() const {
      return m_noOfBillItems;
   }

   bool Ordering::hasUnsavedBill() const {
      return m_noOfBillItems > 0;
   }

   void Ordering::listFoods() const {
      std::cout << "List Of Avaiable Meals" << std::endl;
      std::cout << "========================================"
                << std::endl;
    // Loops through the foods dynamic array and print
      for (size_t i = 0; i < m_noOfFoods; i++) {
         m_foods[i].print() << std::endl;
      }
      // Prints the following footer:
      std::cout << "========================================" << std::endl;
   }

   void Ordering::listDrinks() const {
      std::cout << "List Of Avaiable Drinks" << std::endl;
      std::cout << "========================================"
                << std::endl;
    // Loops through the drinks dynamic array and print
      for (size_t i = 0; i < m_noOfDrinks; i++) {
         m_drinks[i].print() << std::endl;
      }
      // Prints the following footer:
      std::cout << "========================================" << std::endl;
   }

   void Ordering::orderFood() {
    Menu foodMenu("Food Menu", "Back to Order", 2, 3);

      for (size_t i = 0; i < m_noOfFoods; i++) {
         foodMenu << m_foods[i];
      }
      // get selection
      size_t selection = foodMenu.select();

      if (selection != 0) {
         size_t index = selection - 1;
        // Creates a dynamic copy of the selected food item 
         m_billItems[m_noOfBillItems] = new Food(m_foods[index]);

         if (m_billItems[m_noOfBillItems]->order()) {
            m_noOfBillItems++;
         }
         else {
            delete m_billItems[m_noOfBillItems];
            m_billItems[m_noOfBillItems] = nullptr;
         }
      }
   }

   void Ordering::orderDrink() {
  
      Menu drinkMenu("Drink Menu", "Back to Order", 2, 3);

      for (size_t i = 0; i < m_noOfDrinks; i++) {
         drinkMenu << m_drinks[i];
      }

      size_t selection = drinkMenu.select();

      if (selection != 0) {
         size_t index = selection - 1;
        // // Creates a dynamic copy of the selected drink item 
         m_billItems[m_noOfBillItems] = new Drink(m_drinks[index]);

         if (m_billItems[m_noOfBillItems]->order()) {
            m_noOfBillItems++;
         }
         else {
            delete m_billItems[m_noOfBillItems];
            m_billItems[m_noOfBillItems] = nullptr;
         }
      }
   }


   void Ordering::printBill(std::ostream& ostr) const {
      double total = 0.0;

      printBillTitle(ostr);

      for (size_t i = 0; i < m_noOfBillItems; i++) {
        // Prints each item in a separate line using its print method.
         m_billItems[i]->print(ostr) << std::endl;
         // Adds the price of each item to the total.
         total += *m_billItems[i]; // operator+=(total, *m_billItems[i]);
      }

      printTotals(ostr, total);
   }

   void Ordering::resetBill() {
      char fileName[30]{};

      ut.makeBillFileName(fileName, m_billNo);

      std::ofstream billFile(fileName);

      if (billFile) {
         printBill(billFile);
      }

      std::cout << "Saved bill number "<< m_billNo
                << std::endl;

      std::cout << "Starting bill number " << m_billNo + 1
                << std::endl;

      for (size_t i = 0; i < m_noOfBillItems; i++) {
         delete m_billItems[i];
         m_billItems[i] = nullptr;
      }

      m_noOfBillItems = 0;
      m_billNo++;
   }

}