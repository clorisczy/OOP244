/* Final Project Milestone 4:
Filename: Menu.h
Version 4.0
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
#include "constants.h"

namespace seneca {

   class Menu;

   class MenuItem {
      friend class Menu;

      char* m_content{};
      unsigned m_indent{};
      unsigned m_indentSize{};
      int m_rowNumber{-1};

      MenuItem(const char* content, unsigned indent = 0,
               unsigned indentSize = 3, int rowNumber = -1);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;

      ~MenuItem();

      operator bool() const;

      std::ostream& display(std::ostream& ostr = std::cout) const;
   };

   class Menu {
      unsigned m_indent{};
      unsigned m_indentSize{};
      size_t m_numItems{};

      MenuItem m_title;
      MenuItem m_exit;
      MenuItem m_prompt;
      MenuItem* m_items[MaximumNumberOfMenuItems]{};

   public:
      Menu(const char* title, const char* exit = "Exit",
           unsigned indent = 0, unsigned indentSize = 3);
      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;
      ~Menu();
      Menu& operator<<(const char* content);
      size_t select() const;
   };
    size_t operator<<(std::ostream& ostr, const Menu& m);

   
}

#endif
