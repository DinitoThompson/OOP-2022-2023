#ifndef PROGRAM_FILE_STAFFUTIL_H
#define PROGRAM_FILE_STAFFUTIL_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

#include "Utility.h"
#include "Class/Student.h"
#include "Class/Programme.h"
#include "Class/Course.h"

class StaffUtil : Utility
{

public:

    void register_Student()
    {

        int idNumber;
        string firstName;
        string lastName;
        string address;
        Date dateEnrolled;
        string programmeCode;
        string enrollmentStatus;
        string contactNumber;
        string password;

        int day;
        string month;
        int year;

        cout << "Enter Student Info " << endl;

        cout << "   1. Enter ID Number: " << endl;
        cin >> idNumber;
        cout << "   2. Enter First Name: " << endl;
        cin >> firstName;
        cout << "   3. Enter Last Name: " << endl;
        cin >> lastName;
        cout << "   4. Enter Address: " << endl;
        cin >> address;
        cout << "   5. Enter Programme Code: " << endl;
        cin >> programmeCode;
        cout << "   6. Enter Enrollment Status: " << endl;
        cin >> enrollmentStatus;
        cout << "   7. Enter Contact Number: " << endl;
        cin >> contactNumber;
        cout << "   8. Enter Month Enrolled:  " << endl;
        cin >> month;
        cout << "   9. Enter Day Enrolled:  " << endl;
        cin >> day;
        cout << "   10. Enter Year Enrolled:  " << endl;
        cin >> year;


        dateEnrolled.setDay(day);
        dateEnrolled.setYear(year);
        dateEnrolled.setMonth(month);

        Student student = Student(idNumber, firstName, lastName, address, dateEnrolled, programmeCode, enrollmentStatus, contactNumber, password);

        std::ofstream fileWriter;

        fileWriter.open("Student.txt", std::ios_base::app);

        fileWriter << student.getStudentData(); 
        
        fileWriter.close();
    }

    void create_Programme()
    {
        string programmeCode;
        string name;
        int maximumNumberOfCourse;
        string award;
        string accreditation;

        cout << "Enter Programme Code Info " << endl;

        cout << "   1. Enter Programme Code: " << endl;
        cin >> programmeCode;
        cout << "   2. Enter Name: " << endl;
        cin >> name;
        cout << "   3. Enter Maximum Number Of Courses: " << endl;
        cin >> maximumNumberOfCourse;
        cout << "   4. Enter Award: " << endl;
        cin >> award;
        cout << "   5. Enter Accreditation: " << endl;
        cin >> accreditation;

        Programme programme = Programme(programmeCode, name, maximumNumberOfCourse, award, accreditation);

        std::ofstream fileWriter;
        fileWriter.open("Programme.txt", std::ios_base::app);

        fileWriter << programme.getProgrammeData();

        fileWriter.close();
    }

    void edit_Programme()
    {
        bool found = false;
        string course_code;
        string courseCode;
        string name;
        string description;
        string credits;
        string preRequisite;

        cout << "Enter Course Code: ";
        cin >> course_code;

        std::ofstream course_file;
        course_file.open("Course.txt", std::ios_base::app);

        ifstream menu_File("Course.txt");

        while (menu_File >> courseCode >> name >> description >> credits >> preRequisite)
        {
            if (courseCode == course_code)
            {
                cout << "Course Found." << endl;
                cout << "Please enter the name of the Course: ";
                cin >> name;
                cout << "Please enter the Description of Course: ";
                cin >> description;
                cout << "Please enter the Course Credit: ";
                cin >> credits;
                cout << "Please enter the Course Prerequiste: ";
                cin >> preRequisite;
                course_file << courseCode << "\t" << name << "\t"
                            << "\t" << description << "\t" << credits << "\t" << preRequisite << endl;
                cout << "Item Added." << endl;
                system("pause");
                found = true; 
                break;
            }
        }

        course_file.close();

    }

    void delete_Programme()
    {
        system("cls");

        string programmeCode;
        string programme_code;
        string name;
        int maximumNumberOfCourse;
        string award;
        string accreditation;

        cout << "Enter programme ID To Delete: ";
        cin >> programme_code;

        ifstream order_File("Programme.txt");
        ofstream temp_File("temp.txt");

        while (order_File >> programmeCode >> name >> maximumNumberOfCourse >> award >> accreditation)
            if (programme_code != programmeCode)
                temp_File << programmeCode << name << maximumNumberOfCourse << award << accreditation << endl;

        order_File.close();
        temp_File.close();

        if (remove("Programme.txt") == 0)
            if (rename("temp.txt", "Programme.txt") == 0)
                cout << "File Update Successfully" << endl;
        system("pause");
    }

    void generate_StudentList()
    {
        system("cls");
        fstream StudentList;

        StudentList.open("Student List.txt", ios::in);

        if (StudentList.is_open())
        {
            string line;
            while (getline(StudentList, line))
            {
                cout << line << endl;
            }
            StudentList.close();
        } else {
            cout << "Sorry, could not open file." << endl; 
        }
    }
};

#endif // PROGRAM_FILE_STAFFUTIL_H
