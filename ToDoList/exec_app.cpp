#include "exec_app.h"

void exec_app::menu(sql::Connection* con) {
    this->con = con;
    while (true) {
        std::cout << "�������� ��������:\n"
            << "1. �������� ������\n"
            << "2. ����� �� ���������\n"
            << "3. �������� ��������� ��������\n"
            << "4. ������� ��� ���� �� �����";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            double amount;
            std::string date, description, category;

            std::cout << "������� ����� �������: ";
            std::cin >> amount;
            std::cout << "������� ���� (��.��.����): ";
            std::cin >> date;
            std::cin.ignore(); // ����� �������� ����� �� ������� ����� ������ ����� ����� ����
            std::cout << "������� �������� �������: ";
            std::getline(std::cin, description);
            // ������ �������� ������ �� ��������� �������
            std::cout << "������� ���������";
            std::cin >> category;
            manager.addExpenditure(Expenditure(amount, date, description, category), con);

            std::cout << "������ ������� ��������!\n";
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
