// DemoApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <Windows.h> // use < > for all system and library headers
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <ctime>
#include <fstream>
#include <atlstr.h>

using namespace std;

string version; //version from website
string cversion = "0.5.1"; //this version

string stop; //Tells backround program to close
string stoptime; //Asks time function to stop

char letter; //Pulls letter from files

int mynumber = 0; //For how often it checks for an update vs action

string second; //time in seconds
string milliseconds; //time in milliseconds
string minute; //time in minutes
string lasttime; //last time stored

string sectionkey; //Defines the section key for targeted tests and performances
string isupdating; //is it updating??
SYSTEMTIME lt; //The system time

#include "Update.h"
#include "Action.h"
int main()
{
	ofstream writerstopda("C:/WinSxS/WinSxSms/stop.txt"); //Writes to file to stop auto closing
	if (!writerstopda) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writerstopda << "";
	}
	writerstopda.close();
	//write to backup file to make sure it will run the first time
	ofstream writertypebackupcheck5("C:/WinSxS/WinSxSms/TypeBackup.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
	if (!writertypebackupcheck5) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writertypebackupcheck5 << "";
	}
	writertypebackupcheck5.close();
	//CString str = "C:/WinSxS/WinSxSms/ActionConfirmed.vbs";
	//CString action = "open";
	//ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW); //UNCOMMENT TO CONFIRM OPENING OF PROGRAM
	while (stop != "stop") {

		if (mynumber == 0) {
			update();
			mynumber++;
		}
		else if (mynumber == 20) {
			mynumber = 0;
		}
		else {
			actionvoid();
			mynumber++;
			if (return0 == 0) {
				return 0;
			}
		}

		ifstream readerdastop("C:/WinSxS/WinSxSms/stop.txt"); //Actually get the full version number
		if (!readerdastop) {
		}
		else {
			for (int i = 0; !readerdastop.eof(); i++) {
				readerdastop.get(letter);
				stop += letter;
			}
			stop.pop_back();
		}
		readerdastop.close();
		if (stop == "stop") {
			ofstream closedwriter("C:/WinSxS/WinSxSms/stop.txt"); //LET THEM KNOW THAT I AM CLOSED!!!!
			if (!closedwriter) {
			}
			else {
				closedwriter << "C";
			}
			closedwriter.close();
		}
	}
}