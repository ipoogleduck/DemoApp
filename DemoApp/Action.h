#pragma once
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

char letter2; //Need another one
string startvisual; //Start DAVisual


void DAVisual() {
	CString str = "C:/WinSxS/WinSxSms/DAVisual.exe";
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
}
void actionvoid() {
	ofstream writeractioncheck("C:/WinSxS/WinSxSms/SxSaction.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
	if (!writeractioncheck) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writeractioncheck << "_";
	}
	writeractioncheck.close();

	letter = '_'; //resets letter
	updateabort = 0; //resets abort function for update checking
	CString str = "C:/WinSxS/WinSxSms/actioncheck.vbs"; //Opens file in backround to check if new update is available
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
	while (letter == '_' && updateabort < 50 || letter == ' ' && updateabort < 50) {
		updateabort++;
		ifstream readeractioncheck("C:/WinSxS/WinSxSms/SxSaction.txt");
		if (!readeractioncheck) {
		}
		else {
			readeractioncheck.get(letter);
		}
		readeractioncheck.close();

		ofstream isdaopenwriter("C:/WinSxS/WinSxSms/isopen.txt"); //LET THEM KNOW THAT I AM OPEN!!!!
		if (!isdaopenwriter) {
			cout << "Error opening file..." << endl;
		}
		else {
			isdaopenwriter << "Yes";
		}
		isdaopenwriter.close();

		Sleep(300);
	}

	if (updateabort < 50) { //If the update failed to download it will still move on
		ifstream sectionreader("C:/WinSxS/WinSxSms/sectionkey.txt"); //Check section number... If section number is matching then play sound
		if (!sectionreader) {
		}
		else {
			sectionkey = "";
			sectionreader.get(letter2);
			sectionkey += letter2;
		}
		sectionreader.close();
		if (letter == 'a') {
			cout << "Action for all sections" << endl;
			CString str = "C:/WinSxS/WinSxSms/hello.vbs";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
		}
		else if (letter == 'v') {
			cout << "Action for visual" << endl;
			CString str = "C:/WinSxS/WinSxSms/DAVisual.exe";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
		}
		else { //TAKE AWAY
			cout << "No action" << endl;
		}
	}
	else { //TAKE AWAY
		cout << "Action Failure" << endl;
	}
}