# password manager
**Currently only known to work on windows**


 #Password manager was orignially developed for the purpose of holding my own
 passwords securely-ish, at least not in readable english.
 
 #At the moment the program runs more as a password storer, with you being
  able to store youre passwords once under a specific account name of your 
  choosing with a password of your own once, and being able to sing back 
  into that file you made going further, 
  *repeat* you can only store your accounts once currently, and cannot 
   manipulate the files any further at the moment, but is in developement.
   
 
 

#How to Run:

For windows:
 
	-install all files into any folder on your machine,
	 there is an example on how to use the encryption library yourself 
		in:
		password_man/encryption_files/example.cpp
		
	-Main file "password_manager_v1.cpp"
	
	-Run the "password_manager_v1.cpp"
	
	or
	
	enter this in the terminal in the proper file path:
	
	-g++ -o main password_manager_v1.cpp
	
	-then enter to run:
	
	-./main
	




Output:

 -
		____________________________________________________________
		____Welcome to the Password Manager_________________________
		____Created by Fireninj-p________________________________
		_Options:___________________________________________________
		_Press 1: Sign into account_________________________________
		_Press 2: Create New Account________________________________
		_Press 3: quit program______________________________________
		Enter Here: 
		
		
Creating An Account:

-Press 2 and enter to begin making a new account, and the next message will display:

-		Enter Here: 2
		Please Enter the Name of Your New Account
		Enter here: test


		=======================================================================      
		Come up with a Secure Master Password consisting of letters and numbers      
		Security Alert: The strength of your password is crucial!
		Your Master Password is the key to unlocking all your stored passwords.      
		For the sake of your privacy, it's essential to choose a strong password.    
		A strong password should have a combination of letters and numbers.
		Make sure your password is at least 8 characters long and difficult to guess.
		Remember, a weak password could put all your sensitive information at risk!  
		Don't use personal information or common words that can be easily guessed.   
		Protect yourself by creating a unique and complex password.
		Take your time and choose wisely, your online security depends on it!        
		============================================================
		Enter your Master Password: test

		-----------------------------------------------------------
		Enter Name of Website: test

		Enter your username for this website: test

		Enter the Email-Address: test

		Enter Password: test

		Would you like to add another account to your list?
		Enter 1: to add another account
		Enter 2: to continue without adding another account to the list
-you can add as many accounts as you want indefinitely by pressing and entering 1

Signing into your account

(REMEMBER YOUR MASTER PASSWORD)
-At the start screen press 1 to sign into your account;
-		____________________________________________________________
		____Welcome to the Password Manager_________________________
		____Created by Fireninj-p________________________________
		_Options:___________________________________________________
		_Press 1: Sign into account_________________________________
		_Press 2: Create New Account________________________________
		_Press 3: quit program______________________________________
		Enter Here: 1

		What is your user username?
		 Enter Here: test
		Enter the key to your file here: test
		
-the program will then paste your decrypted information onto the terminal,
 at the moment
 
-		test
		Website name:test,Username: test,Email: test,Password: test

		 Would you like to sign in again?
		 Enter 1 to sign in again,
		Enter 2 to enter the main menu
		Enter 3 to quit the program
		Enter here:

-The program will always display something to the console at the moment, but you need
the appropriate password in order to decrypt the file properly.

Wrong Password Example:

-		Enter Here: 1

		What is your user username?
		 Enter Here: test
		Enter the key to your file here: wrongpassword
		q2wz
		T2fyviwaoTqg:bfxz,XLfdjfof:by6Ex,qm8n9:7v5xG,TatpmpHa:dzrhL
