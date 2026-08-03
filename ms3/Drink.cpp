#include "Drink.h"
#include "Menu.h"

#include <iomanip>
#include <string>

namespace seneca {

   std::ostream& Drink::print(std::ostream& ostr) const {
      const char* size = "....."; // If size is unset 

      if (m_size == 'S') {
         size = "SML..";
      }
      else if (m_size == 'M') {
         size = "MID..";
      }
      else if (m_size == 'L') {
         size = "LRG..";
      }
      else if (m_size == 'X') {
         size = "XLR..";
      }

    char name[26]{};
    const char* source = *this;
    int i = 0;
    while (source && source[i] && i < 25) {
        name[i] = source[i];
        i++;
    }
    name[i] = '\0';
    // name: Up to 25 characters in 28 spaces, 
    // left-justified and padded with dots ('.').
    ostr.setf(std::ios::left);
    ostr.fill('.');
    ostr.width(28);
    ostr << name;
    // size
    ostr << size; 
    ostr.unsetf(std::ios::left);
    // price: Right-justified in 7 spaces
    ostr.setf(std::ios::right);
    ostr.fill(' '); 
    ostr.width(7);
     // padded with spaces and displayed with 2 decimal places.
    ostr.setf(std::ios::fixed);
    ostr.precision(2);
    ostr << price();
    return ostr;
   }

   bool Drink::order() {
      Menu menu("Drink Size Selection", "Back", 1, 3);
      menu << "Small"
           << "Medium"
           << "Larg"
           << "Extra Large";

      size_t selection = menu.select();

      if (selection == 1) {
         m_size = 'S';
      }
      else if (selection == 2) {
         m_size = 'M';
      }
      else if (selection == 3) {
         m_size = 'L';
      }
      else if (selection == 4) {
         m_size = 'X';
      }
      else {
         m_size = '\0'; // set as null character
      }

      return ordered();
   }

    bool Drink::ordered() const {
        return m_size == 'S' || m_size == 'M' ||
             m_size == 'L' || m_size == 'X';
   }

    std::ifstream& Drink::read(std::ifstream& file) {
        char drink[50]{};
        double price{};

        if (file.getline(drink, 50, ',') &&
            file >> price) {
            file.ignore(1000, '\n');
            // the details are set to corresponding values
            name(drink);
            Billable::price(price);
            m_size = '\0'; // m_size is set to its default value
        }

        return file;
    }

   double Drink::price() const {
      double billPrice = Billable::price();

      if (m_size == 'S') {
         return billPrice * 0.5;
      }
      else if (m_size == 'M') {
         return billPrice * 0.75;
      }
      else if (m_size == 'X') {
         return billPrice * 1.5;
      }

      return billPrice;
   }

}