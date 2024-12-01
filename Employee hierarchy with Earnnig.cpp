#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    float salary;

public:
    void setName(const string& n) {
        name = n;
    }
    string getName() const {
        return name;
    }
    void setSalary(float s) {
        salary = s;
    }
    float getSalary() {
        return salary;
    }

   float calculateEarnings() {
        return salary;
    }
};
class Manager : public Employee {
private:
    float bonus;

public:
    void setBonus(float b) {
        bonus = b;
    }
    float getBonus() {
        return bonus;
    }
    float calculateEarnings() {
        return salary + bonus;
    }
};
class Intern : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    void setHoursWorked(int hours) {
        hoursWorked = hours;
    }
    int getHoursWorked() {
        return hoursWorked;
    }
    void setHourlyRate(float rate) {
        hourlyRate = rate;
    }
    float getHourlyRate() {
        return hourlyRate;
    }
    float calculateEarnings() {
        return hoursWorked * hourlyRate;
    }
};

int main() {
 
    Manager manager;
    manager.setName("Zain Khan");
    manager.setSalary(9000);
    manager.setBonus(3000);

 
    Intern intern;
    intern.setName("Azfar");
    intern.setSalary(0); 
    intern.setHoursWorked(180);
    intern.setHourlyRate(12);

    cout << "Manager Details:\n";
    cout << "Name: " << manager.getName() << "\n";
    cout << "Base Salary: $" << manager.getSalary() << "\n";
    cout << "Bonus: $" << manager.getBonus() << "\n";
    cout << "Total Earnings: $" << manager.calculateEarnings() << "\n";
    
    cout << "\nIntern Details:\n";
    cout << "Name: " << intern.getName() << "\n";
    cout << "Hours Worked: " << intern.getHoursWorked() << "\n";
    cout << "Hourly Rate: $" << intern.getHourlyRate() << "\n";
    cout << "Total Earnings: $" << intern.calculateEarnings() << "\n";
}
