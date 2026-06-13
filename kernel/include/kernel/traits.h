#ifndef __TRAITS_H
#define __TRAITS_H


namespace TraitBounds{
    template<typename T>
    struct is_integral{
        static constexpr bool value = false;
    };

    template<> struct is_integral<int> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned int> {static constexpr bool value = true; }; 
    template<> struct is_integral<short> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned short> {static constexpr bool value = true; }; 
    template<> struct is_integral<long> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned long> {static constexpr bool value = true; }; 
    template<> struct is_integral<long long> {static constexpr bool value = true; }; 
    template<> struct is_integral<unsigned long long> {static constexpr bool value = true; }; 

    template<typename T,typename U>
    struct is_same{
        static constexpr bool value = false;
    };

    template<typename T>
    struct is_same<T,T>{
        static constexpr bool value = true;
    };


    template <typename T>
    concept Integral = is_integral<T>::value;

    template<typename T>
    concept SignedIntegral = Integral<T> && (T(-1) < T(0));

    template<typename T>
    concept UnsignedIntegral = Integral<T> && !(T(-1) < T(0));
 
    template<typename T,typename U>
    inline constexpr bool is_same_v = is_same<T,U>::value;
}


#endif