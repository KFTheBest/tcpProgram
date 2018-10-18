#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>  
#include <unistd.h>             

#define LISTENQ (1024)   

ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Writeline(int fc, const void *vptr, size_t maxlen);


#endif 