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
    min_heapify(vehicles, heap_size, 0);
    return min;
}