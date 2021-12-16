#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "classes.cpp"

using namespace std;

void printArray(Vehicle* vehicles){
    for(int i = 0; i < 1642; i++){
        cout<< vehicles[i].id<< " " <<vehicles[i].location<< " "<< vehicles[i].distance<< " " <<vehicles[i].speed<<endl;
    }
}

int main(){
    Vehicle* vehicles = new Vehicle[1642];         
	vector<string> row;
	string line, word;
    int i = -1;
	fstream file ("vehicles.txt", ios::in);
	if(file.is_open()){                          // read from the csv file {
		while(getline(file, line))
		{
            cout<<"burada"<<endl;
			row.clear();
			stringstream str(line);
 
			while(getline(str, word, '\t'))             
				row.push_back(word);
            
            //Vehicle* new_vehicle = new Vehicle;
            if (i != -1){
            Vehicle new_vehicle;
            new_vehicle.id =  stoi(row[0]);
            new_vehicle.location = row[1];
            new_vehicle.distance = stof(row[2]);
            new_vehicle.speed = stoi(row[3]);
            vehicles[i] = new_vehicle;
            }
            i++;
		}
	}
	else
		cout<<"Could not open the file\n";
    printArray(vehicles);
    return 0;
}