# password_manager
#Password manager was orignially developed for the purpose of holding my own
 passwords securely-ish, at least not in readable english, but I've run into 
 probelms with methods of encryption and decrypting that encryption with any 
 user generated password which is an integer
#This first version works by adding the user defined integer password to
 every single characters ascii value in that users password file 
 
 #a couple known issues with the program at the moment that are being worked on to be resolved
- not all numerical passwords are usable in the form of encryption the program uses, and I'm currently
  working on implementing openssl for encryption, some numerical values make it so the original letters 
  aren't returnable with the decrypt function

-when trying to sign in as a user directly after making your account, the program won't display the 
 decrypted file documents(debugger will tell you that your file exists, but the contents won't be displayed).
 Exting the program and re-initializing it works
