#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string username, email, password;
    fstream file;

public:
    void signup();
    void login();
};

void temp::signup() {
    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Password: ";
    getline(cin, password);

    file.open("login_data.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();

    cout << "Signup Successful!\n";
}

void temp::login() {
    string searchName, searchPass;

    cout << "Enter Username: ";
    getline(cin, searchName);

    cout << "Enter Password: ";
    getline(cin, searchPass);

    file.open("login_data.txt", ios::in);

    while (getline(file, username, '*')) {
        getline(file, email, '*');
        getline(file, password);

        if (username == searchName && password == searchPass) {
            cout << "Login Successful!\n";
            return;
        }
    }

    cout << "Invalid Credentials!\n";
    file.close();
}

int main() {
    temp obj;
    int choice;

    cout << "\n1. Login";
    cout << "\n2. Signup";
    cout << "\n3. Exit";
    cout << "\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // important

    switch(choice) {
        case 1:
            obj.login();
            break;
        case 2:
            obj.signup();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice!";
    }
}