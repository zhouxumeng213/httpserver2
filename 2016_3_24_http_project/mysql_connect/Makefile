ROOT PATH=$(shell pwd)
INCLUDE=-I$(ROOT PATH)/mysql_lib/include
LIB PATH=-L$(ROOT PATH)/mysql_lib/lib
LDFLAGS=-lmysqlclient
mysql_connect:mysql_connect.cpp
	g++ -o $@ $^ $(INCLUDE) $(LIB PATH) $(LDFLAGS) -D_DEBUG_
.PHONY:clean
clean:
	rm -rf mysql_connect
