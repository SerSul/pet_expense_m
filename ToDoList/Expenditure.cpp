#include "expenditure.h"

Expenditure::Expenditure(int sum, const string& date, const string& description, ExpenseCategory category)
    : sum(sum), date(date), description(description), category(category) {}


int Expenditure::getSum() const {
    return sum;
}

string Expenditure::getDate() const {
    return date;
}

string Expenditure::getDescription() const {
    return description;
}

ExpenseCategory Expenditure::getCategory() const {
    return category;
}
