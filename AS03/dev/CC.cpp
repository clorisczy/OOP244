#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   void CC::deallocate() {
      delete[] a_name;
      a_name = nullptr;
   }

   void CC::aloCopy(const char* name){
      deallocate();
      a_name = new char[strlen(name) + 1];
      strcpy(a_name, name);
   }
   void CC::set(){
      a_name = nullptr;
      a_no = 0;
      a_cvv = 0;
      a_expMon = 0;
      a_expYear = 0;
   }

   bool CC::isEmpty() const {
      return a_name == nullptr;
   }

   bool CC:: validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const{
      return name != nullptr &&
          strlen(name) > 2 &&
          cardNo >= 4000000000000000ull &&
          cardNo <= 4099999999999999ull &&
          cvv >= 100 &&
          cvv <= 999 &&
          expMon >= 1 &&
          expMon <= 12 &&
          expYear >= 24 &&
          expYear <= 32;
   }

   void CC::set(const char* name,
             unsigned long long no,
             short cvv,
             short expMon,
             short expYear) {
      deallocate();
      set();

      if (validate(name, no, cvv, expMon, expYear)) {
         aloCopy(name);
         a_no = no;
         a_cvv = cvv;
         a_expMon = expMon;
         a_expYear = expYear;
      }
   }

   CC::CC() {
      set();
   }

   CC::CC(const char* name,
       unsigned long long no,
       short cvv,
       short expMon,
       short expYear) {
      set();

      if (validate(name, no, cvv, expMon, expYear)) {
         aloCopy(name);
         a_no = no;
         a_cvv = cvv;
         a_expMon = expMon;
         a_expYear = expYear;
      }
   }

   CC::~CC() {
      deallocate();
   }

   void CC::display() const {
      if (isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      }
      else {
         display(a_name, a_no, a_expYear, a_expMon, a_cvv);
      }
   }
}