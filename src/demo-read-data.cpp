#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <mysql_connection.h>
#include <driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;
using namespace sql;
int main(void)
{  
  try {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    
    cout << "connecting to mysql server....";
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "user", "password");   
    cout << "connected" << endl;
    
    con->setSchema("mydatabase");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM product");
    
    cout << "list of data:" << endl;
    while(res->next()) {
     
      cout << "id: " << res->getInt(1) << endl;
      cout << "name: " << res->getString(2) << endl;
      cout << "price: " << res->getDouble(3) << endl;
      cout << "created: " << res->getString(4) << endl;
      
    }
    

    delete res;
    delete stmt;
    delete con;

  } catch (sql::SQLException &e) {    
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  cout << endl;

  return EXIT_SUCCESS;
}