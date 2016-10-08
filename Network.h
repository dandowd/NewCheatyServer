#pragma once

#ifndef NETWORK_H
#define NETWORK_H

#include "stdafx.h"

class Network
{

public:
	std::string Network::Receive();
	std::string Network::Receive(sockaddr_in&);

	Network();
	~Network();

private:
	SOCKET _socket;
	SOCKET Network::CreateSocket();
};

#endif // !NETWORK_H

