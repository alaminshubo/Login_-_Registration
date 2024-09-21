#include <bits/stdc++.h>
using namespace std;

class User {
protected:
    string userId;
    string password;
public:
    User() {}
    User(string id, string pass) {
    userId=id;
    password=pass;
    }

    virtual void login() = 0;
    virtual void registration() = 0;
    virtual void forget() = 0;
};

class RegisteredUser : public User {
public:
    RegisteredUser() {}

    void login() override {
        int count = 0;
        string id, pass;
        system("cls");
        cout << "\t\t\t Please enter the username and password : " << endl;
        cout << "\t\t\t Username : ";
        cin >> userId;
        cout << "\t\t\t Password : ";
        cin >> password;

        ifstream input("record.txt");
        while (input >> id >> pass) {
            if (id == userId && pass == password) {
                count = 1;
                system("cls");
                break;
            }
        }
        input.close();

        if (count == 1) {
            cout << userId << "\nYour Login was successful! \nThanks for Logging in!\n";
            mainMenu();
        } else {
            cout << "\nLogin error\nPlease check your username and password.\n";
            mainMenu();
        }
    }
    void registration() override {
        system("cls");
        cout << "\t\t\t Enter the username: ";
        cin >> userId;
        cout << "\t\t\t Enter the Password: ";
        cin >> password;

        ofstream f1("record.txt", ios::app);
        f1 << userId << ' ' << password << endl;
        f1.close();
        system("cls");
        cout << "\n\t\t\t Registration was successful!\n";
        mainMenu();
    }

    void forget() override {
        int option;
        system("cls");
        cout << "\t\t\t Forgot your password?\n";
        cout << " Press 1 to search your ID by username\n";
        cout << " Press 2 to go back to the main menu\n";
        cout << "\t\t\t Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: {
                int count = 0;
                string suserId, sid, spass;
                cout << "\t\t\t Enter the username you remember: ";
                cin >> suserId;

                ifstream f2("record.txt");
                while (f2 >> sid >> spass) {
                    if (sid == suserId) {
                        count = 1;
                        break;
                    }
                }
                f2.close();

                if (count == 1) {
                    cout << "\n\nYour account was found!\n";
                    cout << "\n\nYour password is: " << spass << endl;
                    mainMenu();
                } else {
                    cout << "\n\t Your account was not found!\n";
                    mainMenu();
                }
                break;
            }
            case 2:
                mainMenu();
                break;
            default:
                cout << "\t\t\t Wrong choice! Please try again.\n";
                forget();
        }
    }

    void mainMenu() {
        int c;
        cout << "\t\t\t<====================================>\n\n\n";
        cout << "\t\t\t          Welcome to Login page       \n\n\n";
        cout << "\t\t\t<==========       Menu     ==========>\n\n\n";
        cout << endl;
        cout << "\t\t\t| Press 1 To Login              |" << endl;
        cout << "\t\t\t| Press 2 To Register           |" << endl;
        cout << "\t\t\t| Press 3 To Forget Password    |" << endl;
        cout << "\t\t\t| Press 4 To Exit               |" << endl;
        cout << "\n\t\t\t Please enter your choice : ";
        cin >> c;
        cout << endl;

        switch(c) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forget();
                break;
            case 4:
                cout << "\t\t\t Thank you! \n\n";
                break;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
                mainMenu();
        }
    }
};

class GuestUser : public User {
public:
    GuestUser() {}

    void login() override {
        cout << "Guest users cannot login. Please register first.\n";
        mainMenu();
    }

    void registration() override {
        cout << "Guest users cannot register.\n";
        mainMenu();
    }

    void forget() override {
        cout << "Guest users cannot recover passwords.\n";
        mainMenu();
    }

    void mainMenu() {
        int c;
        cout << "\t\t\t Welcome, Guest! Please register for more options.\n";
        cout << "\t| Press 1 to Exit |\n";
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> c;
        cout << endl;

        switch(c) {
            case 1:
                cout << "\t\t\t Thank you!";
                break;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above.\n" << endl;
                mainMenu();
        }
    }
};

int main() {
    RegisteredUser user;
    user.mainMenu();
    return 0;
}
