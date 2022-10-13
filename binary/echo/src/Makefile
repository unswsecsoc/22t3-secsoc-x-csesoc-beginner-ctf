CC = gcc
CFLAGS = -no-pie -fno-stack-protector -z execstack

main: echo.o
	$(CC) $(CFLAGS) -o main echo.o
