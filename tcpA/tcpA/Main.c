#include <stdio.h>
#include <stdbool.h>


const short TYPE_SIZE = 1;

int getType(FILE*);

bool isEndofLine(unsigned c){
	return (int)c==0 || (int)c ==1;
}

int main() {
	const char* FILE_NAME = "practice_project_test_file";
	readFile(FILE_NAME);
	return 0;
}

void readFile(const char* readFile) {
	FILE* infile = fopen(readFile, "rb");
	if (infile != NULL) {
		while (getType(infile) != -1) {

			int type = getType(infile);
			if (type == 0) {
				translateZero(infile);
			}
			else {
				translateOne(infile);
			}
		}
	}
	
}

int getType(FILE* file){
	unsigned char type; //where byte will go
	int bytesRead = fread(&type,sizeof(type),1, file); //reading
	return (bytesRead) ? (int)type : -1; // if byte was read, then 1 bytes would have been read. returns number of bytes read. 
	//if no bytes have been read, then its the end of the file. Return -1 to indicate that
}

int numsReadIn(FILE* infile) {
	unsigned char type;
	char numBytes = fread(&type, sizeof(type), 1, infile); //reading
	int num = numBytes;
	return num;
}

int translateZero(FILE* infile) {
	unsigned char type;
	int byteA = fread(&type, sizeof(type), 1, infile); //reading first byte
	int byteB = fread(&type, sizeof(type), 1, infile); //reading second byte
	byteA = byteA >> 8;
	byteA = byteA && byteB;
	printf("%i", byteA);
	printf("\n");
	return byteA;

}
int translateOne(FILE* infile) {
	unsigned char type;
	int byte = fread(&type, sizeof(type), 1, infile); //reading first byte
	byte = byte - 48;
	printf("%i", byte);
	printf("\n");
	return byte;
}

