#pragma once
#include <iostream>
using std::cout;
using std::endl;
class Date{
  public:
    inline int GetMonthDay(int year,int month)const{
      static int month_arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
      if(month==2&&(year%4==0||year%400==0)&&(year%100!=0)){
        return 29;
      }
      return month_arr[month-1];
    }
    Date(int year=1900,int month=1,int day=1){
      if(year>0
          &&month>0&&month<13
          &&day>0&&day<=GetMonthDay(year,month)){
        _year=year;
        _month=month;
        _day=day;
      }else{
        cout<<"please enter right Date !"<<endl;
      }
    }
    ~Date(){
      _year=0;
      _month=0;
      _day=0;
    }
    Date(const Date& d){
      _year=d._year;
      _month=d._month;
      _day=d._day;
    }
    void Print(){
      cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;

    Date& operator+=(int day);
    Date& operator-=(int day);

    Date operator+(int day) const;
    Date operator-(int day) const;

    Date& operator++();   // 前置++
    Date operator++(int); // 后置++

    Date& operator--();    // 前置--
    Date operator--(int); // 后置--

    int operator-(const Date&d);

  private:
    int _year;
    int _month;
    int _day;
};
