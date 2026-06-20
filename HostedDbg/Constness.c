#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void cleanheap(void* ptr){
    free(*(void**)ptr);
    printf("Cleaned up\n");
}

int* foo(){
    int* heap = malloc(40);
    heap[0] = 1;
    heap[1] = 10;
    heap[2] = 100;
    heap[3] = 1000;
    heap[4] = 999;
    heap[5] = 1131;
    printf("Returning from foo() now\n");
    return heap;
}


int main(){
    __attribute__((cleanup(cleanheap))) int* res = foo();
    
    printf("Back to main %d\n",res[3]);
    return 0;
}