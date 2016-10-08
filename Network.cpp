#include "stdafx.h"
#include "Network.h"
#include "Player.h"

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define BUFLEN 512
#define PORT 27015

Network::Network()
{
	_socket = CreateSocket();
}

Network::~Network()
{
	closesocket(_socket);
	WSACleanup();
}

SOCKET Network::CreateSocket() {
	SOCKET s;
	struct sockaddr_in server;
	char buf[BUFLEN];
	char ibuf[BUFLEN];
	WSADATA wsa;


	//initialize winsock
	printf_s("Initializing Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("WSA FAILED");
		exit(EXIT_FAILURE);
	}
	printf("Initialized");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket");
	}
	printf("Socket Created\n");

	//setup server struct
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	//bind
	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Bind done\n");

	printf("Waiting for first player...\n");

	return s;
}

string Network::Receive() {
	char buf[BUFLEN];
	int recv_len;

	recv_len = recv(_socket, buf, BUFLEN, 0);
	buf[recv_len] = '\0';

	return string(buf);
}

string Network::Receive(sockaddr_in& paramSi) {
	char buf[BUFLEN];
	int recv_len = 0;
	int slen = sizeof(paramSi);

	buf[0] = '\0';

	recv_len = recvfrom(_socket, buf, BUFLEN, 0, (struct sockaddr*)&paramSi, &slen);
	buf[recv_len] = '\0';

	return string(buf);
}