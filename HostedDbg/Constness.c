#include<stdio.h>
#include<stdint.h>

void foo(uint16_t val){
    (void)val;
    return;
}


int main(){
    const uint16_t var = 1030;
    foo(var);
    return 0;
}