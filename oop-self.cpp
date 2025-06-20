#include <iostream>
#include <string>
using namespace std;

// ---------- STRUCTURE ----------
struct Date {
    int day, month, year;
};

// ---------- CATEGORY MANAGER CLASS ----------
class CategoryManager {
public:
    static void showCategories() {
        cout << "\nAvailable Categories: Food, Transport, Bills, Shopping, Other\n";
    }

    static bool isValidCategory(const string& cat) {
        return cat == "Food" || cat == "Transport" || cat == "Bills" || cat == "Shopping" || cat == "Other";
    }
};

// ---------- BUDGET CLASS ----------
class Budget {
private:
    double limit;
public:
    Budget(double l = 0) : limit(l) {}

    void setLimit(double l) {
        limit = l;
    }

    bool isOverBudget(double totalExpenses) const {
        return totalExpenses > limit;
    }

    double getLimit() const {
        return limit;
    }
};

// ---------- REPORT CLASS ----------
class Report {
public:
    static void generate(double income, double expenses, const Budget& b) {
        cout << "\n======= Monthly Financial Report =======\n";
        cout << "Total Income: PKR " << income << endl;
        cout << "Total Expenses: PKR " << expenses << endl;
        cout << "Remaining Balance: PKR " << (income - expenses) << endl;

        if (b.getLimit() > 0) {
            cout << "Budget Limit: PKR " << b.getLimit() << endl;
            cout << (b.isOverBudget(expenses) ? "?? You exceeded your budget!" : "? You are within your budget.") << endl;
        }

        cout << "=======================================\n";
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    double totalIncome = 0;
    double totalExpenses = 0;
    int n;

    Budget myBudget;
    double budgetLimit;

    cout << "******* FINANCE TRACKER ********" << endl;
    cout << "Enter your monthly budget limit (in PKR): ";
    cin >> budgetLimit;
    myBudget.setLimit(budgetLimit);

    // Income entry
    cout << "Enter your monthly salary: ";
    cin >> totalIncome;

    // Expense entries
    cout << "How many expenses do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double amt;
        string category, desc;
        Date d;

        cout << "\nEnter expense description: ";
        cin.ignore(); getline(cin, desc);
        cout << "Enter expense amount: ";
        cin >> amt;
        cout << "Enter date (dd mm yyyy): ";
        cin >> d.day >> d.month >> d.year;

        CategoryManager::showCategories();
        cout << "Enter category: ";
        cin.ignore(); getline(cin, category);

        if (!CategoryManager::isValidCategory(category)) {
            cout << "Invalid category! Setting to 'Other'\n";
            category = "Other";
        }

        cout << "[EXPENSE] PKR " << amt << " - " << desc << " [" << category << "] (" << d.day << "/" << d.month << "/" << d.year << ")\n";

        totalExpenses += amt;
    }

    // Generate Report
    Report::generate(totalIncome, totalExpenses, myBudget);

    return 0;
}

