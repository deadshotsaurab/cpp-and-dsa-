#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int employee_id;
    double salary;

public:
    // Constructor
    Employee(const std::string& name, int id, double salary)
        : name(name), employee_id(id), salary(salary) {}

    // Virtual function to be overridden by derived classes
    virtual void performDuties() const {
        std::cout << name << " is performing general employee duties.\n";
    }

    virtual ~Employee() = default; // Virtual destructor for cleanup
};

// Manager class inheriting from Employee
class Manager : public Employee {
public:
    // Constructor
    Manager(const std::string& name, int id, double salary)
        : Employee(name, id, salary) {}

    // Overridden function to perform Manager-specific duties
    void performDuties() const override {
        std::cout << name << " is performing managerial duties.\n";
    }
};

// Engineer class inheriting from Employee
class Engineer : public Employee {
private:
    std::string specialization;

public:
    // Constructor
    Engineer(const std::string& name, int id, double salary, const std::string& spec)
        : Employee(name, id, salary), specialization(spec) {}

    // Overridden function to perform Engineer-specific duties
    void performDuties() const override {
        std::cout << name << " is performing engineering duties in " << specialization << ".\n";
    }
};

// Function to create either a Manager or Engineer based on user input
void createEmployee() {
    std::string name;
    int id;
    double salary;
    int choice;

    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);
    std::cout << "Enter employee ID: ";
    std::cin >> id;
    std::cout << "Enter salary: ";
    std::cin >> salary;

    std::cout << "\nChoose Employee Type:\n1. Manager\n2. Engineer\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;
    std::cin.ignore();  // Clear newline character from input buffer

    Employee* employee = NULL;  // Pointer to base class

    if (choice == 1) {
        employee = new Manager(name, id, salary);
    } else if (choice == 2) {
        std::string specialization;
        std::cout << "Enter Engineer's specialization: ";
        std::getline(std::cin, specialization);
        employee = new Engineer(name, id, salary, specialization);
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }

    // Perform duties based on employee type
    employee->performDuties();

    // Clean up
    delete employee;
}

int main() {
    createEmployee();
    return 0;
}

