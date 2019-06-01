#include "server.h"
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>

server::server(int port):m_port(port){
	serv4.sin_family = AF_INET;
	serv4.sin_port = htons(m_port);
	serv4.sin_addr.s_addr = htonl(INADDR_ANY);
	m_fd = 0;
}

server::~server(){}

void server::s_bind(){
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	bind(m_fd, (SA *)&serv4, sizeof(SA4));
	listen(m_fd, 5);
}

int server::s_accept(){
	socklen_t cli_len = sizeof(SA4);
	return accept(m_fd, (SA *)&clie, &cli_len);
}

void server::doing(int fd, char *buf, int buf_len){
	while(1){
		char ip[128] = {'\0'};
		int r = read(fd, buf, buf_len);
		for(int i = 0; i < r; ++i){
			buf[i] = toupper(buf[i]);
		}
		write(fd, buf, r);
		std::cout << inet_ntop(AF_INET, &clie.sin_addr, ip, sizeof(ip)) << std::endl;
		if (strcmp(buf, "EXIT") == 0) break;
	}
}





