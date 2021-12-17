/**
 * @file main.cpp
 * @author Yunus Emre Yiğit (yigity19@itu.edu.tr)
 * @brief 
 * @Student_Number 150190107
 * @date 2021-12-17
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "heap_sort.cpp"
#include "classes.cpp"

using namespace std;

void printArray(Vehicle* vehicles, int len){
    for(int i = 0; i < len; i++){
        cout<< vehicles[i].id<< " " <<vehicles[i].location<< " "<< vehicles[i].distance<< " " <<vehicles[i].speed<<endl;
    }
}

int main(){
    int heap_size = 1642;
    Vehicle vehicles[heap_size];         
	vector<string> row;
	string line, word;
    int i = -1;
	fstream file ("vehicles.txt", ios::in);
	if(file.is_open()){                          // read from the csv file {
		while(getline(file, line))
		{
			row.clear();
			stringstream str(line);
 
			while(getline(str, word, '\t'))             
				row.push_back(word);
            
            //Vehicle* new_vehicle = new Vehicle;
            if (i != -1){
                Vehicle* new_vehicle = new Vehicle;
                new_vehicle->id =  stoi(row[0]);
                new_vehicle->location = row[1];
                new_vehicle->distance = stod(row[2]);
                new_vehicle->speed = stoi(row[3]);
                
                vehicles[i] = *new_vehicle;
                //delete new_vehicle;
            }
            i++;
		}
	}
	else
		cout<<"Could not open the vehicles.txt\n";

    i = -1;
    vector<Request> requests;
	fstream file2 ("requests.txt", ios::in);
	if(file2.is_open()){                          // read from the csv file {
		while(getline(file2, line))
		{
			row.clear();
			stringstream str(line);
 
			while(getline(str, word, '\t'))             
				row.push_back(word);
            
            //Vehicle* new_vehicle = new Vehicle;
            if (i != -1){
                double row1 = stod(row[1]);
                int row2 = stoi(row[2]);
                Request* new_request = new Request(row[0], row1, row2);
                requests.push_back(*new_request);
            }
            i++;
		}
	}
	else
		cout<<"Could not open the request.txt\n";

    
    
    /*//printArray(vehicles);
    heap_sort(vehicles, heap_size);
    //printArray(vehicles, heap_size);
    decreaseKey(vehicles, heap_size, 1);
    Vehicle* deneme = heap_extract_min(vehicles, heap_size);

    Request request("*************************************", 442.00, 117);
    //cout <<"------------------------------------------"<<endl;
    minHeapInsert(vehicles, request, heap_size, *deneme);
    printArray(vehicles, heap_size);
    //printArray(deneme2, 1);*/

    return 0;
}