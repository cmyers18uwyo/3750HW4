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
int main(int argc, char* argv[]) {
//Check to see if we have any arguments
FILE *infile;
char buffer[1024];
	if(argc > 1) {
		for(int i = 1; argv[i] != NULL; i++) {
			if(argv[i] == '-') {
				
			}
			else {
				infile=fopen(argv[i]);
				if(infile == NULL) {
					perror(argv[i]);
				}
				else {
					fread(buffer, sizeof(char), 10, infile);
					printf("%s\n", buffer);
					fclose(infile);
				}
			
			}
		}
	
	}

}
