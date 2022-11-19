#ifndef PROGRAM_FILE_STUDENTUTIL_H
#define PROGRAM_FILE_STUDENTUTIL_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

#include "Utility.h"

class StudentUtil : Utility
{
public:
    void student_Login()
    {
        cout << "**********************" << endl;
        cout << "*H&AI Electric System*" << endl;
        cout << "**********************" << endl;
        cout << "**  Select an Option  **" << endl;
        cout << "**  1. View Programme Details. **" << endl;
        cout << "**  2. Add Course. **" << endl;
        cout << "**  3. Generate Fee Breakdown for Semester. **" << endl;
        cout << "**  4. Generate Progress Report. **" << endl;
        cout << "**********************" << endl;
        cout << "Input: ";
    }

    void view_Programme()
    {
        system("cls");

        // Create a text string, which is used to output the text file
        string file_data;

        // Read from the text file
        ifstream fileReader("Programme.txt");

        // Use a while loop together with the getline() function to read the file line by line
        while (getline(fileReader, file_data))
        {
            // Output the text from the file
            cout << file_data;
        }

        // Close the file
        fileReader.close();
    }

    void add_Course()
    {
        string courseCode;
        string name;
        string description;
        string credits;
        string preRequisite;

        // GET USER INFO
        cout << "Please Enter Course Code: ";
        cin >> courseCode;

        cout << "Please Enter Course Name: ";
        cin >> name;

        cout << "Please Enter Course Description: ";
        cin >> description;

        cout << "Please Enter Course Credits: ";
        cin >> credits;

        cout << "Please Enter Course Pre-requisite: ";
        cin >> preRequisite;

        Course course = Course(courseCode, name, description, credits, preRequisite);

        // Create and open a text file
        ofstream course_File("Course.txt");

        // Write to the file
        course_File << course.getCourseData();

        // Close the file
        course_File.close();
    }

    void generate_FeeBreakdown()
    {
        system("cls");
        int numberOfCourses = 0;
        int feeBreakdown = 0;

        fstream myFile;
        myFile.open("Course.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                numberOfCourses++;
            }
            myFile.close();
        }
        else
        {
            cout << "Sorry, file could not be opened." << endl;
        }

        cout << "Fee Break Down: " << numberOfCourses * 15 << endl;
    }

    void generate_ProgressReport()
    {
        system("cls");

        fstream myFile;

        myFile.open("ProgressReport.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
        }
        else
        {
            cout << "Sorry, file could not be opened." << endl;
        }
    }
};

#endif // PROGRAM_FILE_STUDENTUTIL_H