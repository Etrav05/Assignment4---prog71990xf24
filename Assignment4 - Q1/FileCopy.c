#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// EvanT - prog71990xf24 - assignment 4 - Q1

int main(int argc, char* argv[]) {
	char* text = "THIS is UPPERCASE?";		 // initalize key variables
	int textLen = strlen(text);
	char buffer[25];

	FILE* originalfp = fopen(argv[1], "w");  // open/create originalfp file
	if (originalfp == NULL) {				 // print errors
		perror("Error writing to originalfp");
		return 1;
		}
	fprintf(originalfp, "%s", text);		 // write to file
	fclose(originalfp);						 // close originalfp file

	originalfp = fopen(argv[1], "r");		 // reopen orginalfp file as read
	if (originalfp == NULL) {
		perror("Error reading file");
		return 1;
	}

	FILE* copyfp = fopen(argv[2], "w");		 // open/create copyfp file
	if (copyfp == NULL) {   
		perror("Error writing to originalfp");
		return 1;
	}

	fread(buffer, sizeof(char), textLen, originalfp); // read contents into the buffer 
	buffer[textLen] = '\0';                 // set a null terminator to make sure the function hands strings properly 

	for (int i = 0; i < textLen; i++) {		// for each char in text, set it to lower case and append to buffer
		buffer[i] = tolower(buffer[i]);
	}

	fprintf(copyfp, "%s", buffer);		    // write this new lowercase buffer of originalfp to copyfp

	fclose(originalfp);					    // close files when finished
	fclose(copyfp);
	return 0;
}