final: solver.o run.o unit_test.o file_test.o main.o
	@g++ solver.o run.o unit_test.o file_test.o main.o -o final

solver.o: solver.cpp
	@g++ -c solver.cpp -o solver.o

run.o: run.cpp
	@g++ -c run.cpp -o run.o

unit_test.o: unit_test.cpp
	@g++ -c unit_test.cpp -o unit_test.o

file_test.o: file_test.cpp
	@g++ -c file_test.cpp -o file_test.o

main.o: main.cpp
	@g++ -c main.cpp -o main.o

