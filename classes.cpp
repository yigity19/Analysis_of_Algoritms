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



bool Vehicle::operator<(Vehicle &a){
    float thisTime = this->calculateTime();
    if (thisTime < a.calculateTime())
        return true;
    return false;
}

class Request{
    public:
        string location;
        float distance;
        int lucky_num;
};
