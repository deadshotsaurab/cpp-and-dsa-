#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;

    Employee(const string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    virtual void performDuties() {
        cout << name << " is doing general work.\n";
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    Manager(const string& name, int id, double salary)
        : Employee(name, id, salary) {}

    void performDuties() override {
        cout << name << " is managing the team.\n";
    }
};

class Engineer : public Employee {
public:
    Engineer(const string& name, int id, double salary)
        : Employee(name, id, salary) {}

    void performDuties() override {
        cout << name << " is building and coding stuff.\n";
    }
};

int main() {
    string name;
    int id;
    double salary;
    int choice;

    cout << "Hi! Let's create an employee.\n";
    cout << "What's the employee's name? ";
    getline(cin, name);

    cout << "What's the employee's ID? ";
    cin >> id;

    cout << "How much does the employee earn? ";
    cin >> salary;

    cout << "Is this employee a Manager or Engineer?\n";
    cout << "Enter 1 for Manager or 2 for Engineer: ";
    cin >> choice;

    if (choice == 1) {
        Manager manager(name, id, salary);
        manager.performDuties();
    } else if (choice == 2) {
        Engineer engineer(name, id, salary);
        engineer.performDuties();
    } else {
        cout << "Invalid choice. Please enter 1 or 2 next time.\n";
    }

    return 0;
}
