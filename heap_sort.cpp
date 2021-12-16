#include <iostream>
#include "classes.cpp"

void exchange(Vehicle* A, int a, int b){  // neden & kullanamadım??
        Vehicle* temp = &A[a];
        A[a] = A[b];
        A[b] = *temp;
}

void min_heapify(Vehicle A[], int heap_size, int smallest){
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

void min_heapify2(Vehicle A[], int heap_size, int smallest){
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


void build_min_heap(Vehicle A[], int heap_size){
    for (int i = heap_size / 2 -1; i >= 0; i-- ){
        min_heapify(A,heap_size, i);
    }
}

void heap_sort(Vehicle* A, int heap_size){
    build_min_heap(A, heap_size);
    for (int i = heap_size - 1; i >= 0; i--){
        //exchange(A, 0, i);
        swap(A[0], A[i]);
        // decrease heap size but how
        min_heapify(A, i, 0);   // not so sure about what I have done
    }
}

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

//Put the element at index key, to the root. 
//Then extract and return root using heap_extract_min
Vehicle* decreaseKey(Vehicle vehicles[], int &heap_size, int key){
    int parent;
    
    do { 
        parent = (key - 1) / 2; 
        cout << "key " <<key << " " << parent << vehicles[parent].speed << " " << vehicles[key].speed <<endl;
        swap(vehicles[parent], vehicles[key]);
        key = parent;
    }
    while(parent > 0 );//&& vehicles[parent] < vehicles[key]);

    return heap_extract_min(vehicles, heap_size);
}

void minHeapInsert(Vehicle vehicles[], Request &request, int &heap_size, int key){
    cout<<"heap_size"<<heap_size<<endl;
    heap_size++;
    vehicles[heap_size - 1].distance = request.distance;    // -1 olması gerekiyor mu 
    vehicles[heap_size - 1].location = request.location;
    vehicles[heap_size - 1].speed = key;
    decreaseKey(vehicles, heap_size, key); 
}   
