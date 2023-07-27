#ifndef EXEC_APP_H
#define EXEC_APP_H

#include "Manager.h"
#include "Expenditure.h"
#include <iostream>
#include <string>

class exec_app : public Manager {
private:
    sql::Connection* con;
public:
    Manager manager;
    void menu(sql::Connection* con);
};

#endif // EXEC_APP_H
