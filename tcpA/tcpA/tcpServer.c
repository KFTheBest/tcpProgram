#include "tcpServerHelp.h"          
#include "tcpServerHelp.c"


int main(int argc, char *argv[]) {
	int       list_s;                
	int       conn_s;                
	short int port;                  
	struct    sockaddr_in servaddr;  
	char      buffer[MAX_LINE];      
	char     *endptr;                

	if (argc == 2) {
		port = strtol(argv[1], &endptr, 0);
		if (*endptr) {
			fprintf(stderr, "ECHOSERV: Invalid port number.\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (argc < 2) {
		port = ECHO_PORT;
	}
	else {
		fprintf(stderr, "ECHOSERV: Invalid arguments.\n");
		exit(EXIT_FAILURE);
	}

	/*  Create the listening socket  */

	if ((list_s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "ECHOSERV: Error creating listening socket.\n");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);


	/*  Bind socket addresss to listening socket */

	if (bind(list_s, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		fprintf(stderr, "ECHOSERV: Error calling bind()\n");
		exit(EXIT_FAILURE);
	}

	if (listen(list_s, LISTENQ) < 0) {
		fprintf(stderr, "ECHOSERV: Error calling listen()\n");
		exit(EXIT_FAILURE);
	}


	//Loop to respond to client requests
	printf("server: waiting for connections...\n");
	while (1) {

		if ((conn_s = accept(list_s, NULL, NULL)) < 0) {
			fprintf(stderr, "ECHOSERV: Error calling accept()\n");
			exit(EXIT_FAILURE);
		}


		/*  Handle read and write for between server and client     */

		Readline(conn_s, buffer, MAX_LINE - 1);
		Writeline(conn_s, buffer, strlen(buffer));


		/*  Close the connected socket  */
		printf("server: got connection \n");

		if (close(conn_s) < 0) {
			fprintf(stderr, "ECHOSERV: Error calling close()\n");
			exit(EXIT_FAILURE);
		}
	}
}

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
