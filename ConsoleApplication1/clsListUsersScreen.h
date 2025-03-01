#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;

class clsListUsersScreen : protected clsScreen
{

private:

    static void _PrintUserRecordLine(clsUser user)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << user.userName;
        cout << "| " << setw(25) << left << user.fullName();
        cout << "| " << setw(12) << left << user.phone;
        cout << "| " << setw(20) << left << user.email;
        cout << "| " << setw(10) << left << user.password;
        cout << "| " << setw(12) << left << user.permissions;

    }

public:

    static void showUsersList()
    {
        vector <clsUser> vUsers = clsUser::getUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser & user : vUsers) {

                _PrintUserRecordLine(user);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

