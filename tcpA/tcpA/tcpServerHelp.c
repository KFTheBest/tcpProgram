#include "tcpServerHelp.h"


/*  Read a line from a socket  */

ssize_t Readline(int sockd, void *vptr, size_t maxlen) {
	ssize_t n, rc;
	char    c, *buffer;

	buffer = vptr;

	for (n = 1; n < maxlen; n++) {

		if ((rc = read(sockd, &c, 1)) == 1) {
			*buffer++ = c;
			if (c == '\n')
				break;
		}
		else if (rc == 0) {
			if (n == 1)
				return 0;
			else
				break;
		}
		else {
			if (errno == EINTR)
				continue;
			return -1;
		}
	}

	*buffer = 0;
	return n;
}


/*  Write a line to a socket  */

ssize_t Writeline(int sockd, const void *vptr, size_t n) {
	size_t      nleft;
	ssize_t     nwritten;
	const char *buffer;

	buffer = vptr;
	nleft = n;

	while (nleft > 0) {
		if ((nwritten = write(sockd, buffer, nleft)) <= 0) {
			if (errno == EINTR)
				nwritten = 0;
			else
				return -1;
		}
		nleft -= nwritten;
		buffer += nwritten;
	}

	return n;
}

bool endofLine(unsigned chr) { return (int)chr == 0 || (int)chr == 1; }

bool detectNoNums(unsigned chr) { return chr == ","; }

bool getDataType(unsigned char chr) { return chr == DATAZERO || chr == DATAONE; }