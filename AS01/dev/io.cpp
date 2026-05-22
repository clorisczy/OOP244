#include <iostream>
#include <cstdio>
#include "io.h"
#include "cstr.h"

using namespace std;

namespace seneca {

   void read(char name[]) {
      cout << "Name\n> ";
      cin >> name;
   }

   void print(long long phoneNumber) {
      long long area = phoneNumber / 10000000;
      long long prefix = (phoneNumber / 10000) % 1000;
      long long line = phoneNumber % 10000;

      cout << "(";
      if (area < 100) cout << "0";
      if (area < 10) cout << "0";
      cout << area << ") ";

      if (prefix < 100) cout << "0";
      if (prefix < 10) cout << "0";
      cout << prefix << "-";

      if (line < 1000) cout << "0";
      if (line < 100) cout << "0";
      if (line < 10) cout << "0";
      cout << line;
   }

   void print(const PhoneRec& rec, size_t& row, const char* filter) {
      if (filter == nullptr ||
          strstr(rec.m_name, filter) != nullptr ||
          strstr(rec.m_lastName, filter) != nullptr) {

         cout << row << ": " << rec.m_name << " " << rec.m_lastName << " ";
         print(rec.m_phoneNumber);
         cout << endl;
         row++;
      }
   }

   bool read(PhoneRec& rec, FILE* fptr) {
      return fscanf(fptr, "%s %s %lld", rec.m_name, rec.m_lastName, &rec.m_phoneNumber) == 3;
   }

   void print(PhoneRec* records[], size_t size, const char* filter) {
      size_t row = 1;
      for (size_t i = 0; i < size; i++) {
         print(*records[i], row, filter);
      }
   }

   void setPointers(PhoneRec* ptrs[], PhoneRec records[], size_t size) {
      for (size_t i = 0; i < size; i++) {
         ptrs[i] = &records[i];
      }
   }

   void sort(PhoneRec* ptrs[], size_t size, bool sortByLastName) {
      for (size_t i = 0; i < size - 1; i++) {
         for (size_t j = i + 1; j < size; j++) {
            int result;

            if (sortByLastName) {
               result = strcmp(ptrs[i]->m_lastName, ptrs[j]->m_lastName);
            } else {
               result = strcmp(ptrs[i]->m_name, ptrs[j]->m_name);
            }

            if (result > 0) {
               PhoneRec* temp = ptrs[i];
               ptrs[i] = ptrs[j];
               ptrs[j] = temp;
            }
         }
      }
   }

}
