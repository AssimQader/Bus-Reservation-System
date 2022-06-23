#include "Reservation.h"
#include<iostream>
#include<string>
using namespace std;

int Bus::n = 0; //static member

Bus::Bus() : amountOfSeats(0), busID(0), from("null"), to("null"), lclass("null"), date("null"), timee("null")
{
	for (int i = 0; i < 20; ++i)
	{
		Passengers[i] = "Empty";
	}
}


void Bus::setBusID(int i)
{
	busID = i;
}
int Bus::getBusID()
{
	return busID;
}

void Bus::setFrom(string f)
{
	 from= f;
}
string Bus::getFrom()
{
	return from;
}

void Bus::setTo(string t)
{
	 to = t;
}
string Bus::getTo()
{
	return to;
}

void Bus::setlclass(string l)
{
	lclass = l;
}
string Bus::getlclass()
{
	return lclass;
}

void Bus::setdate(string d)
{
	date = d;
}
string Bus::getdate()
{
	return date;
}

void Bus::settime(string tt)
{
	timee = tt;
}
string Bus::gettime()
{
	return timee;
}

void Bus::setAmountOfSeats(int a)
{
	amountOfSeats = a;
}
int Bus::getAmountOfSeats()
{
	return amountOfSeats;
}


//---------------------------------------------------------//

void Bus::reserveSeates(int n, string p)
{
	try
	{
		if (Passengers[n - 1] != "Empty") //to prevent the passenger from reserve a seat which is already taken
			throw 0;

		Passengers[n - 1] = p;
		cout << "\n - Your Reservation added successfuly...\n\n";
	}
	catch (...)
	{
		cout << "This seat is reserved before.\n";
	}
}

void Bus::getReservedSeats() //give info about who reserve a seat and the number of it//
{
	for (int i = 0; i < 20; ++i)
	{
		if (Passengers[i] != "Empty")
			cout <<"   ("<< i + 1 <<")" << " for " << Passengers[i] << ".\n";
	}
}

void Bus::displayBusSeates() //show the whole bus seats in an organized shap at console//
{
	int counter = 0; 
	for (int i = 0; i < 20; ++i)
	{
		if (i == 5 || i == 10 || i == 15 || i == 20)
			cout << "\n";

		cout << "   " << ++counter << "." << Passengers[i] << "\t";
	}
	cout << "\n\n";
}

int Bus::emptySeates() //get the number of empty seats//
{
	int EmptySeats = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (Passengers[i] == "Empty")
			EmptySeats++;
	}
	return EmptySeats;
}

void Bus::dataReset() //reset the bus info as it was before reservation process//
{
	setBusID(0);
	setFrom("NULL");
	setTo("NULL");
	setdate("NULL");
	settime("NULL");
	setlclass("NULL");
	setAmountOfSeats(0);

	for (int i = 0; i < 20; ++i)
		Passengers[i] = "Empty";
}

void Bus::deleteSeat(int n)
{
	Passengers[n - 1] = "Empty";
}

//---------------------------------------------------------//

void Bus::AddBuss()
{
	int busid = 0;
	char from[15], to[15], date[10], timee[10];

	cout << "\n # Enter the ID of the bus number " << n + 1 << ":  ";
	cin >> busid;
	setBusID(busid);
	cout << "\n";

	cout << " # Enter your destination:\n" << "\tFrom: ";
	cin >> from;
	setFrom(from);
	cout << "\tTo: ";
	cin >> to;
	setTo(to);
	cout << "\n";

	cout << " # Enter the departure date and time:\n";
	cout << "\t Date: ";
	cin >> date;
	setdate(date);
	cout << "\t Time: ";
	cin >> timee;
	settime(timee);
	cout << "\n";

	cout << " # Enter the luxury class of the bus: 1. Air-Conditioned\t2. Ordinary\n";
	int x; cin >> x;
	switch (x)
	{
	case 1:
		setlclass("Air-Conditioned");
		break;
	case 2:
		setlclass("Ordinary");
	}
	n++; //buss added
	cout << " - Your Bus added succsessfully..\n\n"
		<< "________________________________________________________________________________________\n\n";
}

void Bus::Reservation()
{
	int nSeats, passengerSeatNum;
	char passName[20];

	if (emptySeates() == 0) //check the number of avilable seats in the bus. 
		cout << " Sorry, this bus is full, choose another one..\n\n";
	else
	{
		cout << "\n # Enter the amount of seats you want in the chosen Bus: ";
		cin >> nSeats;
		setAmountOfSeats(nSeats);
		cout << "\n";

		for (int j = 0; j < getAmountOfSeats(); j++)
		{
			cout << "    Enter the name of the passenger number " << j + 1 << ": ";
			cin >> passName;

			cout << "    Enter the seat number of the passenger " << j + 1 << ": ";
			cin >> passengerSeatNum;

			reserveSeates(passengerSeatNum, passName);
		}
	}
}

void Bus::AvilableSeates()
{
		displayBusSeates(); //show the whole seats in the bus//
		cout << "\n\n   - There are " << emptySeates() << " seats avilable in the bus number: " << getBusID() << "\n\n";
		cout << "_________________________________________________________________________________________\n\n";
}

void Bus::show_Reservation_info()
{
	cout << "\t//YOUR RESERVATION INFOs//\n\t-------------------------\n\n";
	cout << "\tInfo of the Bus number: " << getBusID() << "\n";

	cout << " - Bus ID: " << getBusID() << "\n"
		<< " - From: " << getFrom() << "\n"
		<< " - To:  " << getTo() << "\n"
		<< " - Date: " << getdate() << "\n"
		<< " - Departure Time: " << gettime() << "\n"
		<< " - Luxury Class: " << getlclass() << "\n"
		<< " - Number of reserved seats: " << getAmountOfSeats() << "\n"
		<< " - The number of your seates are: "; getReservedSeats(); cout << "\n\n";

	cout << "*************************************************************\n\n"; 
}

void Bus::Cancel_Res()
{
			dataReset();
			n--; // to delete the reserved bus from the system//
			cout << " - Cancelation done successfully..\n\n";
}

void Bus::Change_Seat()
{
	int prenum, postnum;
	string name;

		displayBusSeates();
		cout << "Choose the seat you want to change: ";
		cin >> prenum;
		deleteSeat(prenum);

		cout << "Choose the person and seat you want to replace with: \n";
		cout << "Person's name:  "; cin >> name;
		cout << "Seat number:  "; cin >> postnum;

		reserveSeates(postnum, name);

		cout << " - Changing done successfully...\n\n";
}


