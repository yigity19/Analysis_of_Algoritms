#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    public:
        int id;
        string location;
        float distance;
        int speed;
}; 

class Request{
    public:
        string location;
        float distance;
        int lucky_num;
};
