CC = gcc
CCW64 = x86_64-w64-mingw32-gcc
CCW32 = i686-w64-mingw32-gcc

	
proccode : main.c fileop.h addstr.h
	${CC} -g -o proccode main.c

proccode32 :  main.c fileop.h addstr.h
	${CC} -m32 -g -o proccode32 main.c
	
winnative : main.c fileop.h addstr.h
	${CC} -g -o proccodenative.exe main.c -mconsole
	
	
clean :
	rm proccode

win64 :
	${CCW64} -g -o proccode64.exe main.c -mconsole
	
win32 :
	${CCW32} -g -o proccode32.exe main.c -mconsole

every1 : win64 win32 proccode proccode32
