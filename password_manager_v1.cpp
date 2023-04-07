#include "manager_functions.h"
#include <iostream>
#include <string>
#include <fstream>
//#include <bits/stdc++.h>
#include <cstring>
#include <list>
#include <filesystem>
#include <cstdio>
//#define MAX 1000;
//header files
//to do:
//fix loop error where program doesn't loop back to main menu
//after signing in and choosing to go back to the menu

//symbols are not recommended in Master Passwords
using namespace std;

int main()
{

    int proceed = 0;
    int initial_input;
    int proceed_case_1 = 0;
    int proceed_case_2 = 0;
    int proceed_case_3 = 0;
    int proceed_case_4 = 0;

    do
    {
        user_welcome();
        cout << "Enter Here: ";
        cin >> initial_input;
        switch (initial_input)
        {
            case 1:
                do
                {
                    sign_in();
                    cout << endl;
                    cout <<" Would you like to sign in again?\n";
                    cout <<" Enter 1 to sign in again,       \n";
                    cout << "Enter 2 to enter the main menu  \n";
                    cout << "Enter 3 to quit the program \n";
                    cout << "Enter here: ";
                    cin >> proceed_case_1;
                }while(proceed_case_1 == 1);
                if (proceed_case_1 == 2)
                {proceed == 1;}
            break;
            
            case 2:
                do
                {
                    create_account();
                    cout << endl;
                    cout <<" Would you like to create another account?\n";
                    cout <<" Enter 1 to create another account,       \n";
                    cout << "Enter 2 to enter the main menu  \n";
                    cout << "Enter 3 to quit the program \n";
                    cout << "Enter here: ";
                    cin >> proceed_case_2;

                }while(proceed_case_2 == 1);
                if (proceed_case_2 == 2)
                {proceed = 1;}
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
    }
    while (proceed == 1);
}
