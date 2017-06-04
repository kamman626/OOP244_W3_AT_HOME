//
// Created by Xiaochen Wang on 2017-06-03.
//

#include <iostream>
#include <stdio.h>
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
            m_year[m_years] = year;
            m_balance[m_years] = balance;
            m_years++;
        }
    }

    bool CRA_Account::isValid() const {
        bool sinTF;
        int tempSin = m_sin;
        int alternateNum[4];
        int sumDigits1[4];
        int sumDigits2[4];
        int lessTenTotal = 0;
        int greaterThenTotal = 0;
        int otherTotal = 0;
        int Total = 0;

        if (m_sin >= MAX_SIN || m_sin <= MIN_SIN) {
            sinTF = false;
        } else {
            int sinArray[9];
            for (int i = 0; i <= 9; i++) {
                sinArray[i] = tempSin % 10;
                tempSin /= 10;
            }

            alternateNum[0] = sinArray[7] * 2; // Convert single array into  one new array.
            alternateNum[1] = sinArray[5] * 2;
            alternateNum[2] = sinArray[3] * 2;
            alternateNum[3] = sinArray[1] * 2;
            alternateNum[4] = '\0';

            for (int j = 0; j < 4; j++) {
                if (alternateNum[j] > 10) {
                    sumDigits1[j] = alternateNum[j] % 10 + 1; //calculate less the 10 even number.
                    greaterThenTotal += sumDigits1[j];
                } else if (alternateNum[j] == 10) {
                    sumDigits2[j] = 1;
                    lessTenTotal += sumDigits2[j];
                } else if (alternateNum[j] < 10) {
                    sumDigits2[j] = alternateNum[j];
                    lessTenTotal += sumDigits2[j];
                } else {
                    sumDigits2[j] = '\0';
                }
            }

            otherTotal = sinArray[8] + sinArray[6] + sinArray[4] + sinArray[2];
            Total = (greaterThenTotal + lessTenTotal) + otherTotal;

            int checkNum = (Total / 10 + 1) * 10 - Total;
            if (checkNum == sinArray[0]) {
                sinTF = true;
            } else {
                sinTF = false;
            }
        }
        return sinTF;
    }

    void CRA_Account::display() const {
        if (isValid()) {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
            if(*m_year != '\0' && *m_balance != '\0'){
                for(int i = 0; i < m_years; i++){
                    if(m_balance[i] > 2){
                        printf("Year (%d) balance owing: %.2lf\n",m_year[i], m_balance[i]) ;
                    }else if(m_balance[i] < -2){
                        printf("Year (%d) refund due: %.2lf\n", m_year[i], -(m_balance[i]));
                    }else{
                        cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
                    }
                }
            } else{
                cout << "Account object is empty!" << endl;
            }
        } else {
            cout << "Account object is empty!" << endl;
        }
    }
}
