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

char letter; ////Pulls letter from files

int main()
{
	system("color F0");

	//read system file Live.txt

	//If not filled out:
	//Get Type.txt link
	cout << "Welcome to Live Type Setup" << endl;
	cout << "Please follow the instructions on the website, and paste in the link below for the Type file" << endl;
	getline(cin, usertype);
	//Convert to dl.dropboxusercontent.com
	//Save in Type.bat file

	//Get Live.txt link
	//Convert to dl.dropboxusercontent.com
	//Save in Live.bat file

	//Zip folder
	//Give user promt to continue online


	//If filled out:
	cout << "Welcome to Live Type Setup" << endl;
	cout << "Type 'Setup' to re-setup links, 'Zip' to rezip the folder, and 'Help' if you're having trouble with the app" << endl;
}

