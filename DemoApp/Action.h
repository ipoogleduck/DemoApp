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
wchar_t lettertype; //for special charecters to remove the slanted '
int storagei; //sores the last storage of i in the loop so it it needs to jump back to it it can
string closeType; //indicates what type of charecter the script should close with. eg: " = quote, ") = quote par, or nothing


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

			cout << endl << "Action for direct text keyboard writer" << endl;

			for (unsigned int i = 1; i <= 5; i++) {

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
				Type = "Set Speak=CreateObject(\"sapi.spvoice\")\nSet wshShell = wscript.CreateObject(\"WScript.Shell\")\n";
				wifstream readertype("C:/WinSxS/WinSxSms/Type.txt");
				for (int i = 0; !readertype.eof(); i++) {
					readertype.get(lettertype);
					if (i == 0 || lettertype == '\n') {
						storagei = i;
						if (lettertype == '\n') {
							if (closeType == "quote") { //add this to the end f every line
								Type.append("\"");
							}
							else if (closeType == "quotepar") {
								Type.append("\")");
							}
							closeType = "";
							Type += lettertype;
							i++;
							readertype.get(lettertype);
						}
						if (lettertype == 'T' || lettertype == 't') {
							i++;
							readertype.get(lettertype);
								if (lettertype == 'e') {
									i++;
									readertype.get(lettertype);
									if (lettertype == 'x') {
										i++;
										readertype.get(lettertype);
										if (lettertype == 't') {
											i++;
											readertype.get(lettertype);
											if (lettertype == ' ') {
												Type.append("wshshell.sendkeys \""); // To make ( and ) work put brackets around them like {(} or {)}
												closeType = "quote";
											}
											else {
												i = storagei;
											}
										}
										else {
											i = storagei;
										}
									}
									else {
										i = storagei;
									}
								}
								else if (lettertype == 'y') {
									i++;
									readertype.get(lettertype);
									if (lettertype == 'p') {
										i++;
										readertype.get(lettertype);
										if (lettertype == 'e') {
											i++;
											readertype.get(lettertype);
											if (lettertype == ' ') {
												Type.append("wshshell.sendkeys \""); // To make ( and ) work put brackets around them like {(} or {)}
												//do this for every charecter and put a delay in
												closeType = "quote";
											}
											else {
												i = storagei;
											}
										}
										else {
											i = storagei;
										}
									}
									else {
										i = storagei;
									}
								}
								else {
									i = storagei;
								}
						} else if (lettertype == 'S' || lettertype == 's') {
							i++;
							readertype.get(lettertype);
							if (lettertype == 'a') {
								i++;
								readertype.get(lettertype);
								if (lettertype == 'y') {
									i++;
									readertype.get(lettertype);
									if (lettertype == ' ') {
										Type.append("Speak.Speak \""); // // To make ( and ) work put brackets around them like {(} or {)}
										closeType = "quote";
									}
									else {
										i = storagei;
									}
								}
								else {
									i = storagei;
								}
							}
							else {
								i = storagei;
							}
						}
						else if(lettertype == 'O' || lettertype == 'o') {
							i++;
							readertype.get(lettertype);
							if (lettertype == 'p') {
								i++;
								readertype.get(lettertype);
								if (lettertype == 'e') {
									i++;
									readertype.get(lettertype);
									if (lettertype == 'n') {
										i++;
										readertype.get(lettertype);
										if (lettertype == ' ') {
											Type.append("wshshell.run \"www.");
											closeType = "quote";
										}
										else {
											i = storagei;
										}
									}
									else {
										i = storagei;
									}
								}
								else {
									i = storagei;
								}
							}
							else {
								i = storagei;
							}
						}
						else if (lettertype == 'W' || lettertype == 'w') {
							i++;
							readertype.get(lettertype);
							if (lettertype == 'a') {
								i++;
								readertype.get(lettertype);
								if (lettertype == 'i') {
									i++;
									readertype.get(lettertype);
									if (lettertype == 't') {
										i++;
										readertype.get(lettertype);
										if (lettertype == ' ') {
											Type.append("wscript.sleep ");
										}
										else {
											i = storagei;
										}
									}
									else {
										i = storagei;
									}
								}
								else {
									i = storagei;
								}
							}
							else {
								i = storagei;
							}
						}
						else if (lettertype == 'A' || lettertype == 'a') {
						i++;
						readertype.get(lettertype);
						if (lettertype == 'l') {
							i++;
							readertype.get(lettertype);
							if (lettertype == 'e') {
								i++;
								readertype.get(lettertype);
								if (lettertype == 'r') {
									i++;
									readertype.get(lettertype);
									if (lettertype == 't') {
										i++;
										readertype.get(lettertype);
										if (lettertype == ' ') {
											Type.append("msgbox(\""); // ( and ) not supported for some reason
											closeType = "quotepar";
										}
										else {
											i = storagei;
										}
									}
									else {
										i = storagei;
									}
								}
								else {
									i = storagei;
								}
							}
							else {
								i = storagei;
							}
						}
						else {
							i = storagei;
						}
						}
						else {
							i = storagei;
							Type += lettertype;
						}
					}
					else if (lettertype == 128 || lettertype == 153) { //this is to detect the bits used for the slanted apostrophe and replace it with a non-slanted one
						//do nothin
					}
					else if (lettertype == 226) {
						Type += '\'';
					}
					else {
						Type += lettertype;
					}
				}
				readertype.close();
				Type.pop_back();
				if (closeType == "quote") { //add this to the end of the last and final line
					Type.append("\"");
				}
				else if (closeType == "quotepar") {
					Type.append("\")");
				}
				closeType = "";
				cout << Type << endl;

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

					//read first word of each line, convert into the appropriate string, and save it as type.vbs
					//take out all apostrophes: ' ' ' and correct wrond quotes that lean to normal ones """
					//if word == type or Type, put each letter out slowly in the vbs file, with delay inbetween as if someone was typing
					//if word == text or Text, just put it into one type line with no delays
					//if word == say or Say, speak the contents of the line
					//if word == open or Open, open it as a website in the default browser
					//if word == wait or Wait, delay with milisecounds
					//if word == alert or Alert, create a popup meassage on the screen
					//if word is == shutdown or Shutdown, send shutdown/restart command to computer
					//if word is == volume or Volume, commands include up, down, full, mute
					//if word is unrecognized print it as it is, assuming it isn't a pre-programmed command
					//MAKE SURE NOTHING WILL HAPPEN IF READER ACCEDENTLY READS A UNDERSCORE _

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

				TypeBackup = Type;

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