#include "tcpClientHelp.h"

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
int ParseCmdLine(int argc, char *argv[], char **szAddress, char **szPort) {

	int n = 1;

	while (n < argc) {
		if (!strncmp(argv[n], "-a", 2) || !strncmp(argv[n], "-A", 2)) {
			*szAddress = argv[++n];
		}
		else if (!strncmp(argv[n], "-p", 2) || !strncmp(argv[n], "-P", 2)) {
			*szPort = argv[++n];
		}
		else if (!strncmp(argv[n], "-h", 2) || !strncmp(argv[n], "-H", 2)) {
			printf("Usage:\n\n");
			printf("    timeclnt -a (remote IP) -p (remote port)\n\n");
			exit(EXIT_SUCCESS);
		}
		++n;
	}

	return 0;
}


