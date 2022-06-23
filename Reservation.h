#pragma once
#include<iostream>
#include<string>
using namespace std;

class Bus 
{
private:
	int  busID, amountOfSeats;
	string Passengers[20]; //array of bus seats(passengers).
	string from, to, lclass, date, timee;
	static int n; //counter to keep track each bus added, and static to chang manually each time a bus created
public:
	Bus();

	void setFrom(string f);
	string getFrom();

	void setTo(string t);
	string getTo();

	void setlclass(string l);
	string getlclass();

	void setdate(string d);
	string getdate();

	void settime(string tt);
	string gettime();

	void setBusID(int);
	int getBusID();

	void setAmountOfSeats(int a); /* to set how many seats the passenger will reserve in the bus */
	int getAmountOfSeats();

	void reserveSeates(int n, string p);  /* to set where the passenger will set down in bus */
	void getReservedSeats();   /* to get where the passenger is seting down in bus */

	int emptySeates();

	void displayBusSeates(); /* display the whole bus seats */

	void dataReset();  /* delete all data from a bus */
	void deleteSeat(int n);

//-------------------------------------------------------------//

	//Fianl Functions which will be used in main() {}//
	void AddBuss(); 
	void Reservation();
	void AvilableSeates();
	void Cancel_Res();
	void Change_Seat();
	void show_Reservation_info();
};



