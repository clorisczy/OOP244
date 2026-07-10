/*-----------------------------------------------------------
Assignment 6
Module: Classes and resources, IO operators
Filename: Numbers.cpp
-----------------------------------------------------------
Author: Zeyi Cai
Student number: 124719253
Email: zcai25@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/7/9  Ready for submission
-----------------------------------------------------------
I used ChatGPT for final debugging after compiling and understanding the related concepts.
I have done all the codings by myself to complete my work for function implenmentation. 
-----------------------------------------------------------*/
#include <iostream>
#include "Numbers.h"
using namespace std;
namespace seneca {

    int Numbers::numberCount()const{
        int count = 0;
        char ch;
        ifstream fin(m_filename);
        if (fin.is_open()){
            while(fin.get(ch)){ //reads every character including whitespace like '\n'
                if(ch == '\n')
                    count++;
            }
            fin.close();
        }
        return count;
    }
    bool Numbers::load(){
        bool status = false;
        if (m_numCount > 0){
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            if (file.is_open()){
                int i = 0;
                while(i < m_numCount && file >> m_numbers[i]){
                    i++;
                }
                if (i != m_numCount){
                    delete [] m_numbers;
                    m_numbers = nullptr;
                    m_numCount = 0;
                }
                else{
                    status = true;
                }
            }             
        }
        return status;  
    }
    void Numbers::save(){
        if (m_isOriginal && !isEmpty()){
            ofstream fout(m_filename);
            for(int i = 0; i < m_numCount; i++){
                fout << m_numbers[i] << endl;
            }
        }
    }

    Numbers& Numbers::operator+=(double value){
        if(!isEmpty()){
            double* temp;
            temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++){
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value;
            m_numCount++;
            delete [] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }
    std::ostream& Numbers::display(std::ostream& ostr) const{
        if(isEmpty()){
            ostr<< "Empty list";
        }
        else{
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "=========================" << endl;
            if (m_isOriginal){
                ostr << m_filename << endl;
            }
            else{
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];

                if (i < m_numCount - 1) {
                    ostr << ", ";
                }
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }

        return ostr;
    }
    Numbers::~Numbers(){
        save();
        delete [] m_filename;
        delete [] m_numbers;
    }
    Numbers::Numbers(const Numbers& n){
        setEmpty();
        m_isOriginal = false;
        if (!n.isEmpty()){
            m_numCount = n.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++){
                m_numbers[i] = n.m_numbers[i];
            }
        }    
    }
    Numbers& Numbers::operator=(const Numbers& n){
        if (this != &n){
            delete [] m_numbers;
            if (!n.isEmpty()){
                m_numCount = n.m_numCount;
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; i++){
                    m_numbers[i] = n.m_numbers[i];
                }
            }
        }
        return *this;
    }
    ostream& operator<<(ostream& os, const Numbers& N){
        N.display(os);
        return os;
    }
    istream& operator>>(istream& istr, Numbers& N){
        double value;
        istr >> value;
        if (istr){
            N += value;
        }
        return istr;
    }


}



  