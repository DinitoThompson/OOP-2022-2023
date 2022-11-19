#ifndef PROGRAM_FILE_UTILITY_H
#define PROGRAM_FILE_UTILITY_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Utility
{

public:
    void user_Login()
    {
        cout << "**********************" << endl;
        cout << "*H&AI Electric System*" << endl;
        cout << "**********************" << endl;
        cout << "**  Select an User  **" << endl;
        cout << "**  1. Staff.       **" << endl;
        cout << "**  2. Student.     **" << endl;
        cout << "**  3. Exit.        **" << endl;
        cout << "**********************" << endl;
        cout << "Input: ";
    }

    void continue_Option()
    {
        system("cls");
        cout << "Do you want to continue." << endl;
        cout << "\t1 : Yes" << endl;
        cout << "\t2 : No" << endl;
        cout << "\tInput: ";
    }

    void initial_Setup()
    {
        cout << "**********************" << endl;
        cout << "*Initial-System-Config*" << endl;
        cout << "**********************" << endl;
        cout << "*#-of-Staff-to-Create*" << endl;
        cout << "**********************" << endl;
        cout << "Input: ";
    }

    void staff_menu()
    {

        cout << "\n\n"
             << endl;
        cout << "**********************" << endl;
        cout << "*H&AI Electric System*" << endl;
        cout << "**********************" << endl;
        cout << "**  Select a Staff Option  **" << endl;
        cout << "**  1. Register Student. **" << endl;
        cout << "**  2. Create Programme. **" << endl;
        cout << "**  3. Edit Programme. **" << endl;
        cout << "**  4. Delete Programme. **" << endl;
        cout << "**  5. Generate Student List. **" << endl;
        cout << "**  6. Exit. **" << endl;
        cout << "**********************" << endl;
        cout << "Input: ";
    }

    void student_menu()
    {
        cout << "**********************" << endl;
        cout << "*H&AI Electric System*" << endl;
        cout << "**********************" << endl;
        cout << "**  Select a Student option  **" << endl;
        cout << "**  1. View Programme Details.  **" << endl;
        cout << "**  2. Add Course.     **" << endl;
        cout << "**  3. Generate Fee Breakdown.  **" << endl;
        cout << "**  4. Generate Progress Report.  **" << endl;
        cout << "**  5. Exit.        **" << endl;
        cout << "**********************" << endl;
        cout << "Input: ";
    }
};

#endif // PROGRAM_FILE_UTILITY_H
