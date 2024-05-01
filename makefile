CC = gcc
CC32 = gcc

	
proccode : main.c fileop.h addstr.h
	${CC} -g -o proccode main.c
	
clean :
	rm proccode

win32 :
	${CC32} -g -o proccode.exe main.c
