#include <string>
#include <iostream>
using namespace std;

class LoanHandler{
protected:
    LoanHandler* successor;
public:
    virtual void processLoan(int amount) = 0;
    virtual ~ LoanHandler(){}
    LoanHandler* setSuccessor(LoanHandler* _successor) {
        successor = _successor;
        return successor;
    }
};

class Cashier : public LoanHandler {
public:
    void processLoan(int amount) {
        if (amount <= 10000) {
            cout << "Кассир схвалив кредит на суму " << amount << endl;
        }
        else if (successor != nullptr) {
            successor->processLoan(amount);
        }
    }
};

class Manager : public LoanHandler {
public:
    void processLoan(int amount) {
        if (amount>10000 && amount <= 150000) {
            cout << "Менеджер схвалив кредит на суму " << amount << endl;
        }
        else if (successor != nullptr) {
            successor->processLoan(amount);
        }
    }
};

class Director : public LoanHandler {
public:
    void processLoan(int amount) {
        if (amount > 150000) {
            cout << "Директор банку схвалив кредит на суму " << amount << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian_Ukraine.1251");

    Cashier cashier;
    Manager manager;
    Director director;

    cashier.setSuccessor(&manager);
    manager.setSuccessor(&director);
    cashier.processLoan(100000);

    return 0;
}

