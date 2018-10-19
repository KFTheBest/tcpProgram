#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP
#define LISTENQ (1024)   
#define ECHO_PORT (4444)
#define MAX_LINE (1000)
#define DATA_ZERO 0
#define DATA_ONE 1

#include <unistd.h>      
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>      
#include <sys/types.h>        
#include <arpa/inet.h>                 
#include <stdbool.h>
#include <error.h>
#include <errno.h>
#include <string.h>




extern int errno;
const short TYPE_SIZE = 1;

ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Writeline(int fc, const void *vptr, size_t maxlen);
int getType(FILE*);
bool isEndofLine(unsigned);
void readFile(const char*);
int numsReadIn(FILE*);
int translateZero(FILE*);
int translateOne(FILE*);


#endif 