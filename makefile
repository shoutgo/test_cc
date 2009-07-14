#CC = gcc -g -masm=intel
CC = gcc -g -pg

main: main.o mytool1.o mytool2.o
	$(CC) -lstdc++ -o main main.o mytool1.o mytool2.o
	@echo by makefile ! 
main.o: main.cc 
	$(CC) -lstdc++ -c main.cc -o main.o 
mytool1.o: mytool1.cc 
	$(CC) -lstdc++ -c mytool1.cc -o mytool1.o 
mytool2.o: mytool2.cc 
	$(CC) -lstdc++ -c mytool2.cc -o mytool2.o 
clean:
	-rm main *.o *.d *~
