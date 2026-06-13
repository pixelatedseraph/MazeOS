#ifndef __GDT_HXX
#define __GDT_HXX

#include<stdint.h>

namespace GDT{
    struct [[gnu::packed]] Entry{
        uint16_t limit;
        uint16_t baseLow;
        uint8_t  baseMiddle;
        uint8_t  acesss;
        uint8_t  flags;
        uint8_t  baseHigh;
    };

    struct[[gnu::packed]] Reference{
        uint16_t limit;
        uint32_t base;
    };


    void initGDT();
    void setGDTEntry(uint32_t num,uint32_t base,uint32_t limit,uint8_t access,uint8_t flags);

}
#endif