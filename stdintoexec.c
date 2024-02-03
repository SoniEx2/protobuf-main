#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}
	char *buf = malloc(8192);
	size_t bufsize = 8192;
	size_t pos = 0;
	ssize_t status;
	// this is how you read some stuff from stdin yeah?
	while ((status = read(0, buf + pos, bufsize - pos)) > 0) {
		pos += (size_t)status;
		if (pos > bufsize/2) {
			// no overflow check but eh.
			char *realloced = realloc(buf, bufsize * 2);
			if (!realloced && pos == bufsize) {
				return 1;
			}
			buf = realloced;
			bufsize = bufsize * 2;
		}
	}
	//fprintf(stderr, "Read %zu bytes\n", pos);
	if (status != 0) {
		return 1;
	}
	// and that was the easy part.
	if (pos > bufsize - 2) {
		buf = realloc(buf, bufsize + 2);
		if (!buf) {
			return 1;
		}
	}
	buf[pos++] = '\0'; // pass it off as a string
	buf[pos++] = '\0'; // additional "end marker"
	size_t count = 2; // program name + NULL pointer
	for (size_t i = 0; i < pos; i++) {
		count += buf[i] == '\0'; // count NULs
	}
	//fprintf(stderr, "Will have %zu entries\n", count);
	char **arguments = calloc(count, sizeof(char *));
	arguments[0] = argv[1];
	arguments[count-1] = NULL;
	size_t argpos = 1;
	char *nextarg = buf;
	for (size_t i = 0; i < pos; i++) {
		if (buf[i] == '\0') {
			arguments[argpos++] = nextarg;
			nextarg = buf+i+1; // may be just past the end
		}
	}
	execvp(argv[1], arguments);
}
