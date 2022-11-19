#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <windows.h>

#include "User.h"

using namespace std;

class Customer : public User
{
private:
    int item_ID;
    string item_Name;
    float item_Price;
    int item_Prep_Time;
    int item_Quantity;

    int order_ID;
    float order_Total;
    int order_Seconds;

    int search_ID;

public:
    void create_Order()
    {
        int orderC_Opt;

        do
        {
            system("cls");
            fflush(stdin);
            cout << "Select Item / Creating Order List. \n" << endl;
            view_Menu();
            cout << "\n\n" << endl;
            cout << "Add item to Order List.\n" << endl;
            cout << "Enter Item ID: ";
            cin >> search_ID;

            std::ofstream order_File;
            order_File.open("Order.txt", std::ios_base::app);

            ifstream menu_File("Menu.txt");

            while (menu_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time)
            {
                if (item_ID == search_ID)
                {
                    cout << "Item Found.";
                    showdata();
                    system("pause");
                    system("cls");
                    cout << "Please Enter The Quantity: ";
                    cin >> item_Quantity;
                    order_ID++;
                    order_File << order_ID << "\t" << item_Name << "\t" << "\t" << item_Price << "\t" << item_Prep_Time << "\t" << item_Quantity << endl;
                    cout << "Item Added." << endl;
                    system("pause");
                    break;
                }
            }

            menu_File.close();
            order_File.close();

            continue_Options();
            cin >> orderC_Opt;
        }
        while (orderC_Opt != 2);
    }
    void view_Order()
    {
    	order_Total = 0; 
    	order_Seconds = 0; 
        // Displaying the Order file line by line.
        ifstream order_File;
        order_File.open ("Order.txt");

        cout << "ORDER LIST" << endl;

        while (order_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time >> item_Quantity)
        {
            cout << "Order ID: " << item_ID << "\n\tItem Name: " << item_Name << "\n\tItem Price: " << item_Price << "\n\tItem Prep-Time: " << item_Prep_Time << "\n\tQuantity: " << item_Quantity << endl;

            order_Total += item_Price * item_Quantity;
            order_Seconds += item_Prep_Time;
        }
        cout << "\nTotal Cost: " << order_Total << endl;
        cout << "Estimated Time (Minutes): " << order_Seconds << "\n" << endl;

        order_File.close();
    }
    void delete_Order()
    {
        system("cls");
        cout << "Enter ID# To Delete: ";
        cin >> search_ID;

        ifstream order_File ("Order.txt");
        ofstream temp_File ("temp.txt");

        while (order_File >> item_ID >> item_Name >> item_Price >> item_Prep_Time >> item_Quantity)
            if (item_ID != search_ID)
                temp_File << item_ID << "\t" <<  item_Name << "\t" << item_Price << "\t" << item_Prep_Time << "\t" << item_Quantity << endl;

        order_File.close();
        temp_File.close();

        if (remove ("Order.txt") == 0)
            if (rename ("temp.txt", "Order.txt") == 0)
                cout << "File Update Successfully" << endl;
        system("pause");
    }
    void customer_Options()
    {
        cout << "Select an Option." << endl;
        cout << "   1. Select an order." << endl;
        cout << "   2. Search for an item." << endl;
        cout << "   3. View Order/s." << endl;
        cout << "   4. Sign Out." << endl;
        cout << "   Option: ";
    }
    void order_Options()
    {
        cout << "Select an Option." << endl;
        cout << "   1. Delete Order." << endl;
        cout << "   2. Submit Order/s." << endl;
        cout << "   3. Return to Menu." << endl;
        cout << "   Option: ";
    }
    void submit_Order()
    {
        int sub_Opt; 
        int order_Minutes; 
        
        order_Minutes = order_Seconds; 
        order_Seconds = 60; 
        // View the orders that were made and have their time count down.

        cout << "\n" << endl; 
        view_Order(); 
        cout << "\n" << endl; 

        cout << "Please Confirm: " << endl; 
        cout << "\t1 : Yes : Submit & Start Timer." << endl; 
        cout << "\t2 : No : Return to Customer Menu." << endl;
		cout << "\tOpt: "; 
        cin >> sub_Opt; 

        if (sub_Opt == 1)
            for(;;)
            {
            	if (order_Minutes == 0)
            	{
            		if (order_Seconds == 0)
            		{
            			system("cls");
        	    		cout << "\n\n\t\t" << "Order Complete." << endl;
						cout << "\n\n\t\t" << "Come in to collect your order..." << endl;
						system ("pause");
						
						ofstream order_File; 
						order_File.open("Order.txt");
						
						ofstream temp_File; 
						temp_File.open("Temp.txt"); 
						
						order_File.close(); 
						temp_File.close(); 
						
						remove("Order.txt");
						rename("Temp.txt", "Order.txt");
						
						system("cls");
						cout << "\n\n\t\t" << "Order File Cleared." << endl; 
						cout << "\n\n\t\t" << "Returning to Menu..." << endl; 
    	                system("pause"); 
	                    break;
					}
				}
                if (order_Seconds == 0)
                {
                	order_Seconds = 60; 
                    order_Minutes --; 
                }
                system("cls");
                cout << "\n\n\t\t" << "Count Down Timer" << endl;
				cout << "\n\n\t\t" << "Time Remaining (Minutes)" << " : " << order_Minutes;
				cout << "\n\n\t\t" << "Time Remaining (Seconds)" << " : " << order_Seconds--;
				Sleep(1000);
            }
        else
        {
            system("cls"); 
            cout << "Returning to Customer Menu..." << endl;
            system("pause");  
        }
    }
};

#endif // CUSTOMER_H
