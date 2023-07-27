#include "manager.h"

void Manager::addExpenditure(const Expenditure& expenditure, sql::Connection* con) {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO expend (sum_, date_, description_, category_) VALUES (?, ?, ?, ?)"
        );
        pstmt->setInt(1, expenditure.getSum());
        pstmt->setString(2, expenditure.getDate());
        pstmt->setString(3, expenditure.getDescription());
        pstmt->setString(4, expenditure.getCategory());
        pstmt->execute();
        stmt->execute("COMMIT");
        delete stmt;
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        // Обработка исключения при возникновении ошибок с базой данных
        std::cout << "Ошибка при добавлении расхода в таблицу: " << e.what() << std::endl;
    }
}

void Manager::rollback(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("ROLLBACK");
    stmt->execute("COMMIT");
    delete stmt;
}

void Manager::output_base(sql::Connection* con) {
    try {
        // Выполнение запроса SELECT
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM expend");

        // Обработка результатов запроса
        while (res->next()) {
            // Используем методы get соответствующие типам столбцов
            float sum = res->getDouble("sum_");
            std::string date = res->getString("date_");
            std::string description = res->getString("description_");
            std::string category = res->getString("category_");

            std::cout << "Sum: " << sum << ", Date: " << date << ", Description: " << description << ", Category: " << category << std::endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cout << "Ошибка при выполнении запроса SELECT: " << e.what() << std::endl;
    }
}

void Manager::category_output(sql::Connection* con, string value) {
    
    try {
        // Подготовка запроса с плейсхолдером
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "SELECT * FROM expend WHERE category_ = ?"
        );

        // Установка значения переменной cat в плейсхолдер
        pstmt->setString(1, value);

        // Выполнение запроса
        sql::ResultSet* res = pstmt->executeQuery();

        // Обработка результатов запроса
        while (res->next()) {
            float sum = res->getDouble("sum_");
            std::string date = res->getString("date_");
            std::string description = res->getString("description_");
            std::string category = res->getString("category_");

            std::cout << "Sum: " << sum << ", Date: " << date << ", Description: " << description << ", Category: " << category << std::endl;
        }

        delete res;
        delete pstmt;

    }
    catch (sql::SQLException& e) {
        std::cout << "Ошибка при выполнении запроса SELECT: " << e.what() << std::endl;
    }
}

void Manager::deletebycategory(sql::Connection* con, string category, string value)
{

    try {
        std::string query = "DELETE FROM expend WHERE " + category + " = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, value);
        pstmt->execute(); // Выполняем запрос на удаление записей

        std::cout << "Записи успешно удалены." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cout << "Ошибка при выполнении запроса DELETE: " << e.what() << std::endl;
    }
}

void Manager::date_fillter(sql::Connection* con)
{

}