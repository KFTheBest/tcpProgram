#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP
#define LISTENQ (1024)
#define MAX_LINE (1000)
#define PORT 4444

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

extern int errno;

int ParseCmdLine(int argc, char *argv[], char **szAddress, char **szPort);
ssize_t readData(int fd, void *vptr, size_t maxlen);
ssize_t writeBack(int fc, const void *vptr, size_t maxlen);

#endif 