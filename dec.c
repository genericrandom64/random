#include <stdio.h>
// decodes messages expressed as groups of three numbers
int main(int argc, char **argv) {
	int r = 0;
	for(int i = 1; i < argc; i++) {
		for(int b = 0; b < 3; b++) r += argv[i][b] - 48;
		printf("%i ", r);
		r = 0;
	}
	printf("\n");
	for(int i = 1; i < argc; i++) {
		for(int b = 0; b < 3; b++) r += argv[i][b] - 48;
		printf("%c", r+0x61);
		r = 0;
	}
	printf("\n");
}
