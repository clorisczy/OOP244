#include "Food.h"
#include "Menu.h"
#include "Utils.h"

#include <iostream>

namespace seneca {

   Food::Food() {
      m_ordered = false;
      m_child = false;
      m_customize = nullptr;
   }

   Food::Food(const Food& F)
      : Billable(F) {

      m_ordered = F.m_ordered;
      m_child = F.m_child;
      m_customize = nullptr;

      ut.alocpy(m_customize, F.m_customize);
   }

   Food& Food::operator=(const Food& F) {
      if (this != &F) {
         Billable::operator=(F);

         m_ordered = F.m_ordered;
         m_child = F.m_child;
         ut.alocpy(m_customize, F.m_customize);
      }

      return *this;
   }

   Food::~Food() {
      delete[] m_customize;
      m_customize = nullptr;
   }

   bool Food::ordered() const {
      return m_ordered;
   }

   double Food::price() const {
      double price = Billable::price();

      if (m_ordered && m_child) {
         price *= 0.5;
      }

      return price;
   }

   bool Food::order() {
      Menu foodMenu("Food Size Selection", "Back", 3, 3);

      foodMenu << "Adult" << "Child";

      size_t selection = foodMenu.select();

      if (selection == 0) {
         m_ordered = false;
         m_child = false;

         delete[] m_customize;
         m_customize = nullptr;
      }
      else {
         m_ordered = true;
         m_child = (selection == 2);

         char instructions[1000]{};

         std::cout << "Special instructions" << std::endl;
         std::cout << "> ";

         std::cin.getline(instructions, 1000);

         if (instructions[0] == '\0') {
            delete[] m_customize;
            m_customize = nullptr;
         }
         else {
            ut.alocpy(m_customize, instructions);
         }
      }

      return m_ordered;
   }

   std::ifstream& Food::read(std::ifstream& file) {
      char foodName[50]{};
      double foodPrice{};

      if (file.getline(foodName, 50, ',') &&
          file >> foodPrice) {

         file.ignore(1000, '\n');
        // the details are set to corresponding values
         name(foodName);
         Billable::price(foodPrice);
        
         m_ordered = false;
         m_child = false;

         delete[] m_customize;
         m_customize = nullptr;
      }

      return file;
   }

   std::ostream& Food::print(std::ostream& ostr) const {
      char foodName[26]{};
      // operator const char*() const
      const char* name = *this;

      int i = 0;
      while (name && name[i] && i < 25) {
         foodName[i] = name[i];
         i++;
      }
      foodName[i] = '\0';
      ostr.unsetf(std::ios::right);
      ostr.setf(std::ios::left);
      ostr.fill('.');
      ostr.width(28);
      ostr << foodName;
      // portion type
      if (!ordered()) {
         ostr << ".....";
      }
      else if (ordered() && m_child) {
         ostr << "Child";
      }
      else {
         ostr << "Adult";
      }

      ostr.unsetf(std::ios::left);
      // price
      ostr.setf(std::ios::right);
      ostr.fill(' ');
      ostr.width(7);
      ostr.setf(std::ios::fixed);
      ostr.precision(2);
      ostr << price();
      // customizations
      if (&ostr == &std::cout && m_customize != nullptr) {
         ostr << " >> ";

         int j = 0;

         while (m_customize[j] && j < 30) {
            ostr << m_customize[j];
            j++;
         }
      }

      return ostr;
   }

}