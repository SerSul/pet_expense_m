#include <iostream>
#include <string>
#include <vector>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>



#ifndef EXPENDITURE_H
#define EXPENDITURE_H

using namespace std;


class Expenditure
{
private:
    int sum;
    string date, description;
    string category;

public:

    Expenditure(int sum, const string& date, const string& description, const string& category);



    int getSum() const;
    string getDate() const;
    string getDescription() const;
    string getCategory() const;

};

#endif // EXPENDITURE_H
