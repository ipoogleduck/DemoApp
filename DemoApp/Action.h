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

void actionvoid() {
	ofstream writeractioncheck("C:/DemoApp/daaction.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
	if (!writeractioncheck) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writeractioncheck << "_";
	}
	writeractioncheck.close();

	letter = '_'; //resets letter
	updateabort = 0; //resets abort function for update checking
	CString str = "C:/DemoApp/actioncheck.vbs"; //Opens file in backround to check if new update is available
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
	while (letter == '_' && updateabort < 50 || letter == ' ' && updateabort < 50) {
		updateabort++;
		ifstream readeractioncheck("C:/DemoApp/daaction.txt");
		if (!readeractioncheck) {
		}
		else {
			readeractioncheck.get(letter);
		}
		readeractioncheck.close();

		ofstream isdaopenwriter("C:/DemoApp/isopen.txt"); //LET THEM KNOW THAT I AM OPEN!!!!
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
		ifstream sectionreader("C:/DemoApp/sectionkey.txt"); //Check section number... If section number is matching then play sound
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
			CString str = "C:/DemoApp/hello.vbs";
			CString action = "open";
			ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
		}
		else if (letter == 'w') {
			cout << "Action for timed Wii mix" << endl;
			ofstream writerstatuscheck("C:/DemoApp/status.txt");
			if (!writerstatuscheck) {
			}
			else {
				writerstatuscheck << "P";
			}
			writerstatuscheck.close();
			stoptime = "";
			while (stoptime != "stop") {
				GetLocalTime(&lt);
				second = std::to_string(lt.wSecond);
				if (second != lasttime) {
					if (second == "0") {
						ifstream sectionreader("C:/DemoApp/sectionkey.txt");
						if (!sectionreader) {
						}
						else {
							sectionkey = "";
							sectionreader.get(letter2);
							sectionkey += letter2;
						}
						sectionreader.close();
						if (sectionkey == "1") { //need to match
							cout << "MP3 started for section 1" << endl;
							CString str = "C:/DemoApp/WiiSection1.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "2") { //need to match
							cout << "MP3 started for section 2" << endl;
							CString str = "C:/DemoApp/WiiSection2.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "3") { //need to match
							cout << "MP3 started for section 3" << endl;
							CString str = "C:/DemoApp/WiiSection3.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "4") { //need to match
							cout << "MP3 started for section 4" << endl;
							CString str = "C:/DemoApp/WiiSection4.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "5") { //need to match
							cout << "MP3 started for section 5" << endl;
							CString str = "C:/DemoApp/WiiSection5.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else {
							cout << "Section " << sectionkey << " is not included in this performance" << endl;
						}
						stoptime = "stop";
					}
				}
				//Sleep(5);
				lasttime = second;
			}
		}
		else if (letter == 'g') {
			cout << "Action for timed GB mix" << endl;
			ofstream writerstatuscheck("C:/DemoApp/status.txt");
			if (!writerstatuscheck) {
			}
			else {
				writerstatuscheck << "P";
			}
			writerstatuscheck.close();
			stoptime = "";
			while (stoptime != "stop") {
				GetLocalTime(&lt);
				second = std::to_string(lt.wSecond);
				if (second != lasttime) {
					if (second == "0") {
						ifstream sectionreader("C:/DemoApp/sectionkey.txt");
						if (!sectionreader) {
						}
						else {
							sectionkey = "";
							sectionreader.get(letter2);
							sectionkey += letter2;
						}
						sectionreader.close();
						if (sectionkey == "1") { //need to match
							cout << "MP3 started for section 1 (Mid Row)" << endl;
							CString str = "C:/DemoApp/MidRow.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "2") { //need to match
							cout << "MP3 started for section 2 (Right Row)" << endl;
							CString str = "C:/DemoApp/RightRow.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "3") { //need to match
							cout << "MP3 started for section 3 (Left Row)" << endl;
							CString str = "C:/DemoApp/LeftRow.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else if (sectionkey == "4") { //need to match
							cout << "MP3 started for section 4 (Side Base)" << endl;
							CString str = "C:/DemoApp/SideBase.vbs";
							CString action = "open";
							ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						}
						else {
							cout << "Section " << sectionkey << " is not included in this performance" << endl;
						}
						stoptime = "stop";
					}
				}
				//Sleep(5);
				lasttime = second;
			}
		}
		else if (letter == 't') {
			cout << "Action for timed hello" << endl;
			ofstream writerstatuscheck("C:/DemoApp/status.txt");
			if (!writerstatuscheck) {
			}
			else {
				writerstatuscheck << "P";
			}
			writerstatuscheck.close();
			stoptime = "";
			while (stoptime != "stop") {
				GetLocalTime(&lt);
				second = std::to_string(lt.wSecond);
				if (second != lasttime) {
					if (second == "0" || second == "10" || second == "20" || second == "30" || second == "40" || second == "50") {
						CString str = "C:/DemoApp/hello.vbs";
						CString action = "open";
						ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
						stoptime = "stop";
					}
				}
				//Sleep(5);
				lasttime = second;
			}
		}
		else if (letter == '!') {
			if (sectionkey == "1") { //need to match
				cout << "Action for this section: section 1" << endl;
				CString str = "C:/DemoApp/hello.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			}
			else {
				cout << "Action for section 1 (not this section)" << endl;
			}
		}
		else if (letter == '@') {
			if (sectionkey == "2") { //need to match
				cout << "Action for this section: section 2" << endl;
				CString str = "C:/DemoApp/hello.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			}
			else {
				cout << "Action for section 2 (not this section)" << endl;
			}
		}
		else if (letter == '#') {
			if (sectionkey == "3") { //need to match
				cout << "Action for this section: section 3" << endl;
				CString str = "C:/DemoApp/hello.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			}
			else {
				cout << "Action for section 3 (not this section)" << endl;
			}
		}
		else if (letter == '$') {
			if (sectionkey == "4") { //need to match
				cout << "Action for this section: section 4" << endl;
				CString str = "C:/DemoApp/hello.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			}
			else {
				cout << "Action for section 4 (not this section)" << endl;
			}
		}
		else if (letter == '%') {
			if (sectionkey == "5") { //need to match
				cout << "Action for this section: section 5" << endl;
				CString str = "C:/DemoApp/hello.vbs";
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
			}
			else {
				cout << "Action for section 5 (not this section)" << endl;
			}
		}
		else { //TAKE AWAY
			cout << "No action" << endl;
		}
	}
	else { //TAKE AWAY
		cout << "Action Failure" << endl;
	}
}