#include "exec_app.h"

void exec_app::menu(sql::Connection* con) {
    this->con = con;
    while (true) {
        std::cout << "�������� ��������:\n"
            << "1. �������� ������\n"
            << "2. ����� �� ���������\n"
            << "3. �������� ��������� ��������\n"
            << "4. ������� �� ���������\n"
            << "5. ������� ��� ���� �� �����\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            double amount;
            std::string date, description, category;

            std::cout << "������� ����� �������: ";
            std::cin >> amount;
            std::cout << "������� ���� (����.��.��): ";
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
            std::cout << "�� ����� ��������� ������� �����?";
            std::string value;
            std::cin >> value;
            manager.category_output(con, value);
        }
        else if (choice == 3) {
            manager.rollback(con);
        }
        else if (choice == 4) {
            std::cout << "�� ����� ��������� ������� �����?";
            std::string category;
            std::cin >> category;
            std::cout << "��������?";
            std::string value;
            std::cin >> value;
            manager.deletebycategory(con, category, value);
        }
        else if (choice == 5) {
            manager.output_base(con);
        }
    }
}
  