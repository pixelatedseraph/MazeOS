#include<iostream>
#include<concepts>

void print(const char){

}


template<typename T> 
requires std::integral<T>
void printInt(T value){
    std::cout<<value<<std::endl;
}

template<typename... Args>
void logger(Args... args){
    (print(args),...);
}

int main(){
    int x = 10;
    unsigned int y = 220;
    short z = 3282;
    unsigned short a = 21;
    unsigned long b = 728821;
    long   c = 367812;
    unsigned long long d = 3286832;
    logger(x,y,z,a,b,c,d,"foo");
    return 0;
}
