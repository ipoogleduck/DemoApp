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
string cversion = "0.7"; //this version

string stop; //Tells backround program to close
int stopint; //got every time the function is called to prevent opening more than once
int startstop; //stored at the beggining of opening demo app

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
	stopvoid();
	if (stopint == 9) {
		stopint = 0;
	}
	else {
		stopint++;
	}
	startstop = stopint;

	ofstream writerstopda("C:/WinSxS/WinSxSms/stop.txt"); //Writes to file to stop auto closing
	if (!writerstopda) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writerstopda << startstop;
	}
	writerstopda.close();
	//CString str = "C:/WinSxS/WinSxSms/ActionConfirmed.vbs";
	//CString action = "open";
	//ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW); //UNCOMMENT TO CONFIRM OPENING OF PROGRAM
	while (stop != "stop") {

		stopvoid();
		if (stopint != startstop) {
			return 0;
		}

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
	}
}