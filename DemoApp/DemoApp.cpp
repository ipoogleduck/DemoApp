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
string compat; //compatible check from website
string ccompat = "AA"; //this compatible version

int main()
{
	CString str = "C:/DemoApp/ActionConfirmed.vbs";
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
    return 0;
}