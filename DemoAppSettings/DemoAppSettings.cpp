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
string isadmin = ""; //If admin permissions are granted == Yes  REMOVE PASSKEY LATER
string isdaopen; //Checks if the demo App is open or not
string status;

char letter; ////Pulls letter from files

string sectionkey; //Defines the section key for targeted tests and performances

int actionabort; //for aborting actions like checking status and closing DA

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
	ifstream readerstatuscheck("C:/DemoApp/status.txt");
	if (!readerstatuscheck) {
	}
	else {
		status = "";
		readerstatuscheck.get(letter);
		status += letter;
	}
	readerstatuscheck.close();
	if (status == "U") {
		cout << "Demo App is currently updating." << endl;
	}
	else if (status == "P") {
		cout << "Demo App is currently performing an action." << endl;
	}
	else {
		if (isdaopen == "  ") {
			CString str = "C:/DemoApp/dastart.vbs";
			//CString str = "C:/DemoApp/DemoApp.exe";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			cout << "Demo App has been opened in the background" << endl;
		}
		else if (isdaopen == "Yes") {
			cout << "Demo App is already opened in the background" << endl;
		}
	}

	ifstream sectionreader("C:/DemoApp/sectionkey.txt"); //For checking if a sectionkey is created
	if (!sectionreader) {
		ofstream sectionwriter("C:/DemoApp/sectionkey.txt");
		while (sectionkey != "0" && sectionkey != "1" && sectionkey != "2" && sectionkey != "3" && sectionkey != "4" && sectionkey != "5") {
			cout << "Please define a section key: 1, 2, 3, 4, or 5" << endl;
			getline(cin, sectionkey);
			if (sectionkey != "1" && sectionkey != "2" && sectionkey != "3" && sectionkey != "4" && sectionkey != "5") {
				cout << "This section key is not valid. Are you sure you want to continue?" << endl;
				getline(cin, sectionkey);
				if (sectionkey == "Yes" || sectionkey == "yes") {
					sectionkey = "0";
					sectionwriter << "0";
					cout << "Saved as '0'" << endl;
				}
			}
			else {
				sectionwriter << sectionkey;
			}
		}
		sectionwriter.close();
	}
	else {
		sectionkey = "";
		sectionreader.get(letter);
		sectionkey += letter;
	}
	sectionreader.close();


	cout << "Actions: 'stop' to stop, 'start' or 'start debug' to start" << endl;
	cout << "Actions: 'change key' to change section key, 'status' to check the status of Demo App" << endl;
	cout << "Section key: ";
	if (sectionkey == "0") {
		cout << "Undefined" << endl;
	}
	else {
		cout << sectionkey << endl;
	}
	while (usertype != "exit") {
		getline(cin, usertype);
		if (usertype == "B1046" && isadmin == "" || usertype == "b1046" && isadmin == "") {
			isadmin = "Yes";
			cout << "Administrator Permissions Granted" << endl;
		}
		else if (usertype == "change key") {
			if (isadmin == "Yes") {
				ofstream sectionwriter("C:/DemoApp/sectionkey.txt");
				cout << "Section 1, 2, 3, 4, or 5" << endl;
				getline(cin, sectionkey);
				if (sectionkey != "1" && sectionkey != "2" && sectionkey != "3" && sectionkey != "4" && sectionkey != "5") {
					cout << "This section key is not valid. Are you sure you want to continue?" << endl;
					getline(cin, sectionkey);
					if (sectionkey == "Yes" || sectionkey == "yes") {
						sectionkey = "0";
						sectionwriter << "0";
						cout << "Saved as '0'" << endl;
					}
					else {
						cout << "Okay, new key not saved" << endl;
					}
				}
				else {
					sectionwriter << sectionkey;
					cout << "Section key saved" << endl;
				}
				sectionwriter.close();
			}
			else {
				cout << "Administrator Permissions are required for this action" << endl;
			}
		}
		else if (usertype == "stop") {
			ifstream readerclosedcheck("C:/DemoApp/stop.txt");
			if (!readerclosedcheck) {
			}
			else {
				readerclosedcheck.get(letter);
			}
			readerclosedcheck.close();
			if (letter != 'C') {
				if (isadmin == "Yes") {
					ofstream writerstopda("C:/DemoApp/stop.txt");
					if (!writerstopda) {
						cout << "Error writing to file..." << endl;
					}
					else {
						writerstopda << "stop";
					}
					writerstopda.close();
					cout << "Waiting for confirmation";
					actionabort = 0;
					while (letter != 'C' && actionabort < 50) {
						actionabort++;
						ifstream readerclosedcheck("C:/DemoApp/stop.txt");
						if (!readerclosedcheck) {
						}
						else {
							readerclosedcheck.get(letter);
						}
						readerclosedcheck.close();
						cout << ".";
						Sleep(300);
					}
					cout << endl;
					if (actionabort == 50) {
						cout << "Demo App is not responding... Try restarting the app" << endl;
					}
					else {
						cout << "Stopped" << endl;
					}
				}
				else {
					cout << "Administrator Permissions are required for this action" << endl;
				}
			}
			else {
				cout << "Demo App is already closed" << endl;
			}
		}
		else if (usertype == "status") {
			//Status for when open, closed, or checking for update
			ifstream readerstatuscheck("C:/DemoApp/status.txt");
			if (!readerstatuscheck) {
			}
			else {
				status = "";
				readerstatuscheck.get(letter);
				status += letter;
			}
			readerstatuscheck.close();
			if (status == "U") {
				cout << "Demo App is currently updating. Type 'start' to override" << endl;
			}
			else if (status == "P") {
				cout << "Demo App is currently performing an action. Type 'start' to override" << endl;
			}
			else {
				ifstream readerclosedcheck("C:/DemoApp/stop.txt");
				if (!readerclosedcheck) {
				}
				else {
					readerclosedcheck.get(letter);
				}
				readerclosedcheck.close();
				if (letter == 'C') {
					cout << "Demo App is closed. Type 'start' to open" << endl;
				}
				else {
				ofstream isopenwriter("C:/DemoApp/isopen.txt"); //Checks if the demo App is open or not
				if (!isopenwriter) {
					cout << "Error opening file..." << endl;
				}
				else {
					isopenwriter << "  ";
					isopenwriter.close();
				}
				cout << "Checking status of Demo App" << endl;
				cout << "Waiting for response";
				for (int n = 0; n < 29; n++) {
					cout << ".";
					Sleep(100); //27,000
				}
				cout << endl;
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
					cout << "Demo App is closed. Type 'start' to open" << endl;
				}
				else if (isdaopen == "Yes") {
					cout << "Demo App is opened and running in the background" << endl;					
				}
				}
			}
		}
		else if (usertype == "start" || usertype == "start debug") {
			if (isadmin == "Yes") {
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
				cout << endl;
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
					if (usertype == "start debug") {
						CString str = "C:/DemoApp/DemoApp.exe";
						CString action = "open";
						ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						cout << "Demo App has been opened in the foreground for debugging" << endl;
					}
					else {
						CString str = "C:/DemoApp/dastart.vbs";
						CString action = "open";
						ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						cout << "Demo App has been opened in the background" << endl;
					}
				}
				else if (isdaopen == "Yes") {
					cout << "Demo App is already opened in the background" << endl;
				}
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

