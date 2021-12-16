#include <iostream>
#include "classes.cpp"

void exchange(Vehicle* A, int a, int b){  // neden & kullanamadım??
        Vehicle* temp = &A[a];
        A[a] = A[b];
        A[b] = *temp;
}

void min_heapify(Vehicle* A, int i, int heap_size = 1642){
    int l = i * 2;
    int r = l +1;
    int smallest = i;
    if (l < heap_size && A[l] < A[i])
        smallest = l;

    if (r < heap_size && A[r] < A[smallest])
        smallest = r;
    
    if (smallest != i){
        exchange(A, i, smallest);
        min_heapify(A, smallest);
    }   

}


void build_min_heap(Vehicle* A){
    int heap_size = 1641;
    for (int i = int(heap_size / 2); i >= 0; i-- ){
        min_heapify(A,i);
    }
}

void heap_sort(Vehicle* A){
    build_min_heap(A);
    for (int i = 1641; i > 0; i--){
        exchange(A, 0, i);
        // decrease heap size but how
        min_heapify(A, 0, i);   // not so sure about what I have done
    }
}


Vehicle* heap_extract_min(Vehicle* vehicles, int heap_size){
    if (heap_size < 1){
        cout <<"ne yaptın gardaş"<<endl;
        return NULL;
    } 

}