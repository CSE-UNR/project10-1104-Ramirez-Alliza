// Alliza Ramirez
// Lab 10

#include <stdio.h>

#define WORD_LEN 5
#define MAX_GUESSES 6

// get word from file
	void loadWord(char word[]) {
FILE *file = fopen("mystery.txt", "r");
fscanf(file, "%s", word);
fclose(file);
}

	// lowercase every letter
	void toLower(char word[]) {
	for (int i = 0; i < WORD_LEN; i++) {
	if (word[i] >= 'A' && word[i] <= 'Z') {
word[i] = word[i] + 32;
}
}
}

		// has enough characters and is in correct format
	int isValidGuess(char guess[]) {
	int i = 0;
	while (guess[i] != '\0') i++;
	if (i != WORD_LEN) return 0;

	for (int j = 0; j < WORD_LEN; j++) {
	char c = guess[j];
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
	return 0;
}
}
	return 1;
}

	
	int stringsEqual(char a[], char b[]) {
	for (int i = 0; i < WORD_LEN; i++) {
	if (a[i] != b[i]) return 0;
}
	return 1;
}


	void giveFeedback(char guess[], char mystery[], char feedback[], char pointer[]) {
	for (int i = 0; i < WORD_LEN; i++) {
feedback[i] = guess[i];
pointer[i] = ' ';
}


	for (int i = 0; i < WORD_LEN; i++) {
	if (guess[i] == mystery[i]) {
	if (feedback[i] >= 'a' && feedback[i] <= 'z') {
feedback[i] = feedback[i] - 32;
}
}
}


	for (int i = 0; i < WORD_LEN; i++) {
	if (guess[i] != mystery[i]) {
	for (int j = 0; j < WORD_LEN; j++) {
	if (guess[i] == mystery[j] && guess[j] != mystery[j]) {
pointer[i] = '^';
	break;
}
}
}
}

feedback[WORD_LEN] = '\0';
pointer[WORD_LEN] = '\0';
}


	void displayGuesses(char feedbacks[][WORD_LEN + 1], char pointers[][WORD_LEN + 1], int total) {
		for (int i = 0; i < total; i++) {
printf("%s\n", feedbacks[i]);
printf("%s\n", pointers[i]);
}
}


	int main() {
	char mystery[WORD_LEN + 1];
	char guess[WORD_LEN + 1];
	char feedbacks[MAX_GUESSES][WORD_LEN + 1];
	char pointers[MAX_GUESSES][WORD_LEN + 1];

loadWord(mystery);
toLower(mystery);

	int attempts = 0;
	while (attempts < MAX_GUESSES) {
printf("GUESS %d! Enter your guess: ", attempts + 1);
scanf("%s", guess);
toLower(guess);

	if (!isValidGuess(guess)) {
printf("Your guess must be 5 letters long.\n");
	continue;
}

giveFeedback(guess, mystery, feedbacks[attempts], pointers[attempts]);
displayGuesses(feedbacks, pointers, attempts + 1);

	if (stringsEqual(guess, mystery)) {
	printf("You won in %d guess%s!\n", attempts + 1, attempts == 0 ? "" : "es");
	return 0;
}

attempts++;
}

	printf("You lost. The word was: %s\n");
	return 0;
}


