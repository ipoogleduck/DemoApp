#pragma once
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

int updateabort;

void update() {
	version = ""; //Makes sure no interference with updated version number
	ofstream writerupdatecheck("C:/DemoApp/daversion.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
	if (!writerupdatecheck) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writerupdatecheck << "_";
	}
	writerupdatecheck.close();
	letter = '_'; //resets letter
	updateabort = 0; //resets abort function for update checking
	CString str = "C:/DemoApp/updatecheck.vbs"; //Opens file in backround to check if new update is available
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
	while (letter == '_' && updateabort < 50 || letter == ' ' && updateabort < 50) {
		updateabort++;
		ifstream readerupdatecheck("C:/DemoApp/daversion.txt");
		if (!readerupdatecheck) {
		}
		else {
			readerupdatecheck.get(letter);
		}
		readerupdatecheck.close();

		ofstream isdaopenwriter("C:/DemoApp/isopen.txt"); //LET THEM KNOW THAT I AM OPEN!!!!
		if (!isdaopenwriter) {
			cout << "Error opening file..." << endl;
		}
		else {
			isdaopenwriter << "Yes";
		}
		isdaopenwriter.close();

		Sleep(500);
	}
	Sleep(1000);
	if (updateabort < 50) { //If the update failed to download it will still move on
		ifstream readergetvnumber("C:/DemoApp/daversion.txt"); //Actually get the full version number
		if (!readergetvnumber) {
		}
		else {
			for (int i = 0; !readergetvnumber.eof(); i++) {
				readergetvnumber.get(letter);
				version += letter;
			}
			version.pop_back();
			cout << version << endl; //delete later
		}
		readergetvnumber.close();
		if (version != cversion) {
			//stop = "stop"; //close this program
			//CString str = "C:/DemoApp/update/daupdate.vbs"; //Start install of new version
			//CString action = "open";
			//ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			cout << "New version" << endl;
		}
		else { //TAKE AWAY
			cout << "Same version " << endl;
		}
	}
	else { //TAKE AWAY
		cout << "Update Failure " << endl;
	}
}