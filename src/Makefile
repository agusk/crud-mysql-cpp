all: demo-connection demo-create-data demo-read-data demo-update-data demo-delete-data

demo-connection: demo-connection.o 
	g++ -o demo-connection demo-connection.o -L/usr/lib -lmysqlcppconn
	
demo-connection.o: demo-connection.cpp
	g++ -c -I/usr/include/cppconn demo-connection.cpp

demo-create-data: demo-create-data.o 
	g++ -o demo-create-data demo-create-data.o -L/usr/lib -lmysqlcppconn
	
demo-create-data.o: demo-connection.cpp
	g++ -c -I/usr/include/cppconn demo-create-data.cpp

demo-read-data: demo-read-data.o 
	g++ -o demo-read-data demo-read-data.o -L/usr/lib -lmysqlcppconn
	
demo-read-data.o: demo-read-data.cpp
	g++ -c -I/usr/include/cppconn demo-read-data.cpp

demo-update-data: demo-update-data.o 
	g++ -o demo-update-data demo-update-data.o -L/usr/lib -lmysqlcppconn
	
demo-update-data.o: demo-update-data.cpp
	g++ -c -I/usr/include/cppconn demo-update-data.cpp

demo-delete-data: demo-delete-data.o 
	g++ -o demo-delete-data demo-delete-data.o -L/usr/lib -lmysqlcppconn
	
demo-delete-data.o: demo-delete-data.cpp
	g++ -c -I/usr/include/cppconn demo-delete-data.cpp

clean:
	rm -f *.o demo-connection demo-create-data demo-read-data demo-update-data demo-delete-data