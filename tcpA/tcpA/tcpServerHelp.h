#ifndef PG_SOCK_HELP
#define PG_SOCK_HELP


/*#include <unistd.h>             /*  for ssize_t data type  */
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define LISTENQ        (1024)   /*  Backlog for listen()   */


/*  Function declarations  */

ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Writeline(int fc, const void *vptr, size_t maxlen);


#endif  /*  PG_SOCK_HELP  */