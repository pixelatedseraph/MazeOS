#ifndef __SUM_H
#define __SUM_H
namespace Helper::Private{
    void add(int val);
}
template<typename... T>
void sum(T... args){
    (Helper::Private::add(args),...);
}

void printSum();

#endif