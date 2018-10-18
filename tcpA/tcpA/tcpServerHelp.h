#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>      
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>   
#include <string.h>
#include <netinet/in.h>


#define LISTENQ (1024) 
#define ECHO_PORT (2002)
#define MAX_LINE (1000)
#define PORT (4444)
# define DATAZERO 0
#define DATAONE 1


//Define struct as how it should be received from client
struct myFile {

	unsigned char file*;
	unsigned char* file_name;
}myFile;


ssize_t readData(int fd, void *vptr, size_t maxlen);
ssize_t writeBack(int fc, const void *vptr, size_t maxlen);
bool endOfLine(unsigned chr);
bool detectNoNums(unsigned chr);


struct 


#endif 
