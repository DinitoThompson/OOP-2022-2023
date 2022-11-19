
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <cstdlib>

#include "OlderClasses/Admin.h"
#include "OlderClasses/Customer.h"
#include "OlderClasses/User.h"

#include "Class/Staff.h"
#include "Class/Student.h"
#include "Class/Course.h"
#include "Class/Programme.h"
#include "Utility/AdminUtil.h"
#include "Utility/StaffUtil.h"
#include "Utility/StudentUtil.h"

using namespace std;

int main()
{
    // Class Instances
    User user;
    Admin admin;
    Customer customer;

    // H&AI
    Student student;
    Course course;
    Programme programme;
    Date date;
    Staff staff;

    // H&AI Utility
    AdminUtil adminUtil;
    StaffUtil staffUtil;
    StudentUtil studentUtil;
    Utility utility;

    // Driver Variables
    int user_Opt;
    int orderC_Opt;
    int order_Opt;

    int student_Opt;
    int admin_Opt;

    string user_Name;
    string user_Password;

    fflush(stdin);
    utility.initial_Setup();
    cin >> user_Opt;
    adminUtil.initial_Config(user_Opt);

    do
    {
        system("cls");
        fflush(stdin);
        utility.user_Login();
        cin >> user_Opt;

        switch (user_Opt)
        {
        // Staff Instance
        case 1:
            system("cls");
            fflush(stdin);
            cout << "Welcome Staff !\n"
                 << endl;
            system("pause");
            system("cls");

            cout << "Staff - Sign In \n"
                 << endl;
            cout << "Enter Staff ID: ";
            cin >> user_Name;
            cout << "Enter Password: ";
            cin >> user_Password;

            if (user_Name == "staff" && user_Password == "staff")
            {
                do
                {
                    system("cls");
                    fflush(stdin);

                    cout << "Welcome Staff User.  \n\n"
                         << endl;
                    cout << "\n\n"
                         << endl;
                    utility.staff_menu();
                    cin >> admin_Opt;

                    switch (admin_Opt)
                    {
                    case 1:
                        system("cls");
                        fflush(stdin);
                        staffUtil.register_Student();
                        break;
                    case 2:
                        system("cls");
                        fflush(stdin);
                        staffUtil.create_Programme();
                        break;
                    case 3:
                        system("cls");
                        fflush(stdin);
                        staffUtil.edit_Programme();
                        break;
                    case 4:
                        system("cls");
                        fflush(stdin);
                        staffUtil.delete_Programme();
                        break;
                    case 5:
                        system("cls");
                        fflush(stdin);
                        staffUtil.generate_StudentList();
                        break;
                    case 6:
                        system("cls");
                        fflush(stdin);
                        cout << "Returning to Main Menu." << endl;
                        break;
                    default:
                        system("cls");
                        fflush(stdin);
                        cout << "Incorrect Option" << endl;
                        break;
                    }
                } while (admin_Opt != 6);
            }
            else
            {
                system("cls");
                fflush(stdin);
                cout << "Incorrect Credentials.\n"
                     << endl;
                cout << "Returning to Main Menu.\n"
                     << endl;
                system("pause");
            }
            break;

            // Student Instance
        case 2:
            system("cls");
            fflush(stdin);
            cout << "Welcome Student !\n"
                 << endl;
            system("pause");
            system("cls");

            cout << "Sign In \n"
                 << endl;
            cout << "Enter Username: ";
            cin >> user_Name;
            cout << "Enter Password: ";
            cin >> user_Password;

            if (user_Name == "student" && user_Password == "student")
            {
                do
                {
                    system("cls");
                    fflush(stdin);
                    cout << "Welcome Student ! \n\n"
                         << endl;
                    cout << "\n\n"
                         << endl;
                    utility.student_menu();
                    cin >> student_Opt;
                    switch (student_Opt)
                    {
                    case 1:
                        system("cls");
                        fflush(stdin);
                        studentUtil.view_Programme();
                        break;

                    case 2:
                        system("cls");
                        fflush(stdin);
                        studentUtil.add_Course();
                        break;

                    case 3:
                        system("cls");
                        fflush(stdin);
                        studentUtil.generate_FeeBreakdown();
                        break;

                    case 4:
                        system("cls");
                        fflush(stdin);
                        studentUtil.generate_ProgressReport();
                        break;

                    case 5:
                        system("cls");
                        fflush(stdin);
                        cout << "Returning to Front Page." << endl;
                        break;
                        fflush(stdin);

                    default:
                        system("cls");
                        cout << "Incorrect Option." << endl;
                        break;
                    }
                } while (student_Opt != 5);
            }
            else
            {
                system("cls");
                fflush(stdin);
                cout << "Incorrect Credentials.\n"
                     << endl;
                cout << "Returning to Main Menu.\n"
                     << endl;
                system("pause");
            }
            break;

            // Exit
        case 3:
            system("cls");
            cout << "Good Bye !..." << endl;
            system("pause");
            break;

            // Invalid Option
        default:
            system("cls");
            cout << "Invalid Option." << endl;
            system("pause");
            break;
        }
    } while (user_Opt != 3);

    return 0;
}
