#include "tcpClientHelp.h"
#include "tcpClientHelp.c"



void main() {

	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("[+]Client Socket Created Sucessfully.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("[+]Connected to Server.\n");

	recv(clientSocket, buffer, 1024, 0);
	printf("[+]Data Recv: %s\n", buffer);
	printf("[+]Closing the connection.\n");

}