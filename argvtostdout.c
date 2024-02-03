#include <stddef.h>
#include <unistd.h>

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
	// for now, just dump the data onto stdout
	// no error checking...
	write(1, argv[1], (size_t)len);
	return 0;
}
