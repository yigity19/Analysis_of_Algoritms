/**
 * @file classes.cpp
 * @author Yunus Emre Yiğit (yigity19@itu.edu.tr)
 * @brief 
 * @Student_Number 150190107
 * @date 2021-12-17
 */
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Vehicle{
    public:
        int id;
        string location;
        double distance;
        int speed;
        double time;

        bool operator<(Vehicle &a);
        float calculateTime(){time = distance / speed;}
}; 


// --------------------------------------------------*---------------------------------------------------
bool Vehicle::operator<(Vehicle &a){
    this->calculateTime();
    a.calculateTime();
    float thisTime = this->time;
    if (thisTime < a.time)
        return true;
    return false;
}

class Request{
    public:
        Request(string, double, int);
        string location;
        double distance;
        int lucky_num;
};

Request::Request(string location, double distance, int lucky_num){
    this->location = location;
    this->distance = distance;
    this->lucky_num = lucky_num;
}
