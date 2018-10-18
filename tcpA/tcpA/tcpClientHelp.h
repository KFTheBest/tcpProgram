#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP
#define LISTENQ (1024)
#define MAX_LINE (1000)

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ParseCmdLine(int argc, char *argv[], char **szAddress, char **szPort);
ssize_t readLine(int fd, void *vptr, size_t maxlen);
ssize_t writeLine(int fc, const void *vptr, size_t maxlen);

#endif 