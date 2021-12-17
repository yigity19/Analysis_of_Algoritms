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

/**
 * @brief Vehicle class for data encapsulation
 * 
 */
class Vehicle{
    public:
        int id;
        string location;
        double distance;
        int speed;
        double time;
        Vehicle(){time = -1;};
        Vehicle(int id,string location, double distance, int speed);
        bool operator<(Vehicle &a);
        void calculateTime(){time = distance / speed;}

}; 

/**
 * @brief Construct a new Vehicle:: Vehicle object
 * 
 * @param id id of vehicle
 * @param location current location of the car
 * @param distance distance to the hotel
 * @param speed speed of the vehicle
 */
Vehicle::Vehicle(int id,string location, double distance, int speed){
    this->id = id;
    this->location = location;
    this->distance = distance;
    this->speed = speed;
    time = distance / speed;
}


/**
 * @brief < operator overload for Vehicle class
 * 
 * @param a Vehicle object
 * @return Whether this < a true of false
 */
bool Vehicle::operator<(Vehicle &a){
    float thisTime = this->time;
    if (thisTime < a.time)
        return true;
    return false;
}

/**
 * @brief .Request class for data encapsulation
 * 
 */
class Request{
    public:
        Request(string, double, int);
        string location;
        double distance;
        int lucky_num;
};

/**
 * @brief Construct a new Request:: Request object
 * 
 * @param location location of the destination of the customer
 * @param distance distance of the destination adress to the hotel
 * @param lucky_num luck number of customer
 */
Request::Request(string location, double distance, int lucky_num){
    this->location = location;
    this->distance = distance;
    this->lucky_num = lucky_num;
}
