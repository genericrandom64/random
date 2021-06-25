#include "en-US.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int beginning = 1; // dont count argv[0], and sometimes argv[1]

const unsigned long hash(const char *str) {
	// djb2 from http://www.cse.yorku.ca/~oz/hash.html
	unsigned long hash = 5381;  
	int c;
	while ((c = *str++)) hash = ((hash << 5) + hash) + c;
	return hash;

}

void getlennospaces(int segs, char** vals) {

	int len = 0;
	for(int i = beginning; i < segs; i++) len += strlen(vals[i]); // strlen not accounting for spaces
	printf("%d\n", len);

}

void getlenwithspaces(int segs, char** vals) {

	int len = 0;
	for(int i = beginning; i < segs; i++) len += strlen(vals[i]) + 1; // strlen + 1 for spaces between
	/*
		jammy3662: what if they put two spaces in between arguments
		jammy3662: or more
		jammy3662: you wont be able to account for that
		genericrandom64: the shell cant handle that anyway
		jammy3662: it can
		jammy3662: i just ran it like that
		genericrandom64: but see
		genericrandom64: it saw the length as 3
		jammy3662: yeah
		jammy3662: so how are you going to account for the spaces in your program
		genericrandom64: i just add 1 to the length of each arg
		jammy3662: but i put more than one space
		genericrandom64: if they have 2 spaces the shell wont tell me anyway
		jammy3662: well my point is that you cant keep track of how many spaces are between the arguments
		jammy3662: but why do you want to anyway
		genericrandom64: its a program with the sole purpose of getting string length, so it should have that as an option if not by default
		jammy3662: but that option wouldnt work properly because it always just adds one space by default
		jammy3662: even if the user puts in several spaces between each argument
		genericrandom64: but the shell wont tell me if theres 2 anyway so its the best i can do
		jammy3662: ig */

	len--; // remove trailing space
	printf("%d\n", len);

}

void getlen(int segs, char** vals) {
	
	for(int i = beginning; i < segs; i++) printf("%d ", strlen(vals[i]));
	printf("\n");

}

int main(int argc, char *argv[]) {

	if(argc == 1) {
		// there are no arguments
		printf(usage); 
		exit(1);

	}

	switch(hash(argv[1])) {

		case 5861498: // -h
			printf(usage);
			exit(0);
			break;
	
		case 5861491: // -a
			beginning++;
			getlenwithspaces(argc, argv);
			exit(0);
			break;

		case 5861509: // -s
			beginning++;
			getlen(argc, argv);
			exit(0);
			break;

		case 5861510: // -t
			beginning++;
			getlennospaces(argc, argv);
			exit(0);
			break;

		}

	getlen(argc, argv); // default action
	return 0;

}

