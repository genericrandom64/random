#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
// run this on your favorite files
int main(int argc, char **argv) {
	struct stat s;
	for(int i = 1; i < argc; i++) {
		stat(argv[i], &s);
		// Open heart surgery.
		int fd = open(argv[i], O_RDWR);
		// It failed.
		unsigned char *mem = mmap(NULL, s.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
		// Run.
		for(int x = 0; x < s.st_size; x++) {
			mem[x]--;
		}
		// They found me.
		munmap(mem, s.st_size);
		close(fd);
	}
	return 0;
}
