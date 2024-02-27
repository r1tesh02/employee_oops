#include <iostream>
#include <fstream>
using namespace std;

class Company {
    string cmpname;
    string city;
    int totalemp;

public:
    Company() {
        cmpname = "xyz";
        city = "local";
        totalemp = 0;
    }

    void company(string cmpname, string city, int totalemp) {
        this->cmpname = cmpname;
        this->city = city;
        this->totalemp = totalemp;
    }

    virtual void display() {
        cout << "********company details*********" << endl;
        cout << "company name :" << cmpname << endl;
        cout << "city location :" << city << endl;
        cout << "total emp count :" << totalemp << endl;
    }
};

class Department : public Company {
    string dname;
    string manager;

public:
    void setdname(string dname, string manager) {
        this->dname = dname;
        this->manager = manager;
    }

    string getdname() {
        return this->dname;
    }

    string getmanager() {
        return this->manager;
    }
    void display()
    {
        cout<<"dept name is : "<<dname<<endl;
        cout<<"manager name is : "<<manager<<endl;
    }
};

class Employee : public Department {
private:
    string name;
    int id;
    string address;
    int age;
    char grade;
    int salary;
    int deptId;

public:
    static int totalsalary;
    static int employeecount;

    string getEmpName() {
        return name;
    }

    void setEmpName(string str) {
        this->name = str;
    }

    void setEmpId(int id) {
        this->id = id;
    }

    int getEmpId() {
        return this->id;
    }

    string getEmpAdd() {
        return this->address;
    }

    void setEmpAdd(string str) {
        this->address = str;
    }

    void setEmpAge(int age) {
        this->age = age;
    }

    int getEmpAge() {
        return this->age;
    }

    void setEmpGrade(char ch) {
        this->grade = ch;
    }

    char getEmpGrade() {
        return this->grade;
    }

    void setEmpSalary(int salary) {
        this->salary = salary;
    }

    int getEmpSalary() {
        return this->salary;
    }

    void setDepId(int deptId) {
        this->deptId = deptId;
    }

    int getDeptId() {
        return this->deptId;
    }

    void display() {
        cout << "employee name is : " << name << endl;
        cout << "employee id is : " << id << endl;
        cout << "employee salary is : " << salary << endl;
    }

    static void caltotalsalary(Employee s1[]) {
        for (int i = 0; i < employeecount; i++) {
            totalsalary = totalsalary + s1[i].salary;
        }
    }

    static void employeecnt() {
        cout << "total employee count is :" << employeecount << endl;
    }

    static void displaytotalsalary() {
        cout << "total salary of all employees is :" << totalsalary << endl;
    }
};

int Employee::totalsalary = 0;
int Employee::employeecount = 0;

int main() {

    fstream file;
    Employee e1[100];
    Department e2[100];
    Company e3[100];

    file.open("input.txt");
    string temp, temp1, temp2;
    int temp3, i = 0;

    while (file >> temp) {
        e1[i].setEmpId(stoi(temp));
        file >> temp;
        e1[i].setEmpName(temp);
        file >> temp;
        e1[i].setEmpSalary(stoi(temp));
        file >> temp >> temp1;
        e1[i].setdname(temp, temp1);
        e2[i].setdname(temp, temp1);
        file >> temp1 >> temp2 >> temp3;
        e1[i].company(temp1, temp2, temp3);
        e3[i].company(temp1, temp2, temp3);

        Employee::employeecount++;
        i++;
    }

    int newi = i;
    Employee::caltotalsalary(e1);

    int value, ans;

    do {
        cout << "Employee details" << endl;
        cout << "1. employee name" << endl;
        cout << "2. employee id" << endl;
        cout << "3. employee salary" << endl;
        cout << "4. total employee salary" << endl;
        cout << "5. total employee count" << endl;
        cout << "6. employee details" << endl;
        cout << "7. department details" << endl;
        cout << "8. company details" << endl;
        cout << "9. all details" << endl;
        cin >> value;

        switch (value) {
        case 1: {
            int i = 0;
            while (newi > i) {
                cout << e1[i].getEmpName() << endl;
                i++;
            }
            break;
        }

        case 2: {
            int i = 0;
            while (newi > i) {
                cout << e1[i].getEmpId() << endl;
                i++;
            }
            break;
        }

        case 3: {
            int i = 0;
            while (newi > i) {
                cout << e1[i].getEmpSalary() << endl;
                i++;
            }
            break;
        }

        case 4: {
            Employee::displaytotalsalary();
            break;
        }

        case 5: {
            Employee::employeecnt();
            break;
        }

        case 6: {
            int i = 0;
            Company *ptr1;

            while (newi > i) {
                 ptr1 = &e1[i];
                ptr1->display();
                i++;
            }
            break;
        }

        case 7: {
            int i = 0;
            Company *ptr2;

            while (newi > i) {
                 ptr2 = &e2[i];
                ptr2->display();
                i++;
            }
            break;
        }

        case 8: {
            int i = 0;
            Company *ptr3;

            while (newi > i) {
                 ptr3 = &e3[i];
                ptr3->display();
                i++;
            }
            break;
        }

        case 9: {
            int i = 0;
            while (newi > i) {
                cout << e1[i].getEmpName()<<endl;
                cout << e1[i].getEmpId()<<endl;
                cout << e1[i].getEmpSalary()<<endl;
                cout << e1[i].getdname()<<endl;
                cout << e1[i].getmanager()<<endl;
                i++;
            }
            break;
        }
        }
        cout << "do u want to continue yes-1||no-0";
        cin >> ans;
    } while (ans == 1);

    return 0;
}
