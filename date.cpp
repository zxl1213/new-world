#include "date.h"
Date& Date::operator+=(int day){
  _day+=day;
  while(_day>GetMonthDay(_year,_month)){
    _day-=GetMonthDay(_year,_month);
    _month++;
    if(_month==13){
      _year++;
      _month=1;
    }
  }
  return *this;
}
Date Date::operator+(int day)const{
  Date d=*this;
  d+=day;
  return d;
}
Date& Date::operator++(){
  *this+=1;
  return *this;
}
Date Date::operator++(int){
  Date d(*this);
  *this+=1;
  return d;
}
Date& Date::operator-=(int day){
  _day-=day;
  while(_day<1){
    if(_month==1){
      _year--;
      _month=12;
      _day+=GetMonthDay(_year,_month);
    }else{
      _day+=GetMonthDay(_year,_month-1);
      _month--;
    }
  }
  return *this;
}
Date Date::operator-(int day)const{
  Date d=*this;
  d-=day;
  return d;
}
Date& Date::operator--(){
  *this-=1;
  return *this;
}
Date Date::operator--(int){
  Date d(*this);
  *this-=1;
  return d;
}
bool Date::operator>(const Date& d)const{
  if(this->_year>d._year){
    return true;
  }if(this->_year==d._year){
    if(this->_month>d._month){
      return true;
    }if(this->_year==d._year&&this->_month>d._month){
      if(this->_day>d._day){
        return true;
      }
    }
  }
  return false;
}
bool Date::operator>=(const Date& d)const{
  if(*this>d||*this==d){
    return true;
  }
  return false;
}
bool Date::operator<(const Date& d)const{
  return !(*this>=d);
}
bool Date::operator<=(const Date& d)const{
  return !(*this>d);
}
bool Date::operator==(const Date& d)const{
  if(this->_year==d._year
      &&this->_month==d._month
      &&this->_day==d._day){
    return true;
  }
  return false;
}
bool Date::operator!=(const Date& d)const{
  return !(*this==d);
}
int Date::operator-(const Date& d){
  int day=0;
  Date d1(*this);
  Date d2(d);
  if(d1>=d2){
    while(d1!=d2){
      d2++;
      day++; 
    }
  }else{
    while(d1!=d2){
      d1++;
      day++;
    }
  }
  return day;
}
int main(){
  Date d1(2020,2,29); 
  Date d2(2020,2,2); 
  cout<<(d1-d2)<<endl;
}
