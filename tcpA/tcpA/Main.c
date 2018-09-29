#include <stdio.h>
#include <stdbool.h>


const short TYPE_SIZE = 1;

int getType(FILE*);

bool isEndofLine(unsigned c){
	return (int)c==0 || (int)c ==1;
}

int main() {
	const char* FILE_NAME = "Something";
	FILE* infile = fopen(FILE_NAME, "rb");

	while(getType(infile) != 1) {
	}

	return 0;
}

int getType(FILE* file){
	unsigned char type; //where byte will go
	int bytesRead = fread(&type,sizeof(type),1, file); //reading
	return (bytesRead) ? (int)type : -1; // if byte was read, then 1 bytes would have been read. returns number of bytes read. 
	//if no bytes have been read, then its the end of the file. Return -1 to indicate that
}
