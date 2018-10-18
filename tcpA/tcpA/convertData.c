#include "convertData.h"

bool isEndofLine(unsigned c) { return (int)c == 0 || (int)c == 1; }

void readFile(const char* readFile) {
	FILE* infile = fopen(readFile, "rb");
	if (infile != NULL) {
		int type = getType(infile);
		while (getType(infile) != -1) {
			if (type == 0) {
				int amountNums = numsReadIn(infile);
				for (int i = 0; i < amountNums; i++) {
					translateZero(infile);
				}
			}
			else if (type == 1) {
				int amountNums = numsReadIn(infile);
				for (int i = 0; i < amountNums; i++) {
					translateOne(infile);
				}
			}
			else {}
		}
	}
}
int getType(FILE* file) {
	unsigned char type; //where byte will go
	int bytesRead = fread(&type, sizeof(type), 1, file); //reading
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
	unsigned char typeA;
	unsigned char typeB;
	int byteARead = fread(&typeA, sizeof(typeA), 1, infile); //reading first byte
	int byteBRead = fread(&typeB, sizeof(typeB), 1, infile); //reading second byte
	int byteA = typeA << 8;
	int byteB = typeB;
	byteA = byteA | byteB;
	printf("%d", byteA);
	printf("\n");
	return byteA;
}
int translateOne(FILE* infile) {
	unsigned char type;
	int byteRead = fread(&type, sizeof(type), 1, infile); //reading
	while (type != 0 && type != 1) {
		printf("%d", type);
		int byteRead = fread(&type, sizeof(type), 1, infile); //reading
	}
	printf("\n");
	return (int)type;
}
int main() {
	const char* FILE_NAME = "practice_project_test_file";
	readFile(FILE_NAME);
	return 0;
}


