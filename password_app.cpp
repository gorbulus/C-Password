/*========================================================================================================================*/
/*
===============================
Filename:       password_app.cpp
Author:         William Ponton
Date:           Version 1: 8.7.17   Program design and basic layout                             (1.0 hours)
                Version 2: 8.8.17   Started some coding - menu, rand, file i/o, etc             (1.5 hours)
                Version 3. 8.9.17:  Flow control of menu, file fixes (user entered filename)    (1.0 hours)

===============================
Description:    A password generator application in C++

***Goals:***
To practice using pointers, classes, header implementation, and read/write files in C++
while learning how to do some basic password hash and encryption.

***Specs:***
1. Prompt the user for a File to write to. (Use Error State Bits)
2. Ask for the number of passwords.
3. Individually ask the criteria of each password:
    a. Name
    b. Length
    c. Special Chars - Legal or not?
4. Generate a clever password.
    -Using the ASCII table, generate random integers and convert to chars using the boundaries for number, letter, symbol.
5. Write the data to a file specified by the user.
5. Encryption (hashing) of some sort.
6. Repetition of the program until user exits at any time.

========================================================================================
***This will not be a true C++ Program until I implement an object oriented solution***
***Use pointers and classes/polymorphism to profile each password.***
========================================================================================
*/

//Include files=====
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

//Constants=====



///Update later to not say "using namespace std;" instead use std::cout << "Blah" << std::endl;
using namespace std;
///Don't forget to inherit the class, and where it goes - after namespace (if using one)!

//Function prototypes=====

//random

//file_open
int file_open(string filename);

//file_read
//void file_read(string filename);

//file_close
//void file_close(ifstream passFile);

//Main function=====
int main()
{
    //Variable Declarations:
    int engage = 0;
    int check = 0;
    int menu_choice = 0;
    string user_file;

    //Program welcome - menu start
    cout << "============================================" << endl;
    cout << "============================================" << endl;
    cout << "==================PASSWORD==================" << endl;
    cout << "===================WIZARD===================" << endl;
    cout << "====================2017====================" << endl;
    cout << "============================================" << endl;
    cout << "============================================" << endl;
    cout << "a project in C++ by William Ponton, August 7, 2017" << endl << endl;
    cout << "PRESS 1 TO START, 0 TO EXIT: ";
    cin >> engage;

    //While user engages program:
    while(engage == 1)
    {
        //Run program
        //1. Ask for Filename
        check = file_open(user_file);
        if(check != 0)
        {
            return 1;
        }

        cout << "============================================" << endl;
        cout << "==================MAIN MENU=================" << endl;
        cout << "============================================" << endl;
        cout << "    1. MAKE A NEW PASSWORD     PRESS 1      " << endl;
        cout << "    1. MAKE A NEW PASSWORD     PRESS 1      " << endl;
        cout << "    1. MAKE A NEW PASSWORD     PRESS 1      " << endl;
        cout << "    1. MAKE A NEW PASSWORD     PRESS 1      " << endl;
        cout << "    1. MAKE A NEW PASSWORD     PRESS 1      " << endl;
        cout << "============================================" << endl;
        //2. Ask for number of passwords
        cout << "PLEASE ENTER A MENU SELECTION, OR PRESS 0 TO EXIT: ";
        cin >> menu_choice;

        ///Fix this so the loop repeats until correct!
        if(isdigit(menu_choice == 0))
           {
              cout << "Invalid selection, try again: ";
              cin >> menu_choice;
           }
        switch(menu_choice){
            case 1: cout << "Case 1" << endl;
                break;
            case 2: cout << "Case 2" << endl;
                break;
            case 3: cout << "Case 3" << endl;
                break;
            case 4: cout << "Case 4" << endl;
                break;
            case 5: cout << "Case 5" << endl;
                break;
            default : cout << "Default!" << endl;
                break;
        }



        //3. Ask for name/length/special chars for each password

        //4. Generate the password using random integers to char arrays (pointers!)
        //4a.   Encrypt and hash before writing

        //5. Write the data to the file the user has specified and clean up all pointers and files.


        //Program Repeat?
        cout << "Try again?" << endl;
        cout << "PRESS 1 FOR YES, 0 fOR EXIT: ";
        cin >> engage;

        //Validate input here (more Robust) - maybe a function?
        if(engage != 1 || isdigit(engage) != 1)
        {
            cout << "~EXIT~" << endl;
            cout << "Goodbye" << endl;
        }

    }//User selected end of program loop

    cout << "With great power comes great responsibility." << endl; // End of program (error or exit)

    ///DID you REMEMBER TO CLEAN UP ALL POINTERS AND CLOSE FILES?===============================
    ///=========================================================================================
    return 0;
}//End main=====




