CC = gcc

CFLAGS = -Iinclude
LDFLAGS = -Llib -lanimate

all: server client

server: animate_server.c
	$(CC) $< $(CFLAGS) $(LDFLAGS) -o server

client: animate_client.c
	$(CC) $< $(CFLAGS) $(LDFLAGS) -o client

clean:
	rm -f server client