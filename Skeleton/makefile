all: compile link clean

link:
	g++ -o bin/runHere bin/main.o bin/Order.o bin/Customer.o bin/Volunteer.o bin/Action.o bin/parse.o

compile:
	g++ -g -Wall -Weffc++ -c -o bin/Order.o src/Order.cpp
	
	g++ -g -Wall -Weffc++ -c -o bin/Volunteer.o src/Volunteer.cpp
	g++ -g -Wall -Weffc++ -c -o bin/Action.o src/Action.cpp
	g++ -g -Wall -Weffc++ -c -o bin/main.o src/main.cpp
	g++ -g -Wall -Weffc++ -c -o bin/Customer.o src/Customer.cpp



clean:
	rm -f bin/*


	