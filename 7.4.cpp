#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
public:
    string name, id, address, phone, email;
    Person(string n, string i, string addr, string ph, string em)
        : name(n), id(i), address(addr), phone(ph), email(em) {}
    virtual void displayInfo() {
        cout << "ID: " << id << " | Name: " << name << endl;
        cout << "Contact: " << phone << " | Email: " << email << endl;
        cout << "Address: " << address << endl;
    }
};
class Student : public Person {
public:
    int enrollmentYear;
    double gpa;
    vector<string> coursesEnrolled;
    Student(string n, string i, string addr, string ph, string em, int year, double avg)
        : Person(n, i, addr, ph, em), enrollmentYear(year), gpa(avg) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrolled Since: " << enrollmentYear << " | Current GPA: " << gpa << endl;
    }
};
class Professor : public Person {
public:
    string department;
    double salary;
    Professor(string n, string i, string addr, string ph, string em, string dept, double pay)
        : Person(n, i, addr, ph, em), department(dept), salary(pay) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Faculty Salary: $" << salary << endl;
    }
};
class Course {
public:
    string courseId, courseName;
    int credits;
    Course(string id, string name, int creds) : courseId(id), courseName(name), credits(creds) {}
    void registerStudent(Student &s) {
        s.coursesEnrolled.push_back(courseName);
        cout << "Student " << s.name << " successfully registered for " << courseName << endl;
    }
};
int main() {
    string n, id, addr, ph, em, cName;
    int year, creds;
    double gpa;
    cout << "--- Enter Student Registration Data ---" << endl;
    cout << "Name: "; getline(cin, n);
    cout << "ID: "; getline(cin, id);
    cout << "Address: "; getline(cin, addr);
    cout << "Phone: "; getline(cin, ph);
    cout << "Email: "; getline(cin, em);
    cout << "Enrollment Year: "; cin >> year;
    cout << "Current GPA: "; cin >> gpa;
    cin.ignore();
    Student freshie(n, id, addr, ph, em, year, gpa);
    cout << "\n--- Create a Course ---" << endl;
    cout << "Course Name: "; getline(cin, cName);
    cout << "Credits: "; cin >> creds;
    Course newCourse("CS101", cName, creds);
    cout << endl;
    newCourse.registerStudent(freshie);
    cout << "\n--- Final Student Record ---" << endl;
    freshie.displayInfo();
    return 0;
}
