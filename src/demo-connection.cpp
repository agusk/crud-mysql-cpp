#include <stdlib.h>
#include <iostream>

#include <mysql_connection.h>
#include <driver.h>
#include <cppconn/exception.h>

using namespace std;
using namespace sql;
int main(void)
{  
  try {
    sql::Driver *driver;
    sql::Connection *con;
    
    cout << "connecting to mysql server....";
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "user", "password");  
    cout << "connected" << endl;

    delete con;

  } catch (sql::SQLException &e) {    
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  cout << endl;

  return EXIT_SUCCESS;
}