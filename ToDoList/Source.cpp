#include <iostream>
#include "exec_app.h" 

#include <stdlib.h>
#include <iostream>



const string server = "tcp://127.0.0.1:3306";
const string username = "root";
string password = "";

//use the std namespace
using namespace std;
int main() {
    setlocale(LC_ALL, "ru_RU");
    std::cout << "Введите пароль от БД";
    std::cin >> password;
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        sql::Statement* stmt = con->createStatement();
        stmt->execute("SET AUTOCOMMIT=OFF");
        delete stmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }


    con->setSchema("expernd");

    exec_app exec;
    exec.menu(con);
    delete pstmt;
    delete con;
    system("pause");
    return 0;
}
