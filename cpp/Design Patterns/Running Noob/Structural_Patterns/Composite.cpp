#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
private:
    std::string name;
    std::string dept;
    int salary;
    std::vector<Employee*> subordinates;

public:
    Employee(const std::string& name, const std::string& dept, int salary)
        : name(name), dept(dept), salary(salary), subordinates() {}

    void add(Employee* e) {
        subordinates.push_back(e);
    }

    void remove(Employee* e) {
        auto it = std::find(subordinates.begin(), subordinates.end(), e);
        if (it != subordinates.end()) {
            subordinates.erase(it);
        }
    }

    const std::vector<Employee*>& getSubordinates() {
        return subordinates;
    }

    std::string toString() const {
        return "Employee: [ Name: " + name + ", dept: " + dept + ", salary: " + std::to_string(salary) + " ]";
    }
};

int main() {
    Employee* CEO = new Employee("John", "CEO", 30000);

    Employee* headSales = new Employee("Robert", "Head Sales", 20000);

    Employee* headMarketing = new Employee("Michel", "Head Marketing", 20000);

    Employee* clerk1 = new Employee("Laura", "Marketing", 10000);
    Employee* clerk2 = new Employee("Bob", "Marketing", 10000);

    Employee* salesExecutive1 = new Employee("Richard", "Sales", 10000);
    Employee* salesExecutive2 = new Employee("Rob", "Sales", 10000);

    CEO->add(headSales);
    CEO->add(headMarketing);

    headSales->add(salesExecutive1);
    headSales->add(salesExecutive2);

    headMarketing->add(clerk1);
    headMarketing->add(clerk2);

    //打印该组织的所有员工
    std::cout << CEO->toString() << std::endl;
    for (const auto& headEmployee : CEO->getSubordinates()) {
        std::cout << headEmployee->toString() << std::endl;
        for (const auto& employee : headEmployee->getSubordinates()) {
            std::cout << employee->toString() << std::endl;
        }
    }

    // 释放内存
    delete salesExecutive1;
    delete salesExecutive2;
    delete clerk1;
    delete clerk2;
    delete headSales;
    delete headMarketing;
    delete CEO;

    return 0;
}