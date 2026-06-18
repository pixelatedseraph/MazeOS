#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include"HexDump.h"

    int x = 10;
    int y = 20;

    int n1 = -100;    
    int n2 = -100;    

    int n3 = -100;
    int n4 =  100;

    int n5 = 0;
    int n6 = -10;

    int n7 = -10;
    int n8 = 0;

    unsigned int u1 = 1010;
    unsigned int u2 = 1010;

    double a = 21.231341;
    double b = 21.231341;

    const char* i = "hello";
    const char* j = "goo kha 1245";


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


    

static void test_hex_equal_ints(void** state){
    (void)state;
    assert_int_equal(hex_equal(&x,&y,sizeof(int)),-1);
    assert_int_equal(hex_equal(&n1,&n2,sizeof(int)),0);
    assert_int_equal(hex_equal(&n3,&n4,sizeof(int)),1);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_hex_equal_ints),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}