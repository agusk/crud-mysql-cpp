#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <mysql_connection.h>
#include <driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;
int main(void)
{  
  try {
    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *prep_stmt;
    
    cout << "connecting to mysql server....";
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "user", "password");  
    cout << "connected" << endl;
    
    con->setSchema("mydatabase");
    prep_stmt = con->prepareStatement("INSERT INTO product(name,price,created) VALUES(?,?,NOW())");
    
    int i = 0;
    char name[10];
    float price;
    
    cout << "inserting 10 data....";
    for(i=1;i<=10;i++) {
     
      sprintf(name,"product-%d",i);
      price = 0.23*i;      
      
      prep_stmt->setString(1,name);
      prep_stmt->setDouble(2,price);
      
      prep_stmt->execute();
      
    }
    cout << "done" << endl;
    

    delete prep_stmt;
    delete con;

  } catch (sql::SQLException &e) {    
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  cout << endl;

  return EXIT_SUCCESS;
}