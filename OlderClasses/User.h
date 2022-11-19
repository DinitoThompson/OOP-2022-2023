#ifndef USER_H
#define USER_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

class User
{
protected:
    // Variables an item.
    int item_ID;
    string item_Name;
    float item_Price;
    int item_Prep_Time;

    string search_Name;

public:
    char Name[50];

    void menu_Search()
    {
        // Search the menu file by Item Name.
        // Display if found.
        ifstream menu_File("Menu.txt");

        cout << "Enter Item Name: " << endl;
        cin >> search_Name;

        while (menu_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
        {
            if (item_Name == search_Name)
            {
                system("cls");
                cout << "Item Found." << endl;
                showdata();
                system("pause");
                menu_File.close();
                break;
            }
        }
        if (item_Name != search_Name)
        {
            system("cls");
            cout << "Item Wasnt Found." << endl;
            cout << "Make sure you entered Item Name as seen in Menu." << endl;
            system("pause");
            menu_File.close();
        }
    }
    void view_Menu()
    {
        // Displaying the Menu file line by line.
        ifstream menu_File;
        menu_File.open("Menu.txt");

        cout << "Item ID\t\t\t"
             << "Name\t\t\t"
             << "Price\t\t\t"
             << "Prep-Time (Minutes)\t\t\t" << endl;

        while (menu_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
            cout << item_ID << "\t\t\t" << item_Name << "\t\t\t" << item_Price << "\t\t\t" << item_Prep_Time << endl;

        menu_File.close();
    }
    void front_Opt()
    {
        cout << "**********************" << endl;
        cout << "**Barbican*Beach*Bar**" << endl;
        cout << "**********************" << endl;
        cout << "**  Select an User  **" << endl;
        cout << "**  1. Admin.       **" << endl;
        cout << "**  2. Customer.    **" << endl;
        cout << "**  3. Exit.        **" << endl;
        cout << "**********************" << endl;
        cout << "Option: ";
    }
    void continue_Options()
    {
        system("cls");
        cout << "Do you want to continue." << endl;
        cout << "\t1 : Yes" << endl;
        cout << "\t2 : No" << endl;
        cout << "\tOption: ";
    }
    void showdata()
    {
        cout << "\n"
             << endl;
        cout << "Item ID#: " << item_ID << endl;
        cout << "Item Name: " << item_Name << endl;
        cout << "Item Price: " << item_Price << endl;
        cout << "Item Prep Time (Minutes): " << item_Prep_Time << endl;
        cout << "\n"
             << endl;
    }
};

#endif
