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
#include <string. h>
int main(int argc, char* argv[]) {
//Check to see if we have any arguments
FILE *infile;
char buffer[4096];
	if(argc > 1) {
		for(int i = 1; argv[i] != NULL; i++) {
			if(strcmp(argv[i], "-") == 0) {
				
			}
			else {
				infile=fopen(argv[i], "r");
				if(infile == NULL) {
					perror(argv[i]);
				}
				else {
					
					while(fread(buffer, sizeof(char), 4, infile) == 4) {
						printf("%s\n", buffer);
					}
					fclose(infile);
				}
			
			}
		}
	
	}

}
