#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>


void print_hex(void* base,uint32_t limit){
    //printf("0x ");
    for(uint32_t i = 0; i< limit ; ++i){
        printf("%02X ",*(((unsigned char*)base)+i));
    }
    printf("\n");
}

int hex_equal(void* base1,void* base2,uint32_t limit){
    for(uint32_t i = 0 ; i < limit ; ++i){
        if ((*(((unsigned char*)base1)+i)) > (*(((unsigned char*)base2)+i))){
            return 1;
        }
        else if(((*(((unsigned char*)base1)+i)) < (*(((unsigned char*)base2)+i)))){
            return -1;
        }
        continue;
    }
    return 0;
}


#define DebugIntegers(x,y) ({     \
    printf("======================================\n");      \
    printf("Variables: %s(%d),%s(%d)\n",#x,x,#y,y);                       \
    print_hex(&x,sizeof(int));      \
    print_hex(&y,sizeof(int));      \
                                    \
    printf("%d \n",hex_equal(&x,&y,sizeof(int)));   \
    printf("%d \n",memcmp(&x,&y,sizeof(int)));      \
    printf("======================================\n");      \
})


#define Inspect(x,y) ({     \
    printf("======================================\n");      \
    print_hex(&x,sizeof(x));      \
    print_hex(&y,sizeof(y));      \
    printf("%d \n",hex_equal(&x,&y,sizeof(x)));   \
    printf("%d \n",memcmp(&x,&y,sizeof(y)));      \
    printf("======================================\n");      \
})


int main(){


    struct Test{
        int first;
        double second;
        char third;
    };

    struct NestedStruct{
        struct Test t1;
        unsigned int val;
        struct Test t2;
    };


    int x = -10;
    int y = 10;

    int n1 = 10;
    int n2 = 20;

    int n3 = -100;
    int n4 =  100;

    int n5 = 0;
    int n6 = -10;

    int n7 = -10;
    int n8 = 0;

    unsigned int u1 = 1010;
    unsigned int u2 = 1010;


    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"

    /*const char* foo  = "Hello World";
    const char* goo  = "Hello Zorld";
    print_hex(foo,strlen(foo)); 
    print_hex(goo,strlen(goo)); 

    printf("%d\n",hex_equal(foo,goo,strlen(foo)));
    */

    #pragma GCC diagnostic pop


    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wgnu-statement-expression-from-macro-expansion"

    DebugIntegers(x,y);
    DebugIntegers(n1,n2);
    DebugIntegers(n3,n4);
    DebugIntegers(n5,n6);
    DebugIntegers(n7,n8);
    DebugIntegers(u1,u2);

    struct Test t1 = {.first = 1032,.second = 3.1232,.third = 'c'};
    struct Test t2 = {.first = 1032,.second = 3.1232,.third = 'c'};

    struct Test t3 = {.first = 15326537,.second = 463.113,.third = 'a'};

    Inspect(t1,t2);
    Inspect(t2,t3);

    struct NestedStruct ns1 = {.t1 = t1, .val = 1938764, .t2=t2};
    struct NestedStruct ns2 = {.t1 = t1, .val = 19387641, .t2=t2};
    
    Inspect(ns1,ns2);


    #pragma GCC diagnostic pop

    return 0;
}