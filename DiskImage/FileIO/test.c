
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){ 
    FILE* fp = fopen("hello.txt","r");
    
    
    fclose(fp);
    return 0;
}