main: main.o mytool1.o mytool2.o
	gcc -lstdc++ -o main main.o mytool1.o mytool2.o
	@echo by makefile ! 
main.o: main.cc 
	gcc -lstdc++ -c main.cc -o main.o 
mytool1.o: mytool1.cc 
	gcc -lstdc++ -c mytool1.cc -o mytool1.o 
mytool2.o: mytool2.cc 
	gcc -lstdc++ -c mytool2.cc -o mytool2.o 
clean:
	-rm main *.o *~
