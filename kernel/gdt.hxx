#ifndef __GDT_HXX
#define __GDT_HXX

#include<stdint.h>

class GlobalDescriptorTable{
    public:
       class SegementDescriptor{
        private:
            uint16_t LimitLow;
            uint16_t BaseLow;
            uint8_t  BaseHigh;
            uint8_t  Access;
            uint8_t  FlagLimitHigh;
            uint8_t  BaseVeryHigh;
        public:
            SegementDescriptor(uint32_t base,uint32_t limit,uint8_t access);
            
            uint32_t Base();
            uint32_t Limit();

       } __attribute__((packed)); 
    
    SegementDescriptor nullSegementSelector;
    SegementDescriptor unusedSegementSelector;       
    SegementDescriptor codeSegementSelector;       
    SegementDescriptor dataSegementSelector;
    
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();

    uint16_t getCodeSegementSelector();
    uint16_t getDataSegementSelector();
    
};

#endif