#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
#include <list>
#define MAX 1000
using namespace std; 


//user welcome menu
void user_welcome()
{
    cout << endl;
    cout << "____________________________________________________________\n";
    cout << "____Welcome to the Password Manager_________________________\n";
    cout << "____Created by Angel Barrera________________________________\n";
    cout << "_Options:___________________________________________________\n";
    cout << "_Press 1: Sign into account_________________________________\n";
    cout << "_Press 2: Create New Account________________________________\n";
    cout << "_Press 3: quit program______________________________________\n";
    

}

//create a new account 
void create_account()
{
    string newaccountname, name_of_website_to_add, 
    email_used_for_site, password, username_for_site,
    userfile;
    int encryption_key;
    cout << "Please Enter the Name of Your New Account\n";
    cout << "Enter here: ";
    cin >> newaccountname;
    string newaccount_systemname = newaccountname + ".txt";
    cout << endl;
    cout <<"-----------------------------------------------------------\n";
    cout <<"Next you will choose your new Master Pin for this program\n";
    cout <<"Enter a pin in numerical form using numbers between 1-10\n";
    cout << "Enter here: ";
    cin >> encryption_key;
    userfile = newaccount_systemname;


    if (ifstream(newaccount_systemname))
    {
        cout << endl;
        cout << "That Account Already Seems to Exist," << endl;
        cout << "Please run the program again and sign" << endl;
        cout << "by pressing the proper button" << endl;
    }
    else 
    {
        int create_account_loop;
        ofstream temporary_file("tempfile.txt");
        temporary_file << encryption_key << endl;
        
        do
        {
            cout << endl;
            cout << "-----------------------------------------------------------\n";
            cout << "Enter Name of Website: ";
            cin >> name_of_website_to_add;
            cout << endl <<"Enter your username for this website: ";
            cin >> username_for_site;
            cout << endl << "Enter the Email-Address: " ;
            cin >> email_used_for_site;
            cout << endl <<"Enter Password: ";
            cin >> password;
            temporary_file << "Website name:" << name_of_website_to_add;
            temporary_file << ",Username: " << username_for_site;
            temporary_file << ",Email: " << email_used_for_site;
            temporary_file << ",Password: " << password << endl;

            cout << "\nWould you like to add another account to your list?\n";
            cout << "Enter 1: to add another account\n";
            cout << "Enter 2: to continue without adding another account to the list\n";
            cin >> create_account_loop;
            
        }
        while (create_account_loop == 1);
        temporary_file.close();
        
        /*read temporary_file, transfer all contents from temporary file into 
        a new file encrypted by adding the value of the users key to every character*/
        int len = 0;
        string text, user_file, filearray[MAX];
        ifstream fread;
        fread.open("tempfile.txt");
        if(fread.is_open())
        {
            char c;
            int i, j;
            char arr[MAX];
            while(fread.get(c))
            {
                c = c + encryption_key;
                arr[i] = c;
                i++;

            }
            fread.close();
            arr[i] = '\0';
            ofstream real_file(newaccount_systemname);
            real_file << arr;
            int result = remove("tempfile.txt");
        }
    }

} 


//sign into a previously existing account
void sign_in()
{
    string username_input, myfile;
    int sign_in_loop = 1, encryption_key;
        cout <<"\nWhat is your user username?\n";
        cout <<" Enter Here: ";
        cin >> username_input;
        cout << "Enter the key to your file here: ";
        cin >> encryption_key;
        myfile = username_input + ".txt";
    
        ifstream fread;
        fread.open(myfile);
        if (fread.is_open())
        {
            cout << "File exists \n \n";
            string line;

            char c;
            int i, j;
            char arr[MAX];
            while (fread.get(c))
            {
                c = c - encryption_key;
                arr[i] = c;
                i++;
            }
            fread.close();
            arr[i] = '\0';
            cout << arr << endl;

            
            
        }
        else 
        {
            cout << "\n";
            cout << "-------------------------------------\n";
            cout << "User file Doesn't Exist\n";
            cout << "Please enter a proper username,\n ";
            cout << "or go back and make a new account\n";
            cout <<"--------------------------------------\n";
            sign_in_loop = 1;

        }
}

void encrypt (int encryption_key, string userfile)
{
    ifstream fread;
    fread.open(userfile);
    if (fread.is_open())
    {
        char c;
        int i, j;
        char arr[MAX];
        while (fread.get(c))
        {
            c = c + encryption_key;
            arr[i] = c;
            i++;
        }
        fread.close();
        arr[i] = '\0';
        cout << arr << endl;
    }
}
