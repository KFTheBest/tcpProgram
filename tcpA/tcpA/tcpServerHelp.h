#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>      
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>   

#define LISTENQ (1024) 
#define ECHO_PORT (2002)
#define MAX_LINE (1000)


ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Writeline(int fc, const void *vptr, size_t maxlen);


#endif 
