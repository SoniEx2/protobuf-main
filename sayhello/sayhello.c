#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include "hello_world.pb-c.h"

int main(int argc, char *argv[]) {
	// at least 2 args: program name and "end marker"
	if (argc < 2) {
		return 1;
	}
	// "end marker": the last argument must be empty, otherwise return an
	// error
	if (argv[argc-1][0]) {
		return 1;
	}
	// this is where things start to get a little cursed
	ptrdiff_t len = argv[argc-1] - argv[1];
	if (len > 0) {
		len--;
	}
	char *buf = argv[1];
	// grab the message
	Hello *message = hello__unpack(NULL, len, (uint8_t*)buf);
	if (!message) {
		return 1;
	}
	if (message->version) {
		printf("sayhello 0.1.0-experimental\n");
		return 0;
	}
	if (message->help) {
		// hmm #embed "hello_world.proto" when...
		printf("[NYI]\n");
		return 0;
	}
	// say hello
	printf("Hello, %s!\n", message->hello_target);
	// then get rid of it
	hello__free_unpacked(message, NULL);
	return 0;
}
