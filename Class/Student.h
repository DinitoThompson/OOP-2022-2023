#ifndef PROGRAM_FILE_STUDENT_H
#define PROGRAM_FILE_STUDENT_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

#include "Date.h"

using namespace std;

class Student
{

protected:
    int idNumber;
    string firstName;
    string lastName;
    string address;
    Date dateEnrolled;
    string programmeCode;
    string enrollmentStatus;
    string contactNumber;
    string password;

public:
    Student(int idNumber, const string &firstName, const string &lastName, const string &address,
            const Date &dateEnrolled, const string &programmeCode, const string &enrollmentStatus,
            const string &contactNumber, string password)
    {
        this->idNumber = idNumber;
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->dateEnrolled = dateEnrolled;
        this->programmeCode = programmeCode;
        this->enrollmentStatus = enrollmentStatus;
        this->contactNumber = contactNumber;
        this->password = password;
    }

    Student()
    {
        this->idNumber = 1234567;
        this->firstName = "";
        this->lastName = "";
        this->address = "";
        this->dateEnrolled = Date();
        this->programmeCode = "";
        this->enrollmentStatus = "";
        this->contactNumber = "";
        this->password = "";
    }

    int getIdNumber() const
    {
        return idNumber;
    }

    void setIdNumber(int idNumber)
    {
        Student::idNumber = idNumber;
    }

    const string &getFirstName() const
    {
        return firstName;
    }

    void setFirstName(const string &firstName)
    {
        Student::firstName = firstName;
    }

    const string &getLastName() const
    {
        return lastName;
    }

    void setLastName(const string &lastName)
    {
        Student::lastName = lastName;
    }

    const string &getAddress() const
    {
        return address;
    }

    void setAddress(const string &address)
    {
        Student::address = address;
    }

    const Date &getDateEnrolled() const
    {
        return dateEnrolled;
    }

    void setDateEnrolled(const Date &dateEnrolled)
    {
        Student::dateEnrolled = dateEnrolled;
    }

    const string &getProgrammeCode() const
    {
        return programmeCode;
    }

    void setProgrammeCode(const string &programmeCode)
    {
        Student::programmeCode = programmeCode;
    }

    const string &getEnrollmentStatus() const
    {
        return enrollmentStatus;
    }

    void setEnrollmentStatus(const string &enrollmentStatus)
    {
        Student::enrollmentStatus = enrollmentStatus;
    }

    const string &getContactNumber() const
    {
        return contactNumber;
    }

    void setContactNumber(const string &contactNumber)
    {
        Student::contactNumber = contactNumber;
    }

    const string &getPassword() const
    {
        return password;
    }

    void setPassword(const string &password)
    {
        Student::password = password;
    }

    string getStudentData()
    {
        cout << getIdNumber() << "\t";
        cout << getFirstName() << "\t";
        cout << getLastName() << "\t";
        cout << getAddress() << "\t";
        cout << getDateEnrolled().getMonth() << " "
             << getDateEnrolled().getDay() << " "
             << getDateEnrolled().getYear() << "\t";
        cout << getProgrammeCode() << "\t";
        cout << getEnrollmentStatus() << "\t";
        cout << getContactNumber() << "\t";
        cout << "\n" << endl;
    }
};

#endif // PROGRAM_FILE_STUDENT_H
