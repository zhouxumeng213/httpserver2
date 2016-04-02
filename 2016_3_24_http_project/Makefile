ROOT_PATH=$(shell pwd)
CGI_PATH=$(ROOT_PATH)/cgi-bin
SERVER_BIN=httpd
CLIENT_BIN=demo_client

CC=gcc
FLAGS=#-D_DEBUG_
LDFLAGS=-lpthread

SERVER_SRC=httpd.c
CLIENT_SRC=demo_client.c

.PHONY:all
all:$(SERVER_BIN) $(CLIENT_BIN) cgi
$(SERVER_BIN):$(SERVER_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(LDFLAGS)
$(CLIENT_BIN):$(CLIENT_SRC)
	$(CC) -o $@ $^ $(FLAGS) $(LDFLAGS)
.PHONY:cgi
cgi:
	for name in `echo $(CGI_PATH)`;\
	do\
		cd $$name;\
	   	make;\
	   	cd -;\
	done
.PHONY:output
output:
	mkdir output
	cp httpd output
	cp demo_client output
	cp start.sh output
	cp -rf htdocs output
	cp -rf conf output
	cp -rf log output
	mkdir -p output/htdocs/cgi-bin
	for name in `echo $(CGI_PATH)`;\
	do\
		cd $$name;\
		make output;\
		cd -;\
	done
.PHONY:clean
clean:
	rm -rf $(SERVER_BIN) $(CLIENT_BIN) output
	for name in `echo $(CGI_PATH)`;\
	do\
		cd $$name;\
		make clean;\
		cd -;\
	done
