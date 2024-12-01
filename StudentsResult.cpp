#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float grade;

public:
    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
    void setRollNumber(int r) {
        rollNumber = r;
    }
    int getRollNumber() {
        return rollNumber;
    }
    void setGrade(float g) {
        grade = g;
    }
    float getGrade() {
        return grade;
    }
    bool Passed() {
        return grade >= 50;
    }
};

int main() {
    
    Student student1;
    student1.setName("Zain");
    student1.setRollNumber(28);
    student1.setGrade(72);

    cout << "Student Name: " << student1.getName() << "\n";
    cout << "Roll Number: " << student1.getRollNumber() << "\n";
    cout << "Grade: " << student1.getGrade() << "\n";
    if (student1.Passed()) {
        cout << "Result: Passed" << "\n";
    } else {
        cout << "Result: Failed" << "\n";
    }
}
