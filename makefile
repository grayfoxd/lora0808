########
#######

OBJ = main.o serial.o serialtest.o jpgtolora.o
edit:$(OBJ)
	g++ -o sender $(OBJ) -pthread
main.o:main.cpp serialtest.h
	g++ -c main.cpp
serial.o: serial.cpp serial.h
	g++ -c serial.cpp
serialtest.o:serialtest.cpp serialtest.h /usr/include/pthread.h jpgtolora.h
	g++ -c serialtest.cpp -pthread
jpgtolora.o:jpgtolora.cpp /usr/include/c++/4.8.4/iostream /usr/include/c++/4.8.4/fstream
	g++ -c jpgtolora.cpp
clean:
	rm edit $(OBJ)
