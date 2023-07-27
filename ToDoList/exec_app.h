
#include "Manager.h"
#include "Expenditure.h"

class exec_app : public Manager
{
private :
    sql::Connection* con;
public:
    Manager manager;
    void menu(sql::Connection* con)
    {
        this->con = con;
        while (true) {
            std::cout << "�������� ��������:\n"
                << "1. �������� ������\n"
                << "2. ����������� ����� ����� ��������\n"
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
                manager.addExpenditure(Expenditure(amount, date, description, ExpenseCategory::Food), con);

                std::cout << "������ ������� ��������!\n";

            }
            else if (choice == 2) {
                double totalExpenses = manager.getTotalExpenditure();
                std::cout << "����� ����� ��������: " << totalExpenses << "\n";
            }
            else if (choice == 3) {
                manager.rollback(con);
            }
            else if (choice == 4) {
                manager.output_base(con);
            }
        }
    }
};
