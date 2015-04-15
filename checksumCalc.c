#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "ocarina.h"

#define BUFFER_SIZE 4946

unsigned int uShort(unsigned char *data, int bufSize);

int main(int argc, char **argv){
	//This makes sure that the comman is the right length
	if(argc != 3){
		printf("Invalid use!");
	}

	//Opens the file to read from
	FILE *file = fopen(argv[1], "r");

	//The save file into one buffer
	unsigned char buffer[BUFFER_SIZE];

	//Safe way to get string->hex->decimal for the offset
	size_t offset = strtoul(argv[2], (char **)0, 16);

	//Offsets the file
	fseek(file, offset, SEEK_SET);
	//Reads the file into the buffer
	size_t size = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file);

	//Final value of the checksum
	unsigned int checksum = uShort(buffer, size);

	//This is anding the value to only get the 4 byte answer we need
	checksum = checksum & 0x00ffff;

	printf("0x%X\n", checksum); //4dc5

	return 0;
}

unsigned int uShort(unsigned char *data, int bufSize){
	int z;
	unsigned int checksum = 0;
	//Calculates the checksum
	for(z = 0; z < bufSize - 1; z += 2){
		//Adds the bytes in together
		checksum += ((ushort)data[z] << 8) + data[z + 1];
	}

	return checksum;
}
