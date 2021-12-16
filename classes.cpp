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
        
        bool operator<(Vehicle &a);
        float calculateTime(){return distance / speed;}
}; 


// --------------------------------------------------*---------------------------------------------------
bool Vehicle::operator<(Vehicle &a){
    float thisTime = this->speed;
    if (thisTime < a.speed)
        return true;
    return false;
}

class Request{
    public:
        Request(string, float, int);
        string location;
        float distance;
        int lucky_num;
};

Request::Request(string location, float distance, int lucky_num){
    this->location = location;
    this->distance = distance;
    this->lucky_num = lucky_num;
}
