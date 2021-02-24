/*
* wycat.c
* Charles Myers
* COSC 3750 Spring 2021
* Homework 4
* February 23, 2021
*
* This file is our version of cat
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(int argc, char* argv[]) {
//Declare vars for our file and buffer
FILE *infile;
char buffer[4096];
int size;
//Check to see if we have any arguments
	if(argc > 1) {
		//iterate through our arguments
		for(int i = 1; argv[i] != NULL; i++) {
			//If an argument is - then copy the users standard input
			//to standard output
			if(strcmp(argv[i], "-") == 0) {
				while(fread(buffer, sizeof(char), 4, stdin) == 4) {
						fwrite(buffer,sizeof(char), 4, stdout);
					}
			}
			else {
				//Try to open the file from the arguments
				infile=fopen(argv[i], "r");
				//If its not a file return an error, but dont stop the program
				if(infile == NULL) {
					perror(argv[i]);
				}
				else {
					//Read the data from the file then copy it to standard output
					while(fread(buffer, sizeof(char), 4, infile) == 4) {
						fwrite(buffer,sizeof(char), 4, stdout);
					}
					fclose(infile);
				}
			
			}
		}
	
	}
	else {
		while(fread(buffer, sizeof(char), 4, stdin) == 4) {
			fwrite(buffer,sizeof(char), 4, stdout);
		}
		
	}
}
