#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>

/* MBR Partition */
typedef struct [[gnu::packed]] {
    uint8_t boot_indicator;
    uint8_t starting_chs[3];
    uint8_t os_type;
    uint8_t ending_chs[3];
    uint32_t starting_lba;
    uint32_t size_lba;
}MasterBootRecordPartition;
    
/* Master Boot Record */
typedef struct [[gnu::packed]]{
    uint8_t boot_code[440];
    uint32_t mbr_signature;
    uint16_t unknown;
    MasterBootRecordPartition partition[4];
    uint16_t boot_signature;
}MasterBootRecord;

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;


typedef struct [[gnu::packed]]{
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t header_crc32;
    uint32_t reserved;
    uint64_t my_lba;
    uint64_t alt_lba;
    uint64_t first_usable_lba;
    uint64_t last_usable_lba;
    uint128_t disk_guid;
    uint64_t partition_entry_lba;
    uint32_t number_of_partitions;
    uint32_t size_of_partitions;
    uint32_t partition_entry_array_crc32;
    uint32_t reserved;

}


/* GLB Variables */
char* image_name = "foo.img";
uint64_t lba_size = 512;
uint64_t esp_size = 1024 * 1024 * 33; //33MiB
uint64_t data_size = 1024 * 1024 * 1; // 1 MiB
uint64_t image_size = 0;
uint64_t esp_lbas,data_lbas,image_lbas,image_size_lbas;


uint64_t bytes_to_lbas(const uint64_t bytes){
    return (bytes / lba_size) + (bytes % lba_size > 0 ? 1 : 0);
}

void write_full_lba_size(FILE* image){
    uint8_t zero_sector[512];
    for(uint8_t i = 0 ; i < lba_size - sizeof zero_sector)
}

bool write_mbr(FILE* image){

    uint64_t mbr_image_lbas = image_size_lbas;
    if(mbr_image_lbas > 0xFFFFFFFF)
        mbr_image_lbas = 0x100000000;
    //MasterBootRecord
    MasterBootRecord mbr = {
        .boot_code = {0},
        .mbr_signature = 0,
        .unknown = 0,
        .partition[0] = {
            .boot_indicator = 0,
            .starting_chs = {0x00,0x02,0x00},
            .os_type = 0xEE, // protective gpt
            .ending_chs = {0xFF,0xFF,0xFF},
            .starting_lba = 0x00000001,
            .size_lba = mbr_image_lbas - 1,
        },
        .boot_signature = 0xAA55,
    };
    //write to file
    if (fwrite(&mbr,1,sizeof mbr,image) != sizeof mbr)
        return false;

    write_full_lba_size(image);
    
    return true;
}

int main(){
    FILE* image  = fopen(image_name,"wb+");
    if(!image){
        fprintf(stderr,"[Error]: Couldnt Open file %s\n",image_name);
        return EXIT_FAILURE;
    }

    //Set sizes
    image_size = esp_size + data_size + (1024*1024); //add padding for GPTs/MBR
    image_size_lbas = bytes_to_lbas(image_size);

    if(!write_mbr(image)){
        fprintf(stderr,"[Error]: Couldnt Protective MBR for the file %s\n",image_name);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}