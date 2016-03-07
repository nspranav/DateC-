//
//  Date.h
//  assign6
//
//  Created by Pranav Nadigapu on 3/7/16.
//  Copyright © 2016 Pranav Nadigapu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


#ifndef Date_h
#define Date_h

class Date
{
private:
    string month;
    int day;
    int year;
    const bool isValidMonth() const;
    const int daysInMonth(const string &m) const;
    const bool isLeapYear(void) const;
    vector<string> months { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
public:
    Date (const string & m = "January", int d = 1, int y = 2000);
    friend istream &operator>>(istream&, Date&);
    friend ostream &operator<<(ostream&,const Date&);
    void setMonth(const string &m);
    void setDay(const int &d);
    void setYear(const int &y);
    string getMonth();
    int getDay();
    int getYear();
    void Month(void);
    const bool isValidDate(void) const;
    string toString(void);
};

#endif /* Date_h */
