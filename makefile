all:
	@make -B objects/io.o
	@make -B objects/io_main.o
	@make -B io_main
objects/io.o: sources/io.cpp
	@g++ -c $< -o $@ -std=c++11
objects/io_main.o: tests/io_main.cpp headers/io.h
	@g++ -c $< -o $@ -std=c++11
io_main: objects/io_main.o objects/io.o
	@g++ objects/io_main.o objects/io.o -o $@ -std=c++11
