#include<iostream>
#include<string>
#include<fstream>
#include "Reservation.h"
using namespace std;

int z = 0; //variable of options menue//
void MainMenue()
{
	cout << "\t\t\t\t\t *****SIMPLE BUS RESERVATION SYSTEM*****\n\n"
		<< "\t\t\t\t\t  1. Add Bus Information\n"
		<< "\t\t\t\t\t  2. Reserve Bus Seat\n"
		<< "\t\t\t\t\t  3. Display Reservation Information\n"
		<< "\t\t\t\t\t  4. Cancel Reservation\n"
		<< "\t\t\t\t\t  5. Change Seat\n"
		<< "\t\t\t\t\t  6. Show Avilable seats in the bus\n"
		<< "\t\t\t\t\t  7. Exit..\n\n"
		<< "\t\t\t\t\t  Enter your choise -> "; cin >> z;
}

void Open_Bus_File()
{
	fstream MyFile;
	MyFile.open("Buses.txt", ios::in);
	if (MyFile.is_open())
	{
		string filetxt;
		while (getline(MyFile, filetxt)) {

			cout << filetxt << "\n";
		}
		MyFile.close();
	}
}

int main()
{
	int nn = 0, bus_id = 0;
	Bus b[20]; //array of 20 objects (20 Buses).

	Open_Bus_File();

	do
	{
		MainMenue();

		switch (z)
		{
		case 1:
		{
			try 
			{
				if (nn >= 20)
					throw 0;

				b[nn].AddBuss();
				nn++;
				break;
			}
			catch (int i)
			{
				cout << " Unfortunately, all Buses are reserved..\n\n";
			}
		}

		case 2:
		{
			try
			{
				if (nn == 0) // to prevent the user from reserva a seat without rserve a bus first//
					throw 0;

				bool flag = false;
				cout << "\n Enter the bus ID you want to reserve the seat in: ";
				cin >> bus_id;

				for (int i = 0; i < nn; i++)
				{
					if (b[i].getBusID() == bus_id)
					{
						b[i].Reservation();
						flag = true;
						break;
					}
				}

				if (flag == false)
					cout << "  The Bus number " << bus_id << " is not registed in the system\n";
			}
			catch (int i)
			{
				cout << "Error!  Add a bus first from option number 1 \n";
			}
		}
		break;

		case 3:
		{
			try
			{
				if (nn == 0)
					throw 0;

				for (int i = 0; i < nn; i++)
				{
					if (b[i].getBusID() != 0) //condition to not display any bus that reserved and then canceled afterwhile//
						b[i].show_Reservation_info();
					else
						continue;
				}
			}
			catch (int i)
			{
				cout << "Error!  there is no buses added yet.\n\n";
			}
		}
		break;

		case 4:
		{
			cout << " - Enter the ID of the bus that you want to cancel: ";
			cin >> bus_id;

			bool flag = false;
			for (int i = 0; i < nn; i++)
			{
				if (b[i].getBusID() == bus_id)
				{
					b[i].Cancel_Res();
					flag = true;
					break;
				}
			}

			if(flag == false)
				cout << " There is no such a bus reserved in our system !!  Please enter a valid id number..\n\n";
		}
		break;

		case 5:
		{
			cout << " - Enter the ID of the Bus: ";
			cin >> bus_id; 

			for (int i = 0; i < nn; i++)
			{
				if (b[i].getBusID() == bus_id)
				{
					b[i].Change_Seat();
					break;
				}
			}
		}
		break;

		case 6:
		{
			//int bus_id;
			bool flag = false;

			cout << "choose the bus: ";
			cin >> bus_id;

			for (int i = 0; i < nn; i++)
			{
				if (b[i].getBusID() == bus_id)
				{
					b[i].AvilableSeates();
					flag = true;
					break;
				}
			}

			if(flag == false)
				cout << " You did not reserve this bus in our system, you only able to see an info about it When you reserve it.. \n\n";
		}
		break;
		} 

	} while (z != 7);

	cout << "\n\t\t*** You are logged out from the Application, thanks for using \"Almaza Bus Reservation System\" ***\n"
		<< "\t\t*** We hope to see you soon :) ***\n" << "\t\t\t\t\t | Created By: Asem Adel Ba7r |\n\n";
}