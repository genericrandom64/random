#include <stdlib.h>
#include <stdio.h>
#define CANDIDATES 2
// rewrite of a program made by a friend
int main() {

	int vote;
	char res;

	// arrays of arrays of chars
	// this lets us iterate over entire strings
	char* cands[] = {"Boberino", "Giraffe Man"};
	char* parties[] = {"Purge Party", "Communist Party"};

	// lets us store votes as array indexed the same way as the above char**s
	int votes[] = {0, 0};

	scan: // label is shorter than new function and isnt infinitely recursive
	printf("Choose a party to vote for.\n");
	for(int i = 0; i < CANDIDATES; i++) printf("%i. %s - %s\n", i+1, cands[i], parties[i]);

	scanf("%i", &vote);

	if(vote > CANDIDATES || vote <= 0) {
		printf("Invalid vote!\n");
		goto scan;
	}

	votes[vote-1]++;
	
	printf("Do you want to see the results of this godforsaken election? (Y/N) ");
	
	// leading space required for some reason
	scanf(" %c", &res);
	if(res == 'Y' || res == 'y') for(int i = 0; i < CANDIDATES; i++) printf("%s - %i vote(s)\n", cands[i], votes[i]);

	printf("Do you want to leave? (Y/N) ");
	scanf(" %c", &res);
	if(res == 'Y' || res == 'y') exit(0);

	goto scan;

}
