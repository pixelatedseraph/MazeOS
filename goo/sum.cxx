#include<iostream>
#include "sum.h"

int glbSum = 0;

namespace Helper
{
    namespace Private{
  void add(int val){
        glbSum += val;
    }
    }  
} 


void printSum(){
    std::cout<<glbSum<<std::endl;
}