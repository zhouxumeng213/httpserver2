#include"demo_client.h"
void usage(const char* proc)
{
	printf("Usage:%s [IP] [PORT]\n",proc);
}
int main(int argc,char* argv[])
{
	if(argc!=3){
		usage(argv[0]);
		exit(1);
	}
	const char* ip=argv[1];
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1){
		printf("%d : %s\n",errno,strerror(errno));
		exit(1);
	}
	unsigned short port=atoi(argv[2]);
	struct sockaddr_in remote;
	remote.sin_family=AF_INET;
	remote.sin_port=htons(port);
	inet_aton(ip,&remote.sin_addr);
	int ret=connect(sock,(struct sockaddr*)&remote,sizeof(remote));
	if(ret<0){
		perror("connect");
		exit(1);
	}
	char buf[1024];
	memset(buf,'\0',sizeof(buf));
	while(1){
		size_t ret=read(0,buf,sizeof(buf)-1);
		if(ret<0){
			perror("read");
			break;
		}
		buf[ret]='\0';
		ssize_t _size=write(sock,buf,strlen(buf));
		if(_size<0){
			perror("write");
			break;
		}
	}
	close(sock);
	return 0;

}
