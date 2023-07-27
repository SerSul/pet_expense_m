#ifndef MANAGER_H
#define MANAGER_H

#include "Expenditure.h"
#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

class Manager : public Expenditure {
private:

public:
    Manager() : Expenditure(0, "", "", "") {}

    void addExpenditure(const Expenditure& expenditure, sql::Connection* con);
    void rollback(sql::Connection* con);
    void output_base(sql::Connection* con);
    void category_output(sql::Connection* con, string value);
    void date_fillter(sql::Connection* con);
    void deletebycategory(sql::Connection* con, string category, string value);
};

#endif // MANAGER_H
