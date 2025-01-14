#include "Time.hpp"

Time::Time(){
    this->h = 0;
    this->m = 0;
    this->s = 0;
}

Time::Time(int h, int m, int s){
    this->h = h;
    this->m = m;
    this->s = s;
}

Time::Time(const Time& other){
    this->h = other.h;
    this->m = other.m;
    this->s = other.s;
}

Time::~Time(){}

int Time::getHour(){
    return this->h;
}

int Time::getMinute(){
    return this->m;
}

int Time::getSecond(){
    return this->s;
}

void Time::setHour(int HOUR){
    this->h = HOUR;
}

void Time::setMinute(int MINUTE){
    this->m = MINUTE;
}

void Time::setSecond(int SECOND){
    this->s = SECOND;
}

int Time::convertToSecond(){
    return ((this->h)*3600 + (this->m)*60 + (this->s));
}

Time Time::add(Time t){
    int temp_h, temp_m, temp_s;
    temp_h = this->h + t.h;
    temp_m = this->m + t.m;
    temp_s = this->s + t.s;

    if (temp_s >= 60){
        temp_m += temp_s / 60;
        temp_s = temp_s % 60;
    }
    if (temp_m >= 60){
        temp_h += temp_m / 60;
        temp_m = temp_m % 60;  
    }
    if (temp_h >= 24){
        temp_h = temp_h % 24;
    }

    return Time(temp_h, temp_m, temp_s);
}

Time Time::minus(Time t){
    if (this->convertToSecond() < t.convertToSecond()){
        return Time(this->h, this->m, this->s);
    }

    int selisih, temp_h, temp_m, temp_s;
    selisih = this->convertToSecond() - t.convertToSecond();
    temp_h = selisih / 3600;
    temp_m = (selisih - (temp_h * 3600)) / 60;
    temp_s = (selisih - (temp_m * 60 + temp_h * 3600));

    return Time(temp_h, temp_m, temp_s);
}

void Time::printTime(){
    if (h < 10){
        cout << "0" << h << ":";
    }
    else{
        cout << h << ":";
    }
    if (m < 10){
        cout << "0" << m << ":";
    }
    else{
        cout << m << ":";
    }
    if (s < 10){
        cout << "0" << s << endl;
    }
    else{
        cout << s << endl;
    }
}
