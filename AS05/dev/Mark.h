/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.h
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Citation and Sources
-----------------------------------------------------------
Assignment 5
Module: Helper functions and operators, IO operators and output formatting
Filename: Mark.h
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/3  Ready for submission
-----------------------------------------------------------
I use ChatGPT for final debugging after compiling, 
understanding the related concepts,
and writting std::istream& operator>>(std::istream& is, Mark& M).
I have done all other codings by myself to complete my work for function. 
-----------------------------------------------------------
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_MARK_H
#define SENECA_MARK_H
#include <iostream>
#include <fstream>
const char GPA = 'G';
const char MARK = 'M';
const char GRADE = 'R';
namespace seneca {
   class Mark {
      // Temporary c-string for grade display
      char m_grade[3]{};
      // Exact mark value (double) to maintain precision; rounded when displayed
      double m_value;
      // Display type: 'G' (GPA), 'M' (MARK), or 'R' (GRADE)
      char m_type;
      // Checks if the Mark object is valid
      bool isValid() const;
   public:
      /// <summary>
      /// Constructs a Mark object with a given integer value (out of 100) and display type (default is MARK).
      /// </summary>
      /// <param name="value">Integer mark value (0-100)</param>
      /// <param name="type">'G', 'M', or 'R' to specify GPA, MARK, or GRADE (default is MARK)</param>
      Mark(int value = 0, char type = 'M');

      /// <summary>
      /// Constructs a Mark object with an exact value (used for internal calculations).
      /// </summary>
      /// <param name="value">Exact mark value as a double</param>
      Mark(double value);

      /// <summary>
      /// Adds the mark of the right operand to the left operand. The type of the left operand remains unchanged.
      /// </summary>
      /// <param name="other">The right operand Mark object</param>
      /// <returns>A reference to the updated left operand Mark</returns>
      Mark& operator+= (const Mark& other);

      /// <summary>
      /// Subtracts the mark of the right operand from the left operand. The type of the left operand remains unchanged.
      /// </summary>
      /// <param name="other">The right operand Mark object</param>
      /// <returns>A reference to the updated left operand Mark</returns>
      Mark& operator-= (const Mark& other);

      /// <summary>
      /// Returns a new Mark object representing the sum of the left and right operands. The type is that of the left operand.
      /// </summary>
      /// <param name="other">The right operand Mark object</param>
      /// <returns>A new Mark object with the sum and the left operand's type</returns>

      Mark operator+ (const Mark& other) const;

      /// <summary>
      /// Returns a new Mark object representing the difference between the left and right operands. The type is that of the left operand.
      /// </summary>
      /// <param name="other">The right operand Mark object</param>
      /// <returns>A new Mark object with the difference and the left operand's type</returns>
      Mark operator- (const Mark& other) const;


      /// <summary>
      /// Divides the mark of the left operand by the given integer. The type of the left operand remains unchanged.
      /// </summary>
      /// <param name="other">The divisor (integer)</param>
      /// <returns>A reference to the updated left operand Mark</returns>
      Mark& operator/= (int other);

      /// <summary>
      /// Returns a new Mark object representing the mark of the left operand divided by the given integer. The type is that of the left operand.
      /// </summary>
      /// <param name="other">The divisor (integer)</param>
      /// <returns>A new Mark object with the divided value and the left operand's type</returns>
      Mark operator/ (int other) const;

      /// <summary>
      /// Sets the mark value of the left operand to the given integer value.
      /// </summary>
      /// <param name="value">Integer mark value</param>
      /// <returns>A reference to the updated left operand Mark</returns>
      Mark& operator= (int value);

      /// <summary>
      /// Sets the display type to 'G' (GPA), 'M' (MARK), or 'R' (GRADE). If an invalid type is provided, defaults to 'M' (MARK).
      /// </summary>
      /// <param name="type">'G', 'M', or 'R'</param>
      /// <returns>A reference to the updated left operand Mark</returns>
      Mark& operator= (char type);

      /// <summary>
      /// Returns the exact mark value stored in m_value (raw value), without any rounding or validation.
      /// </summary>
      /// <returns>The exact double value of the mark</returns>
      double raw() const;

      /// <summary>
      /// Returns the mark value as an integer if valid; otherwise, returns -1.
      /// </summary>
      operator int() const;

      /// <summary>
      /// Returns the GPA value as a double if valid; otherwise, returns -1.
      /// </summary>
      operator double() const;

      /// <summary>
      /// Returns the grade as a C-string if valid; otherwise, returns "X".
      /// </summary>
      operator const char* () const;

      /// <summary>
      /// Checks whether the Mark object is valid.
      /// </summary>
      operator bool() const;

      // display and friends done by students go here 
      std::ostream& display(std::ostream& os = std::cout) const;
      friend double operator/(double value, const Mark& M);
      friend int operator/(int value, const Mark& M);
     
   };
   // student helper function prototypes go here
   std::ostream& display(const Mark& M, char type, std::ostream& os = std::cout);
   // ostream Insertion Helper Operator Overload
   std::ostream& operator<<(std::ostream& os, const Mark& M);
   // istream Extraction Helper Operator Overload
   std::istream& operator>>(std::istream& is, Mark& M);
   // ifstream Extraction Helper Operator Overload
   std::ifstream& operator>>(std::ifstream& file, Mark& M);
   // Helper operator+ Overload for double and int Values
   double operator+(double value, const Mark& M);
   int operator+(int value, const Mark& M);
   // Helper operator- Overload for double and int Values
   double operator-(double value, const Mark& M);
   int operator-(int value, const Mark& M);

}

#endif // !SENECA_MARK_H
