objects/io.o: headers/io.h sources/io.cpp
	@g++ -c $< -o $@ -std=c++11
