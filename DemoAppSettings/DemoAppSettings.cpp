// DemoAppSettings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

string usertype; //What the user types for actions
string isadmin; //If admin permissions are granted == Yes
string isdaopen; //Checks if the demo App is open or not

char letter; ////Pulls letter from files

int main()
{
	system("color F0");


	ofstream isopenwriter("C:/DemoApp/isopen.txt"); //Checks if the demo App is open or not
	if (!isopenwriter) {
		cout << "Error opening file..." << endl;
	}
	else {
		isopenwriter << "  ";
		isopenwriter.close();
	}
	cout << "Checking if Demo App is opened" << endl;
	cout << "Waiting for response..." << endl;
	for (int n = 0; n < 29; n++) {
		cout << ".";
		Sleep(100); //27,000
	}
	system("CLS");
	ifstream isopenreader("C:/DemoApp/isopen.txt");
	if (!isopenreader) {
	}
	else {
		isdaopen = "";
		for (int i = 0; !isopenreader.eof(); i++) {
			isopenreader.get(letter);
			isdaopen += letter;
		}
		isopenreader.close();
		isdaopen.pop_back();
	}
	if (isdaopen == "  ") {
		CString str = "C:/DemoApp/DemoApp.exe";
		CString action = "open";
		ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
		cout << "Demo App has been opened in the background" << endl;
	}
	else if (isdaopen == "Yes") {
		cout << "Demo App is already opened in the background" << endl;
	}

	cout << "Actions: 'stop' to stop, 'change key' to change row key" << endl;
	while (usertype != "exit") {
		getline(cin, usertype);
		if (usertype == "B1046" && isadmin == "" || usertype == "b1046" && isadmin == "") {
			isadmin = "Yes";
			cout << "Administrator Permissions Granted" << endl;
		}
		else if (usertype == "change key") {
			if (isadmin == "Yes") {
				cout << "Change rowkey" << endl;

			}
			else {
				cout << "Administrator Permissions are required for this action" << endl;
			}
		}
		else if (usertype == "stop") {
			if (isadmin == "Yes") {
				ofstream writerstopda("C:/DemoApp/stop.txt");
				if (!writerstopda) {
					cout << "Error writing to file..." << endl;
				}
				else {
					writerstopda << "stop";
				}
				writerstopda.close();
				cout << "Stopped" << endl;
			}
			else {
				cout << "Administrator Permissions are required for this action" << endl;
			}
		}
		else if (usertype == "exit" || usertype == "bye" || usertype == "Exit" || usertype == "Bye") {
			return 0;
		}
		else {
			cout << "Command not recognized" << endl;
		}
	}
}

