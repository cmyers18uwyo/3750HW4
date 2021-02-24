#################################
#Makefile
#Charles Myers
#COSC 3750 Spring 2021
#Homework 4
#February 23, 2021
#
#This file will compile the wycat file for HW4
##################################
CC=gcc
CFLAGS=-ggdb -Wall
RM=/bin/rm -f
#tidy and clean are not files
.PHONY : tidy clean
#wycat will use the wycat.c file and create an executable called wycat
wycat : wycat.c
	$(CC) $(CFLAGS) -o wycat wycat.c
#tidy will remove any object files in the directory
tidy :
	$(RM) *.o
#clean will run tidy and remove the executable wycat
clean : tidy
	$(RM) wycat