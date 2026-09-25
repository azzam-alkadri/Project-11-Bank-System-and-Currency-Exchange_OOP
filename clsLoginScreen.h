#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    


    static  bool _Login()
    {

        bool LoginFaild = false;

        short Trials = 3;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";

                cout << "You have " << Trials << " trial(s) left.\n\n";
            }

            if (Trials == 0)
            {
                cout << "Your account is locked. Contact the bank.\n";
                system("pause>0");
                return false ;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            Trials--;

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return  _Login();

    }

};
