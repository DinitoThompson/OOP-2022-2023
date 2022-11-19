#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "User.h"

using namespace std;

#include <cstdlib>


class Admin : public User
{
private:
    int item_ID;
    string item_Name;
    float item_Price;
    int item_Prep_Time;
    int search_ID;

public:
    void get_Data()
    {
        cout << "Enter Name of Item: ";
        cin >> item_Name;
        cout << "Enter Price of Item: ";
        cin >> item_Price;
        cout << "Enter Item Prep-time: ";
        cin >> item_Prep_Time;
    }
    void admin_Options()
    {
        cout << "Select an Option." << endl;
        cout << "   1. Add New Menu Item." << endl;
        cout << "   2. Search Menu item." << endl;
        cout << "   3. Edit Menu Items." << endl;
        cout << "   4. Delete Menu Item." << endl;
        cout << "   5. Return to Main Menu." << endl;
        cout << "Option: ";
    }
    int get_CurrentID()
    {
    	int current_ID = 1;
    	item_ID = 0;

    	std::ifstream menu_Ptr;
    	menu_Ptr.open("Menu.txt");

    	while (menu_Ptr >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
			current_ID = item_ID;

		current_ID = item_ID + 1;
		return current_ID;
	}
	void add_Item()
    {
    	system("cls");

		std::ofstream menu_Ptr;
		menu_Ptr.open("Menu.txt", std::ios_base::app);

		item_ID = get_CurrentID();
		get_Data();
		menu_Ptr << item_ID << "\t" << item_Name << "\t" << item_Price << "\t" << item_Prep_Time << endl;

		system("cls");
		cout << "Menu Updated." << endl;

		system("pause");
		menu_Ptr.close();
    }
    void edit_Menu()
    {
        // Edit The Menu Line By Line.

        int newitem_ID  = 0;
        string newitem_Name;
        float newitem_Price;
        int newitem_Prep_Time;

        cout << "Enter the Item ID of the Item you wish to edit: ";
        cin >> newitem_ID;

        ifstream ofile;
        ofile.open("Menu.txt");

        std :: ofstream file1;
        file1.open("temp_Menu.txt",std::ofstream::out | std::ofstream::app);

        while (ofile >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
        {
            if (newitem_ID != item_ID)
                file1 << item_ID << "\t" << item_Name << "\t" << item_Price << "\t" << item_Prep_Time << endl;

			else if (newitem_ID == item_ID)
            {
                system("cls");
                cout << "Current information: "<< endl;
				showdata();

                cout << "Enter the New Information below." << endl;

                cout << "Enter the Name: ";
                cin >> newitem_Name;
                cout << "Enter the New Price: ";
                cin >> newitem_Price;
                cout << "Enter the New Prep-Time: ";
                cin >> newitem_Prep_Time;

				system("cls");
                file1 << item_ID << "\t" << newitem_Name << "\t" << newitem_Price << "\t" << newitem_Prep_Time << "\t" << endl;
                cout <<"Item Updated Successfully!!" <<endl;
            }
        }

        ofile.close();
        file1.close();

        if (remove ("Menu.txt") == 0)
            if (rename ("temp_Menu.txt", "Menu.txt") == 0)

        system("pause");

    }
    void delete_Menu()
    {
        system("cls");
        cout << "Enter ID# To Delete: ";
        cin >> search_ID;

        ifstream menu_File ("Menu.txt");
        ofstream temp_File ("temp.txt");

        while (menu_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
            if (item_ID != search_ID)
                temp_File << item_ID << "\t" <<  item_Name << "\t" << item_Price << "\t" << item_Prep_Time << endl;

        menu_File.close();
        temp_File.close();

        if (remove ("Menu.txt") == 0)
            if (rename ("temp.txt", "Menu.txt") == 0)
                cout << "File Update Successfully" << endl;
        system("pause");
    }
	void showdata()
    {
        cout << "\n" << endl;
        cout << "Item ID#: " << item_ID << endl;
        cout << "Item Name: " << item_Name << endl;
        cout << "Item Price: " << item_Price << endl;
        cout << "Item Prep Time: " << item_Prep_Time << endl;
        cout << "\n" << endl;
    }
};

#endif // ADMIN_H
