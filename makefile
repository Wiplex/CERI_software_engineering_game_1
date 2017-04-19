# Variables :
I="archives/io.a"

# Targets :
all:
	@make fj
	@make io
fj:
	@make -B objects/fonctionsjeu.o
	@make -B objects/fonctionsjeu_main.o
	@make -B fonctionsjeu.exe
io:
	@make -B objects/io.o
	@make -B objects/io_main.o
	@make io.a
	@make -B io_main.exe
objects/io.o: sources/io.cpp
	@g++ -c $< -o $@ -std=c++11
archives/io.a: objects/io.o
	@ar rvs $@ $<
objects/io_main.o: tests/io_main.cpp headers/io.h
	@g++ -c $< -o $@ -std=c++11
io_main.exe: objects/io_main.o objects/io.o
	@g++ $^ -o $@ -std=c++11
objects/fonctionsjeu.o:	sources/fonctionsjeu.cpp headers/fonctionsjeu.h
	@g++ -c $< -o $@ -std=c++11
objects/fonctionsjeu_main.o:	tests/fonctionsjeu_main.cpp headers/fonctionsjeu.h
	@g++ -c $< -o $@ -std=c++11
fonctionsjeu.exe: objects/fonctionsjeu.o objects/fonctionsjeu_main.o
	@g++ $^ $I -o $@ -std=c++11
