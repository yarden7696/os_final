CXX=gcc


all: q1

server: server.c 
	$(CXX) server.c -o server
client: client.c 
	$(CXX) client.c -o client

.PHONY: clean

clean:
	rm -f *.o client server