#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>

char* image_name = "foo.img";

bool write_mbr(FILE* image){
    typedef struct [[gnu::packed]] {
        uint8_t boot_indicator;
        uint8_t starting_chs[3];
        uint8_t os_type;
        uint8_t ending_chs[3];
        uint8_t starting_lba;
        uint8_t ending_lba;
    }MasterBootRecordPartition;
    
    typedef struct [[gnu::packed]]{
        uint8_t boot_code[400];
        uint8_t mbr_signature;
        uint16_t unknown;
        MasterBootRecordPartition partition[4];
        uint16_t boot_signature;
    }MasterBootRecord;

    //TODO 
    MasterBootRecord mbr = {

    };
    //write to file
    if (fwrite(&mbr,1,sizeof mbr,image) != sizeof mbr)
        return false;

    return true;
}

int main(){
    FILE* image  = fopen(image_name,"wb+");
    if(!image){
        fprintf(stderr,"[Error]: Couldnt Open file %s\n",image_name);
        return EXIT_FAILURE;
    }

    if(!write_mbr(image)){
        fprintf(stderr,"[Error]: Couldnt Protective MBR for the file %s\n",image_name);
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}