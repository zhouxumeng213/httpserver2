#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/sendfile.h>
#include<ctype.h>
#include<fcntl.h>

#define _BACK_LOG_ 5
#define _BLOCK_SIZE_ 2048
#define MAIN_PAGE "index.html"
