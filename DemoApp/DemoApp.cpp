// DemoApp.cpp : Defines the entry point for the console application.
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

string version; //version from website
string cversion = "0.1"; //this version

string stop; //Tells backround program to close

char letter; ////Pulls letter from files

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
	CString str = "C:/DemoApp/ActionConfirmed.vbs";
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
	while (stop != "stop") {

		update();

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

		ofstream isdaopenwriter("C:/DemoApp/isopen.txt"); //LET THEM KNOW THAT I AM OPEN!!!!
		if (!isdaopenwriter) {
			cout << "Error opening file..." << endl;
		}
		else {
			isdaopenwriter << "Yes";
		}
		isdaopenwriter.close();
	}
	Sleep(1000);
}