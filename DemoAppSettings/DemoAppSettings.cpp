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


int main()
{
	system("color F0");
	cout << "Demo App is ready" << endl;
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
		else if (usertype == "exit" || usertype == "bye" || usertype == "Exit" || usertype == "Bye") {
			return 0;
		}
		else {
			cout << "Command not recognized" << endl;
		}
	}
}

