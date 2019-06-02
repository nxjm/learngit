#ifndef _SERVER_H__
#define _SERVER_H__
#include "s_net.h"
#include <iostream>

class server{
public:
	server(int port = 7777);
	~server();
	void s_bind();
	int s_accept();
	void doing(int fd, char *buf, int buf_len);
	const int getfd();
private:
	int m_fd;
	int m_port;
	SA4 serv4;
	SA4 clie;
};

#endif
