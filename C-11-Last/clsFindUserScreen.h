#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;

        ShowPermissions(User);

        cout << "\n___________________\n";
    }

    static void ShowPermissions(clsUser User)
    {
        cout << "\nPermissions: ";

        switch (User.Permissions)
        {
        case -1:
            cout << "Full Access";
            break;

        case 0:
            cout << "No Access";
            break;

        default:

            if ((User.Permissions & clsUser::enPermissions::pListClients)
                == clsUser::enPermissions::pListClients)
            {
                cout << "\n\t- Show Client List";
            }

            if ((User.Permissions & clsUser::enPermissions::pAddNewClient)
                == clsUser::enPermissions::pAddNewClient)
            {
                cout << "\n\t- Add New Client";
            }

            if ((User.Permissions & clsUser::enPermissions::pDeleteClient)
                == clsUser::enPermissions::pDeleteClient)
            {
                cout << "\n\t- Delete Client";
            }

            if ((User.Permissions & clsUser::enPermissions::pUpdateClients)
                == clsUser::enPermissions::pUpdateClients)
            {
                cout << "\n\t- Update Client";
            }

            if ((User.Permissions & clsUser::enPermissions::pFindClient)
                == clsUser::enPermissions::pFindClient)
            {
                cout << "\n\t- Find Client";
            }

            if ((User.Permissions & clsUser::enPermissions::pTranactions)
                == clsUser::enPermissions::pTranactions)
            {
                cout << "\n\t- Transactions";
            }

            if ((User.Permissions & clsUser::enPermissions::pManageUsers)
                == clsUser::enPermissions::pManageUsers)
            {
                cout << "\n\t- Manage Users";
            }

            break;
        }
    }

public:

    static void ShowFindUserScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);
    }
};