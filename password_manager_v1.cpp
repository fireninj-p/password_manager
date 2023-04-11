#include "manager_functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <list>
#include <cstdio>


using namespace std;

int main()
{
    int proceed = 0, proceed_case = 0;
    int initial_input;

    do
    {
        proceed = 0;
        proceed_case = 0;

        user_welcome();
        cout << "Enter Here: ";
        cin >> initial_input;
        switch(initial_input)
        {
            case 1:
                do{
                    proceed_case = 0;
                    sign_in();
                    cout << endl;
                    cout <<" Would you like to sign in again?\n";
                    cout <<" Enter 1 to sign in again,       \n";
                    cout << "Enter 2 to enter the main menu  \n";
                    cout << "Enter 3 to quit the program \n";
                    cout << "Enter here: ";
                    cin >> proceed_case;
                    if (proceed_case == 2)
                    {
                        proceed = 1;
                    }
                }while(proceed_case == 1);
            break;

            case 2:
                do{
                    proceed_case = 0;
                    create_account();
                    cout <<" Would you like to create another account?\n";
                    cout <<" Enter 1 to create another account,       \n";
                    cout << "Enter 2 to enter the main menu  \n";
                    cout << "Enter 3 to quit the program \n";
                    cout << "Enter here: ";
                    cin >> proceed_case;
                    if (proceed_case == 2)
                    {
                        proceed = 1;
                    }
                }while(proceed_case == 1);
            break;

            case 3:
                exit(1);
            break;

            default:
                cout << "\n";
                cout << "----------------------------------------------------\n";
                cout << "Whatever you typed in is not accepted by the program\n";
                cout << "----------------------------------------------------\n";
        }
    }while(proceed == 1);
}
