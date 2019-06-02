#include "server.h"
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handle(int n){
	wait(NULL);
}

int main()
{	
	server serv;
	char buf[128] = {0};
	int c_fd = 0;

	signal(SIGCHLD, handle);
	serv.s_bind();
	while(1){
		c_fd = serv.s_accept();
		pid_t pid = fork();
		if (pid == 0){
			close(serv.getfd());
			serv.doing(c_fd, buf, sizeof(buf));	
			close(c_fd);
			exit(0);
		}else{
			close(c_fd);
		}
	}
	return 0;
}
