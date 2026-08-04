/* Final Project Milestone 4:
Filename: Food.h
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
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"

namespace seneca {

   class Food : public Billable {
      bool m_ordered{};
      bool m_child{};
      char* m_customize{};

   public:
      Food();
      Food(const Food& F);
      Food& operator=(const Food& F);
      ~Food();

      std::ostream& print(std::ostream& ostr = std::cout) const;
      bool order();
      bool ordered() const;
      std::ifstream& read(std::ifstream& file);
      double price() const;
   };

}

#endif