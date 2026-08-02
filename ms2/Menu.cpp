/* Final Project Milestone 2:
Filename: Menu.cpp
Version 2.0
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
#include "Menu.h"
#include "Utils.h"
#include "constants.h"

namespace seneca {

   MenuItem::MenuItem(const char* content, unsigned indent,
                   unsigned indentSize,int rowNumber) {
    // Constructor Validations
   if (content == nullptr || ut.isspace(content) ||
       indent > 4 || indentSize > 4 || 
       // Debugged by ChatGPT
       rowNumber > static_cast<int>(MaximumNumberOfMenuItems)) {
      m_content = nullptr;
      m_indent = 0;
      m_indentSize = 0;
      m_rowNumber = -1;
   }
   else {
      ut.alocpy(m_content, content);
      m_indent = indent;
      m_indentSize = indentSize;
      m_rowNumber = rowNumber;
   }
}

   MenuItem::~MenuItem() {
      delete[] m_content;
      m_content = nullptr;
   }

   MenuItem::operator bool() const {
      return m_content != nullptr;
   }

   std::ostream& MenuItem::display(std::ostream& ostr) const {
      if (m_content == nullptr) {
         ostr << "??????????";
      }
      else {
         for (int i = 0; i < m_indent * m_indentSize; i++) {
            ostr << ' ';
         }

         if (m_rowNumber >= 0) {
            ostr.width(2);
            ostr << m_rowNumber << "- ";
         }
        // not modify m_content
         const char* temp = m_content;
        // Display the content without any leading whitespace.
         while (*temp && ut.isspace(*temp)) {
            temp++;
         }

         ostr << temp;
      }

      return ostr;
   }

   // Menu
   // Constructor with Attributes
   Menu::Menu(const char* title,const char* exit,
           unsigned indent,unsigned indentSize)
   : m_indent(indent),
     m_indentSize(indentSize),
     m_numItems(0),
     m_title(title, indent, indentSize, -1),
     m_exit(exit, indent, indentSize, 0), // The row number of the exit option should be set to zero.
     m_prompt("> ", indent, indentSize, -1) {
   for (int i = 0; i < MaximumNumberOfMenuItems; i++) {
      m_items[i] = nullptr;
   }
}
    // Rule of 3
    // Destructor
    Menu::~Menu() {
        for (int i = 0; i < MaximumNumberOfMenuItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }
    // << Operator Overload for Menu
    Menu& Menu::operator<<(const char* content) {
        if (m_numItems < MaximumNumberOfMenuItems) {
            m_items[m_numItems] = new MenuItem(
                content, m_indent, m_indentSize,
                static_cast<int>(m_numItems + 1));// debugged by AI

            m_numItems++;
        }

        return *this;
    }

    size_t Menu::select() const {
        // Display the Title
        if (m_title) {
            m_title.display() << std::endl;
        }
        // Display Menu Items
        for (int i = 0; i < m_numItems; i++) {
            m_items[i]->display() << std::endl;
        }
        // Display the Exit Option
        m_exit.display() << std::endl;
        // Display the Selection Prompt
        m_prompt.display();
        // Return the User's Selection
        return ut.getInt(0, m_numItems);
    }

    

    

}
