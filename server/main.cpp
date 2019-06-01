#include "server.h"
#include <unistd.h>

int main()
{	
	server serv;
	char buf[128] = {0};
	int c_fd = 0;
	serv.s_bind();
	while(1){
		c_fd = serv.s_accept();
		serv.doing(c_fd, buf, sizeof(buf));	
		close(c_fd);
	}
	return 0;
}
