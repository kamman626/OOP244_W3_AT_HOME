//
// Created by Xiaochen Wang on 2017-06-03.
//

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sict {
    CRA_Account::CRA_Account() {
        m_sin = 0;
        *m_familyName = '\0';
        *m_givenName = '\0';
        *m_balance = '\0';
        *m_year = '\0';
        m_years = 0;
    }

    void CRA_Account::set(const char *familyName, const char *givenName, int sin) {
        strcpy(m_familyName, familyName);
        strcpy(m_givenName, givenName);
        m_sin = sin;
        if (!isValid()) {
            *m_givenName = '\0';
            *m_familyName = '\0';
            m_sin = 0;
            m_years = 0;
            *m_year = '\0';
            *m_balance = '\0';
        }
        /* alternat solution
         for (int =0; i != '\0'; i++){
            m_givenName[i] = 0;
         }
          */
    }

    void CRA_Account::set(int year, double balance) {
        if(isValid()){
            *m_year = year;
            *m_balance = balance;
        }
    }

    bool CRA_Account::isValid() const {
        bool sinTF;

        if (m_sin >= MAX_SIN || m_sin <= MIN_SIN) {
            sinTF = false;
        } else {
            sinTF = true;
        }
        return sinTF;
    }

    void CRA_Account::display() const {
        if (isValid()) {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
            for(int i = 0; i>MAX_YRS; i++){
                cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
            }

        } else {
            cout << "Account object is empty!" << endl;
        }
    }
}
