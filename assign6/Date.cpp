//
//  Date.cpp
//  assign6
//
//  Created by Pranav Nadigapu on 3/7/16.
//  Copyright © 2016 Pranav Nadigapu. All rights reserved.
//

#include "Date.h"


Date::Date(const string &m, int d,int y)
{
    month=m;
    day=d;
    year=y;
    Month();
}

string Date::getMonth()
{
    
    return Date::month;
}
int Date::getYear()
{
    return Date::year;
}
int Date::getDay()
{
    return Date::day;
}
void Date::setDay(const int &d)
{
    Date::day=d;
}
void Date::setYear(const int &y)
{
    Date::year=y;
}
void Date::setMonth(const string &m)
{
    Date::month=m;
    Month();
}

void Date::Month()
{
    month[0]=toupper(month[0]);
    for(int i=1;i<month.length();i++)
    {
        month[i]=tolower(month[i]);
    }
    //cout<<month<<"asa"<<endl;
}

const bool Date::isValidMonth() const
{
    
    for(int i=0;i<months.size();i++)
    {
        if(this->month.compare(months[i])==0)
        {
            return true;
        }
    }
    return false;;
}

const bool Date::isLeapYear(void) const
{
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return true;
    else
        return false;
}
const int Date::daysInMonth(const string &m) const
{
    int daysinmonth[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    
    for(int i=0;i<months.size();i++)
    {
        if(this->month.compare(months[i])==0)
        {
            if(i==1)    //checking for february
            {
                if(isLeapYear())
                    daysinmonth[1]=29;
            }
            return daysinmonth[i];
        }
    }
    return 30;
}

const bool Date::isValidDate() const
{
    if(year<1)
        return false;
    if(!isValidMonth())
        return false;
    if(day>daysInMonth(month))
        return false;
    
    return true;
    
}
string intToString(int n)
{
    if(n<10)
        return "0"+to_string(n);
    else
        return to_string(n);
}

string Date :: toString()
{
    return intToString(day)+"-"+month.substr(0,3)+"-"+intToString(year);
}

istream& operator >>(istream& is, Date& d){
    int day, year;
    string month;
    char ch1;
    if (is >> month >> day)
    {
        is>>ch1;
        if (ch1 == ','||ch1==':')
        {
            is>>year;
            d = Date(month, day, year);
            
        }
        else
        {
            is.unget();
            is>>year;
            d = Date(month, day, year);
        }
    }
    return is;
}

ostream &operator<<(ostream& cout,const Date& d)
{
    cout<<d.month;
    cout<<" ";
    cout<<d.day;
    cout<<", ";
    cout<<d.year;
    return cout;
    
}