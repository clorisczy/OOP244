#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstdio>
#include <cstddef>

namespace seneca {

   struct PhoneRec {
      char m_name[16];
      char m_lastName[26];
      long long m_phoneNumber;
   };

   void read(char name[]);
   void print(long long phoneNumber);
   void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);
   bool read(PhoneRec& rec, FILE* fptr);
   void print(PhoneRec* records[], size_t size, const char* filter = nullptr);
   void setPointers(PhoneRec* ptrs[], PhoneRec records[], size_t size);
   void sort(PhoneRec* ptrs[], size_t size, bool sortByLastName);

}

#endif
