/**
 * @file heap_sort.cpp
 * @author Yunus Emre Yiğit (yigity19@itu.edu.tr)
 * @brief 
 * @Student_Number 150190107
 * @date 2021-12-17
 */
#include <iostream>
#include "classes.cpp"

void exchange(Vehicle* A, int a, int b){  // neden & kullanamadım??
        Vehicle* temp = &A[a];
        A[a] = A[b];
        A[b] = *temp;
}

/**
 * @brief Makes swapping between elements of the heap to maintaiin heap structure if necessary
 * 
 * @param A Array
 * @param heap_size Array size 
 * @param smallest Element index to be placed to the correct place
 */
void min_heapify(Vehicle A[], int &heap_size, int smallest){
    int i = smallest;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < heap_size && A[smallest] < A[l])
        smallest = l;

    if (r < heap_size && A[smallest] < A[r])
        smallest = r;
    
    if (smallest != i){
        //exchange(A, i, smallest);
        swap(A[i], A[smallest]);
        min_heapify(A, heap_size, smallest);
    }   

}

/**
 * @brief Another version of the minHeapify
 * 
 * @param A 
 * @param heap_size 
 * @param smallest 
 */
void min_heapify2(Vehicle A[], int &heap_size, int smallest){
    int i = smallest;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < heap_size && A[l] < A[smallest])
        smallest = l;

    if (r < heap_size && A[r] < A[smallest])
        smallest = r;
    
    if (smallest != i){
        //exchange(A, i, smallest);
        swap(A[i], A[smallest]);
        min_heapify2(A, heap_size, smallest);
    }   

}

/**
 * @brief Structures the given array A according to the heap structure
 * 
 * @param A Array to be structured according to the heap structure
 * @param heap_size Array size to be structured according to heap structure
 */
void build_min_heap(Vehicle A[], int heap_size){
    for (int i = heap_size / 2 -1; i >= 0; i-- ){
        min_heapify(A,heap_size, i);
    }
}

/**
 * @brief Sorts the given array with heap sort algorithm
 * 
 * @param A Array to be sorted
 * @param heap_size Size of the array to be sorted
 */
void heap_sort(Vehicle* A, int heap_size){
    build_min_heap(A, heap_size);
    for (int i = heap_size - 1; i >= 0; i--){
        //exchange(A, 0, i);
        swap(A[0], A[i]);
        // decrease heap size but how
        min_heapify(A, i, 0);   // not so sure about what I have done
    }
}

/**
 * @brief Removes and returns root of the heap while maintaining the heap property 
 * 
 * @param vehicles Min Priority Heap
 * @param heap_size Size of heap
 * @return Vehicle* Root of the tree is returned
 */
Vehicle* heap_extract_min(Vehicle* vehicles, int &heap_size){
    if (heap_size < 1){
        cout <<"ne yaptın gardaş"<<endl;
    } 

    Vehicle* min = new Vehicle;
    min[0] = vehicles[0]; 
    vehicles[0] = vehicles[heap_size - 1];
    heap_size--;
    min_heapify2(vehicles, heap_size, 0);
    return min;
}

/**
 * @brief Places the element pointed by the key to the correct place of the heap.
 * 
 * @param vehicles Array of vehicles in heap order
 * @param heap_size Size of the heap
 * @param key The place of the node whose place is to be corrected
 */
void decreaseKey(Vehicle vehicles[], int &heap_size, int key, bool flag = false){ //--------------------------------------------------------------------------
    int parent = (key - 1) / 2;
    if (not flag)
        vehicles[key].time = -1;
    while(parent > 0 && vehicles[key] < vehicles[parent]){ 
        //cout << "key " <<key << " " << parent << vehicles[parent].speed << " " << vehicles[key].speed <<endl;
        swap(vehicles[parent], vehicles[key]);
        key = parent;
        parent = (key - 1) / 2; 
    }
}

/**
 * @brief Insert a new node to the end of the min priority queue. 
 * Call decreaseKey to place it to the aproppriate place to maintain heap property.
 * 
 * @param vehicles Array of vehicles in heap order
 * @param request The information about the destination and customer 
 * @param heap_size Size of the heap
 * @param gone The vehicle object which brought the customer to the destination
 */
void minHeapInsert(Vehicle vehicles[], Request &request, int &heap_size, Vehicle &gone){
    //cout<<"heap_size"<<heap_size<<endl;
    heap_size++;
    gone.distance = request.distance;    // -1 olması gerekiyor mu 
    gone.location = request.location;
    gone.calculateTime();
    vehicles[heap_size -1] = gone;
    decreaseKey(vehicles, heap_size,  heap_size - 1, true);

}   
