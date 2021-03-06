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
string cversion = "1.0"; //this version

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
	ofstream writerstopda("C:/DemoApp/stop.txt"); //Writes to file to stop auto closing
	if (!writerstopda) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writerstopda << "";
	}
	writerstopda.close();
	ofstream writerstatuscheck("C:/DemoApp/status.txt");
	if (!writerstatuscheck) {
	}
	else {
		writerstatuscheck << "O";
	}
	writerstatuscheck.close();
	CString str = "C:/DemoApp/ActionConfirmed.vbs";
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
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
		}
		if (isupdating != "Yes") {
			ofstream writerstatuscheck("C:/DemoApp/status.txt"); //resets status
			if (!writerstatuscheck) {
			}
			else {
				writerstatuscheck << "O";
			}
			writerstatuscheck.close();
		}

		ifstream readerdastop("C:/DemoApp/stop.txt"); //Actually get the full version number
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
			ofstream closedwriter("C:/DemoApp/stop.txt"); //LET THEM KNOW THAT I AM CLOSED!!!!
			if (!closedwriter) {
			}
			else {
				closedwriter << "C";
			}
			closedwriter.close();
		}

		ofstream isdaopenwriter("C:/DemoApp/isopen.txt"); //LET THEM KNOW THAT I AM OPEN!!!!
		if (!isdaopenwriter) {
			cout << "Error opening file..." << endl;
		}
		else {
			isdaopenwriter << "Yes";
		}
		isdaopenwriter.close();
	}
}