all: demo-connection

demo-connection: demo-connection.o 
	g++ -o demo-connection demo-connection.o -L/usr/lib -lmysqlcppconn
	
demo-connection.o: demo-connection.cpp
	g++ -c -I/usr/include/cppconn demo-connection.cpp

clean:
	rm -f *.o demo-connection