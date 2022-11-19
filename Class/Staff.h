#ifndef PROGRAM_FILE_STAFF_H
#define PROGRAM_FILE_STAFF_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

#include "Date.h"

using namespace std;

class Staff
{

protected:
    int idNumber;
    string firstName;
    string lastName;
    string faculty;
    string department;
    Date dateEmployeed;

public:
    Staff(int idNumber, const string &firstName, const string &lastName, const string &faculty,
          const string &department, const Date &dateEmployeed)
    {
        this->idNumber = idNumber;
        this->firstName = firstName;
        this->lastName = lastName;
        this->faculty = faculty;
        this->department = department;
        this->dateEmployeed = dateEmployeed;
    }

    Staff()
    {
        this->idNumber = 1234567;
        this->firstName = "";
        this->lastName = "";
        this->faculty = "";
        this->department = "";
        this->dateEmployeed = Date();
    }

    int getIdNumber() const
    {
        return idNumber;
    }

    void setIdNumber(int idNumber)
    {
        Staff::idNumber = idNumber;
    }

    const string &getFirstName() const
    {
        return firstName;
    }

    void setFirstName(const string &firstName)
    {
        Staff::firstName = firstName;
    }

    const string &getLastName() const
    {
        return lastName;
    }

    void setLastName(const string &lastName)
    {
        Staff::lastName = lastName;
    }

    const string &getFaculty() const
    {
        return faculty;
    }

    void setFaculty(const string &faculty)
    {
        Staff::faculty = faculty;
    }

    const string &getDepartment() const
    {
        return department;
    }

    void setDepartment(const string &department)
    {
        Staff::department = department;
    }

    const Date getDateEmployeed() const
    {
        return dateEmployeed;
    }

    void setDateEmployeed(const Date &dateEmployeed)
    {
        Staff::dateEmployeed = dateEmployeed;
    }

    string getStaffData()
    {
        cout << getIdNumber() << "\t";
        cout << getFirstName() << "\t";
        cout << getLastName() << "\t";
        cout << getFaculty() << "\t";
        cout << getDepartment() << "\t";
        cout << getDateEmployeed().getMonth() << " "
        << getDateEmployeed().getDay() << " "
        << getDateEmployeed().getYear() << "\t";
        cout << "\n"
             << endl;
    }
};

#endif // PROGRAM_FILE_STAFF_H
