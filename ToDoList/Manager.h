#include "Expenditure.h"

class Manager : public Expenditure {
private:
    std::vector<Expenditure> expenditures;

public:



    Manager() : Expenditure(0, "", "", ExpenseCategory::Other) {}




    void addExpenditure(const Expenditure& expenditure, sql::Connection* con) {
        expenditures.push_back(expenditure);

        try {
            sql::Statement* stmt = con->createStatement();
            sql::PreparedStatement* pstmt = con->prepareStatement(
                "INSERT INTO expend (sum_, date_, description_, category_) VALUES (?, ?, ?, ?)"
            );
            pstmt->setInt(1, expenditure.getSum());
            pstmt->setString(2, expenditure.getDate());
            pstmt->setString(3, expenditure.getDescription());
            pstmt->setString(4, "Food");
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

    int getTotalExpenditure() const {
        int total = 0;
        for (const Expenditure& expenditure : expenditures) {
            total += expenditure.getSum();
        }
        return total;
    }


    std::vector<Expenditure> getAllExpeditures() const {
        return expenditures;
    }

    void rollback(sql::Connection* con)
    {
        sql::Statement* stmt = con->createStatement();
        stmt->execute("ROLLBACK");
        stmt->execute("COMMIT");
        delete stmt;
    }

    void output_base(sql::Connection* con)
    {
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

};
