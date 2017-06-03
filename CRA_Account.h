//
// Created by Xiaochen Wang on 2017-06-03.
//

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999

#define MAX_YRS 4

using namespace std;
namespace sict{
    class CRA_Account{
        char m_familyName[MAX_NAME_LENGTH];
        char m_givenName[MAX_NAME_LENGTH];
        int m_sin;
        //AT HOME class attributes
        int m_year[MAX_YRS];
        double m_balance[MAX_YRS];
        int m_years;

    public:
        CRA_Account();
        void set(const char* familyName, const char* givenName, int sin);
        bool isValid() const;
        void display() const;
        //AT HOME class member function
        void set(int year, double balance);
    };
}
#endif //SICT_CRA_ACCOUNT_H
