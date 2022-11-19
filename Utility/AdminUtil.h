#ifndef PROGRAM_FILE_ADMINUTIL_H
#define PROGRAM_FILE_ADMINUTIL_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

#include "Utility.h"
#include "Class/Staff.h"
#include "Class/Date.h"

class AdminUtil : Utility {

public:

    void initial_Config(int number_of_staff) {

        system("cls");

        int idNumber;
        string firstName;
        string lastName;
        string faculty;
        string department;
        string password;
        int day;
        string month;
        int year;

        Date dateEmployed;

        for (int i = 0; i < number_of_staff; ++i) {

            cout << " Enter Staff #" << i + 1 << " Info" << endl;

            cout << "   1. Enter ID Number: " << endl;
            cin >> idNumber;
            cout << "   2. Enter First Name: " << endl;
            cin >> firstName;
            cout << "   3. Enter Last Name: " << endl;
            cin >> lastName;
            cout << "   4. Enter Faculty: " << endl;
            cin >> faculty;
            cout << "   5. Enter Department: " << endl;
            cin >> department;
            cout << "   6. Enter Month Employed:  " << endl;
            cin >> month;
            cout << "   7. Enter Day Employed:  " << endl;
            cin >> day;
            cout << "   8. Enter Year Employed:  " << endl;
            cin >> year;

            dateEmployed.setDay(day);
            dateEmployed.setYear(year);
            dateEmployed.setMonth(month);

            Staff staff = Staff(idNumber, firstName, lastName, faculty, department, dateEmployed);

            ofstream StaffFile("Staff.txt");

            StaffFile << staff.getStaffData();

            StaffFile.close();
        }
    }
};


#endif //PROGRAM_FILE_ADMINUTIL_H
