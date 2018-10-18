#include "tcpClientHelp.h"           

int main(int argc, char *argv[]) {

	int       conn_s;                
	short int port;                  
	struct    sockaddr_in servaddr;  
	char      buffer[MAX_LINE];      
	char     *szAddress;             
	char     *szPort;                
	char     *endptr;                

	ParseCmdLine(argc, argv, &szAddress, &szPort);

	port = strtol(szPort, &endptr, 0);
	if (*endptr) {
		printf("ECHOCLNT: Invalid port supplied.\n");
		exit(EXIT_FAILURE);
	}
	if ((conn_s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "ECHOCLNT: Error creating listening socket.\n");
		exit(EXIT_FAILURE);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);

	if (inet_aton(szAddress, &servaddr.sin_addr) <= 0) {
		printf("ECHOCLNT: Invalid remote IP address.\n");
		exit(EXIT_FAILURE);
	}

	if (connect(conn_s, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		printf("ECHOCLNT: Error calling connect()\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the string to echo: ");
	fgets(buffer, MAX_LINE, stdin);

	Writeline(conn_s, buffer, strlen(buffer));
	Readline(conn_s, buffer, MAX_LINE - 1);

	printf("Echo response: %s\n", buffer);

	return EXIT_SUCCESS;
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
