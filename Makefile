run: main
	./$^ $(FILENAME) $(N)

main: main.cpp
	g++ -std=c++2a -Wall -o $@ $^