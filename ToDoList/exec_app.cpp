#include "exec_app.h"

void exec_app::menu(sql::Connection* con) {
    this->con = con;
    while (true) {
        std::cout << "Выберите действие:\n"
            << "1. Добавить расход\n"
            << "2. Поиск по категории\n"
            << "3. Откатить последнее действие\n"
            << "4. Вывести всю базу на экран";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            double amount;
            std::string date, description, category;

            std::cout << "Введите сумму расхода: ";
            std::cin >> amount;
            std::cout << "Введите дату (ДД.ММ.ГГГГ): ";
            std::cin >> date;
            std::cin.ignore(); // Чтобы очистить буфер от символа новой строки после ввода даты
            std::cout << "Введите описание расхода: ";
            std::getline(std::cin, description);
            // Можете добавить запрос на категорию расхода
            std::cout << "Введите категорию";
            std::cin >> category;
            manager.addExpenditure(Expenditure(amount, date, description, category), con);

            std::cout << "Расход успешно добавлен!\n";
        }
        else if (choice == 2) {
            manager.category_output(con);
        }
        else if (choice == 3) {
            manager.rollback(con);
        }
        else if (choice == 4) {
            manager.output_base(con);
        }
    }
}
