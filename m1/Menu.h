/* Final Project Milestone 1:
Filename: Menu.h
Version 1.0
Author: Zeyi Cai, StNo: 124719253, Email: zcai25@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/8/2  Personal Work
2026/8/2  Revision 
-----------------------------------------------------------
I have followed the instruction step by step and have done all the work myself
for the first version.
However, I used ChatGPT to clarify some requirements and revised my code before 
compiling. Finally, I debugged with the help of ChatGPT.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {

   class MenuItem {
      char* m_content{};
      unsigned m_indent{};
      unsigned m_indentSize{};
      int m_rowNumber{-1};
    

   public:
    // Rule of 3
      MenuItem(const char* content, unsigned indent = 0,
               unsigned indentSize = 3,int rowNumber = -1);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;
      ~MenuItem();
    // Bool Type  Conversion Overload
      operator bool() const;
      std::ostream& display(std::ostream& ostr = std::cout) const; 
   };

}

#endif
