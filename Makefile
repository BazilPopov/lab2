all:
	rm -rf *.o hello
	g++ main.cpp -o hello
	./hello