//Random Function=====
/*
    //Random Generator - int to char converter

    int var1 = 0;
    char char1;
    unsigned int seed = 0;
    int random_value = 0;

    cout << "Enter a number to convert: ";
    cin >> var1;
    char1 = var1;
    cout << "Char1 = " << char1 << endl;

    cout << "Var1 = " << static_cast<char>(var1) << endl;

    seed = time(0); // Seed the generator
    cout << "Seed: " << seed << endl;
    //generate the random value and display it
    random_value = rand();
    cout << "Random Number: " << random_value << endl;
    cout << "Random value in ASCII: " << static_cast<char>(random_value) << endl;

    //Generate a random value between 1 and 100

    random_value = rand() % 100 + 1;
    cout << "Random value: " << random_value << endl;
    cout << "Random value in ASCII: " << static_cast<char>(random_value) << endl;

    ///Formula for random range:
    ///random_value = rand() % (high - low +1) + low;

*/
//End random_value generator


//FileOpen/Check
int file_open(string user_file)
{
        cout << "Please enter the filename: ";
        cin >> user_file;
        ofstream outputFile;
        outputFile.open(user_file, ios::out);
        if(!outputFile)
        {
            cout << "~File did not open~" << endl;
        }
        ///Add File writing

        ///Close it up
        outputFile.close();
        /*
        //Variable declarations
        string word;



        //Use a constructor to open and create a file in one operation:
        fstream passFile(user_file, ios::in | ios::out);
        if(!passFile)
        {
            cout << "The file was not found!" << endl;
            return 1;
        }
        //Read and print the file contents.
        //Loop terminates at the end of the file, and end of file flag is set in inOutFile.
        cout << endl;

        cout << user_file << endl;
        while(passFile >> word)
        {
            cout << word << " ";
        }
        cout << endl;
        //Clear end of file flag to allow additional file operations
        passFile.clear();

        //Write a word to the file and close the file
        passFile << "PASSWORD: " << endl;
        passFile.close();
        */
        return 0;//Return 0 if passFile successfully opens


}//End file_open=====


///Use later?
/*
//file_read
void file_read(string user_file)
{
        //Variable declarations
        string word;

        //Use a constructor to open and create a file in one operation:
        fstream passFile(user_file, ios::in | ios::out);
        if(!passFile)
        {
            cout << "The file was not found!" << endl;

        }
        //Read and print the file contents.
        //Loop terminates at the end of the file, and end of file flag is set in inOutFile.
        cout << endl;
        cout << user_file << endl;
        while(passFile >> word)
        {
            cout << word << " ";
        }
        cout << endl;

        //Clear end of file flag to allow additional file operations
        passFile.clear();

}//End file_read=====
*/


///Use later?
/*
//file_close
void file_close(string user_file)
{
         fstream passFile(user_file, ios::in | ios:: out);
         if(!passFile)
        {
            cout << "The file was not found!" << endl;

        }
         //Write a word to the file and close the file
        passFile << "PASSWORD: BLAH BLAH" << endl;
        passFile.close();
}//End file_close=====
*/
