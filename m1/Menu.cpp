/* Final Project Milestone 1:
Filename: Menu.cpp
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

}