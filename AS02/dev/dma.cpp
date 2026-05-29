#include "dma.h"
#include "cstr.h"

namespace seneca {
   
    Samples* CreateSamples(const char* title) {
        Samples* s = new Samples; // Allocates a new Samples object on the heap.

        s->m_title = new char[strlen(title) + 1];
        strcpy(s->m_title, title); // Dynamically copies the title into m_title

        s->m_data = nullptr;
        s->m_size = 0; // Sets m_data to nullptr and m_size to 0.

        return s;
    }

    void add(Samples& S, const int data[], int size) {
        if (S.m_data == nullptr) { // if m_data is nullptr, allocates and copies the incoming values
            S.m_data = new int[size]; // Allocate an array of int with same size of data pointer by m_data

            for (int i = 0; i < size; i++) {
                S.m_data[i] = data[i]; // Copies all the elements of data into elements of dynamic m_data
            }

            S.m_size = size;
        }
        else {
            append(S.m_data, S.m_size, data, size); // If m_data already exists, uses append() to expand it and add the new values.
            S.m_size += size;
        }
    }

    void append(int*& data, int size, const int appendedData[], int dataSize) {
        int* newData = new int[size + dataSize]; // Dynamically creates a new array of size size + dataSize.

        for (int i = 0; i < size; i++) {
            newData[i] = data[i]; // Copies existing values。
        }

        for (int i = 0; i < dataSize; i++) {
            newData[size + i] = appendedData[i]; // Appends new values.
        }

        delete[] data; // Frees the old array
        data = newData; // Updates the deleted data pointer to the newly allocated memory 
    }


    void freemem(Samples*& s) {
        if (s != nullptr) {
            delete[] s->m_title;
            delete[] s->m_data; // Deallocates
            delete s;
            s = nullptr; // Sets the pointer s to nullptr
        }
    }

}