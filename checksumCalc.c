#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "ocarina.h"

#define BUFFER_SIZE 4946

unsigned int uShort(unsigned char *data, int bufSize);

int main(int argc, char **argv){
    FILE *file = fopen(argv[1], "r");

    unsigned char buffer[BUFFER_SIZE];

    size_t offset = 1157008;

    fseek(file, offset, SEEK_SET);
    size_t size = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file);
    
    unsigned int checksum = uShort(buffer, size);

    printf("0x%X\n", checksum); //4dc5

    return 0;
}

unsigned int uShort(unsigned char *data, int bufSize){
    int z;
    unsigned int checksum = 0;
    for(z = 0; z < bufSize - 1; z += 2){
        checksum += ((ushort)data[z] << 8) + data[z + 1];
    }

    return checksum;
}
