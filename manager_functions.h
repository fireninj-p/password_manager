#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
//#include <bits/stdc++.h>
#include <cstring>
#include <list>
#include "password_man/encryption_files/vigenere.h"
#include "password_man/encryption_files/Base64.h"
#include <cstdio>
#define MAX 1000
using namespace std; 


//user welcome menu
void user_welcome()
{
    cout << endl;
    cout << "____________________________________________________________\n";
    cout << "____Welcome to the Password Manager_________________________\n";
    cout << "____Created by Fireninj-p________________________________\n";
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
    string encryption_key;
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
        ifstream fread;
        fread.open("tempfile.txt");
        ofstream real_file(newaccount_systemname);
        string line_to_encrypt;
        if(fread.is_open())
        {
            while(getline(fread, line_to_encrypt))
            {
                string msg = line_to_encrypt;
                string key = encryption_key;
                string encryptedMsg = encrypt_vigenere(msg, key);
                string newKey = extend_key(msg,key);
                real_file << encryptedMsg << endl;

            }
            //const int result = remove("tempfile.txt");

        }else
        {
            cout << "Your File Could not be Encrypted" << endl;
        }
        fread.close();
        const int result = remove("tempfile.txt");



        
    }

} 


//sign into a previously existing account
void sign_in()
{
    string username_input, myfile;
    int sign_in_loop = 1;
    string encryption_key;
        cout <<"\nWhat is your user username?\n";
        cout <<" Enter Here: ";
        cin >> username_input;
        cout << "Enter the key to your file here: ";
        cin >> encryption_key;
        myfile = username_input + ".txt";
    

        //decrypt file
        
        fstream fread;
        fread.open(myfile);
        string file_content;
        if (fread.is_open())
        {
            while(getline(fread, file_content))
            {
                string key = encryption_key;
                string msg = file_content;
                string newKey = extend_key(msg, key);
                string decryptedMsg = decrypt_vigenere(msg, newKey);
                cout << decryptedMsg << endl;
            }

            
            
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
