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
int return0 = 1; //when = to 0 it returns 0
string Type; //used for text transfered from the type function
string TypeBackup; //used to compare against Type string to see if it should run the function or not
wchar_t lettertype; //for special charecters to remove the slanted '
int storagei; //sores the last storage of i in the loop so it it needs to jump back to it it can
string closeType; //indicates what type of charecter the script should close with. eg: " = quote, ") = quote par, or nothing
int repeat; //used for how many times to repeate functions eg. 4{tab} or 5{left}
string repeatstring; //used for the actual storage of the repeated action eg {tab} or {left]
string commandnotrue; //collects data on what the orriginal string was for typed commands incase it doesn't match up
int emergencyn; //if == 1 it will not append the next letter at the end


void typevoid() {

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
	if (letter != '_' && letter != ' ') {
		//open file and check against previous version if commands have changed, if they have continue
		//Get newly downloaded file
		Type = "Set Speak=CreateObject(\"sapi.spvoice\")\nSet wshShell = wscript.CreateObject(\"WScript.Shell\")\n";
		wifstream readertype("C:/WinSxS/WinSxSms/Type.txt");
		readertype.get(lettertype);
		for (int i = 0; !readertype.eof(); i++) {
			if (i == 0 || lettertype == '\n') {
				commandnotrue = "";
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
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'e') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'x') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 't') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == ' ') {
									commandnotrue = "";
									i++;
									readertype.get(lettertype);
									//do this for every charecter and put a delay in
									while (lettertype != '\n' && !readertype.eof()) {
										if (lettertype == 128 || lettertype == 153) { //this is to detect the bits used for the slanted apostrophe and replace it with a non-slanted one
											//do nothin
										}
										else {
											Type.append("wshshell.sendkeys \""); // To make ( and ) work put brackets around them like {(} or {)}
											if (lettertype == 226) {
												Type += '\'';
											}
											else if (lettertype == 40 || lettertype == 41) {
												Type.append("{");
												Type += lettertype;
												Type.append("}");
											}
											else {
												Type += lettertype;
											}
											Type.append("\"\nwscript.sleep 100\n");
										}
										i++;
										readertype.get(lettertype);
									}
									Type.pop_back();
									emergencyn = 1;
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
						commandnotrue += lettertype;
						if (lettertype == 'p') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'e') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == ' ') {
									commandnotrue = "";
									Type.append("wshshell.sendkeys \"");
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
				else if (lettertype == 'S' || lettertype == 's') {
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'a') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'y') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == ' ') {
								commandnotrue = "";
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
					else if (lettertype == 'h') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'u') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 't') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == 'd' || lettertype == 'D') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == 'o') {
										i++;
										readertype.get(lettertype);
										commandnotrue += lettertype;
										if (lettertype == 'w') {
											i++;
											readertype.get(lettertype);
											commandnotrue += lettertype;
											if (lettertype == 'n') {
												commandnotrue = "";
												Type.append("WshShell.Run \"C:\\WINDOWS\\system32\\shutdown.exe -r -t 0\""); // // To make ( and ) work put brackets around them like {(} or {)}
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
						}
					}
					else {
						i = storagei;
					}
				}
				else if (lettertype == 'R' || lettertype == 'r') {
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'e') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 's') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 't') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == 'a') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == 'r') {
										i++;
										readertype.get(lettertype);
										commandnotrue += lettertype;
										if (lettertype == 't') {
											commandnotrue = "";
											Type.append("WshShell.Run \"C:\\WINDOWS\\system32\\shutdown.exe -r -t 0\""); // // To make ( and ) work put brackets around them like {(} or {)}
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
					}
				}
				else if (lettertype == 'O' || lettertype == 'o') {
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'p') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'e') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'n') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == ' ') {
									commandnotrue = "";
									Type.append("wshshell.run \"http://");
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
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'a') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'i') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 't') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == ' ') {
									commandnotrue = "";
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
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'l') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'e') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'r') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == 't') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == ' ') {
										commandnotrue = "";
										Type.append("msgbox(\"");
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
				else if (lettertype == 'A' || lettertype == 'a') {
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'l') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'e') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'r') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == 't') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == ' ') {
										commandnotrue = "";
										Type.append("msgbox(\"");
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
				else if (lettertype == 'V' || lettertype == 'v') {
					commandnotrue += lettertype;
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'o') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'l') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'u') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == 'm') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == 'e') {
										i++;
										readertype.get(lettertype);
										commandnotrue += lettertype;
										if (lettertype == ' ') {
											commandnotrue = "";
											i++;
											readertype.get(lettertype);
											if (lettertype == 'U' || lettertype == 'u') {
												i++;
												readertype.get(lettertype);
												if (lettertype == 'p') {
													Type.append("wshShell.SendKeys(chr(&hAF))");
												}
											}
											else if (lettertype == 'D' || lettertype == 'd') {
												i++;
												readertype.get(lettertype);
												if (lettertype == 'o') {
													i++;
													readertype.get(lettertype);
													if (lettertype == 'w') {
														i++;
														readertype.get(lettertype);
														if (lettertype == 'n') {
															Type.append("wshShell.SendKeys(chr(&hAE))");
														}
													}
												}
											}
											else if (lettertype == 'F' || lettertype == 'f') {
												i++;
												readertype.get(lettertype);
												if (lettertype == 'u') {
													i++;
													readertype.get(lettertype);
													if (lettertype == 'l') {
														i++;
														readertype.get(lettertype);
														if (lettertype == 'l') {
															for (unsigned int c = 1; c <= 50; c++) {
																Type.append("wshShell.SendKeys(chr(&hAF))\n");
															}
														}
													}
												}
											}
											else if (lettertype == 'M' || lettertype == 'm') {
												i++;
												readertype.get(lettertype);
												if (lettertype == 'u') {
													i++;
													readertype.get(lettertype);
													if (lettertype == 't') {
														i++;
														readertype.get(lettertype);
														if (lettertype == 'e') {
															for (unsigned int c = 1; c <= 50; c++) {
																Type.append("wshShell.SendKeys(chr(&hAE))\n");
															}
														}
													}
												}
											}
											else if (lettertype == 'H' || lettertype == 'h') {
												i++;
												readertype.get(lettertype);
												if (lettertype == 'a') {
													i++;
													readertype.get(lettertype);
													if (lettertype == 'l') {
														i++;
														readertype.get(lettertype);
														if (lettertype == 'f') {
															for (unsigned int c = 1; c <= 50; c++) {
																Type.append("wshShell.SendKeys(chr(&hAE))\n");
															}
															for (unsigned int c = 1; c <= 25; c++) {
																Type.append("wshShell.SendKeys(chr(&hAF))\n");
															}
														}
													}
												}
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
				Type.append(commandnotrue);
			}
			else if (lettertype == 128 || lettertype == 153) { //this is to detect the bits used for the slanted apostrophe and replace it with a non-slanted one
				//do nothin
			}
			else if (lettertype == 226) {
				Type += '\'';
			}
			else if (lettertype == 40 && closeType == "quote" || lettertype == 41 && closeType == "quote") {
				Type.append("{");
				Type += lettertype;
				Type.append("}");
			}
			else if (lettertype == 'H' || lettertype == 'h') {
				commandnotrue = "";
				commandnotrue += lettertype;
				i++;
				readertype.get(lettertype);
				commandnotrue += lettertype;
				if (lettertype == 't') {
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 't') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'p') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == ':') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == '/') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == '/') {
										commandnotrue = "";
									}
									else {
										i = storagei;
										Type.append(commandnotrue);
									}
								}
								else {
									i = storagei;
									Type.append(commandnotrue);
								}
							}
							else if (lettertype == 's') {
								i++;
								readertype.get(lettertype);
								commandnotrue += lettertype;
								if (lettertype == ':') {
									i++;
									readertype.get(lettertype);
									commandnotrue += lettertype;
									if (lettertype == '/') {
										i++;
										readertype.get(lettertype);
										commandnotrue += lettertype;
										if (lettertype == '/') {
											commandnotrue = "";
										}
										else {
											i = storagei;
											Type.append(commandnotrue);
										}
									}
									else {
										i = storagei;
										Type.append(commandnotrue);
									}
								}
								else {
									i = storagei;
									Type.append(commandnotrue);
								}
							}
							else {
								i = storagei;
								Type.append(commandnotrue);
							}
						}
						else {
							i = storagei;
							Type.append(commandnotrue);
						}
					}
					else {
						i = storagei;
						Type.append(commandnotrue);
					}
				}
				else {
					i = storagei;
					Type.append(commandnotrue);
				}
			}
			else if (lettertype >= 48 && lettertype <= 57) { //for numbers
				repeatstring = "";
				if (lettertype == '0') {
					repeat = 0;
				}
				else if (lettertype == '1') {
					repeat = 1;
				}
				else if (lettertype == '2') {
					repeat = 2;
				}
				else if (lettertype == '3') {
					repeat = 3;
				}
				else if (lettertype == '4') {
					repeat = 4;
				}
				else if (lettertype == '5') {
					repeat = 5;
				}
				else if (lettertype == '6') {
					repeat = 6;
				}
				else if (lettertype == '7') {
					repeat = 7;
				}
				else if (lettertype == '8') {
					repeat = 8;
				}
				else if (lettertype == '9') {
					repeat = 9;
				}
				i++;
				readertype.get(lettertype);
				if (lettertype >= 48 && lettertype <= 57 && !readertype.eof()) {
					repeat = repeat * 10;//adding 0 to the end
					if (lettertype == '0') {
						repeat += 0;
					}
					else if (lettertype == '1') {
						repeat += 1;
					}
					else if (lettertype == '2') {
						repeat += 2;
					}
					else if (lettertype == '3') {
						repeat += 3;
					}
					else if (lettertype == '4') {
						repeat += 4;
					}
					else if (lettertype == '5') {
						repeat += 5;
					}
					else if (lettertype == '6') {
						repeat += 6;
					}
					else if (lettertype == '7') {
						repeat += 7;
					}
					else if (lettertype == '8') {
						repeat += 8;
					}
					else if (lettertype == '9') {
						repeat += 9;
					}
					i++;
					readertype.get(lettertype);
					if (lettertype >= 48 && lettertype <= 57 && !readertype.eof()) {
						repeat = repeat * 10;//adding another 0 to the end for 100
						if (lettertype == '0') {
							repeat += 0;
						}
						else if (lettertype == '1') {
							repeat += 1;
						}
						else if (lettertype == '2') {
							repeat += 2;
						}
						else if (lettertype == '3') {
							repeat += 3;
						}
						else if (lettertype == '4') {
							repeat += 4;
						}
						else if (lettertype == '5') {
							repeat += 5;
						}
						else if (lettertype == '6') {
							repeat += 6;
						}
						else if (lettertype == '7') {
							repeat += 7;
						}
						else if (lettertype == '8') {
							repeat += 8;
						}
						else if (lettertype == '9') {
							repeat += 9;
						}
						i++;
						readertype.get(lettertype);
						if (lettertype == '{') {
							updateabort = 0;
							while (lettertype != '}' && updateabort <= 13) {
								updateabort++;
								repeatstring += lettertype;
								i++;
								readertype.get(lettertype);
							}
							if (updateabort <= 13) {
								repeatstring += lettertype;
								if (repeatstring == "{Delete}" || repeatstring == "{delete}" || repeatstring == "{DELETE}") {
									repeatstring = "{BS}";
								}
								for (unsigned int d = 1; d <= repeat; d++) {
									Type.append(repeatstring);
								}
							}
						}
						else {
							cout << "At 3 letters" << endl;
							string repeatConversion = to_string(repeat); //put the number into a string
							Type.append(repeatConversion); //append string to Type
							if (!readertype.eof() && lettertype != '\n') {
								Type += lettertype; //append unused last charenter to Type
							}
							emergencyn = 1;
						}
					}
					else if (lettertype == '{') {
						updateabort = 0;
						while (lettertype != '}' && updateabort <= 13) {
							updateabort++;
							repeatstring += lettertype;
							i++;
							readertype.get(lettertype);
						}
						if (updateabort <= 13) {
							repeatstring += lettertype;
							if (repeatstring == "{Delete}" || repeatstring == "{delete}" || repeatstring == "{DELETE}") {
								repeatstring = "{BS}";
							}
							for (unsigned int d = 1; d <= repeat; d++) {
								Type.append(repeatstring);
							}
						}
					}
					else {
						string repeatConversion = to_string(repeat); //put the number into a string
						Type.append(repeatConversion); //append string to Type
						if (!readertype.eof() && lettertype != '\n') {
							Type += lettertype; //append unused last charenter to Type
						}
						emergencyn = 1;
					}
				}
				else if (lettertype == '{') {
					updateabort = 0;
					while (lettertype != '}' && updateabort <= 13) {
						updateabort++;
						repeatstring += lettertype;
						i++;
						readertype.get(lettertype);
					}
					if (updateabort <= 13) {
						repeatstring += lettertype;
						if (repeatstring == "{Delete}" || repeatstring == "{delete}" || repeatstring == "{DELETE}") {
							repeatstring = "{BS}";
						}
						for (unsigned int d = 1; d <= repeat; d++) {
							Type.append(repeatstring);
						}
					}
				}
				else {
					string repeatConversion = to_string(repeat); //put the number into a string
					Type.append(repeatConversion); //append string to Type
					if (!readertype.eof() && lettertype != '\n') {
						Type += lettertype; //append unused last charenter to Type
					}
					emergencyn = 1;
				}
			}
			else {
				Type += lettertype;
			}
			if (lettertype == '\n' && emergencyn == 1) {
				emergencyn = 0;
			}
			else {
				readertype.get(lettertype);
			}
		}
		if (lettertype == 40 && closeType == "quote" || lettertype == 41 && closeType == "quote") {
			Type.pop_back();
		}
		readertype.close();
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
	else {
		cout << "Type File Download Error";
	}

}


void actionvoid() {
	ofstream writeractioncheck("C:/WinSxS/WinSxSms/Live.txt"); //Writes to demo app version file so it knows when the knew version has downloaded
	if (!writeractioncheck) {
		cout << "Error writing to file..." << endl;
	}
	else {
		writeractioncheck << "_";
	}
	writeractioncheck.close();

	letter = '_'; //resets letter
	updateabort = 0; //resets abort function for update checking
	CString str = "C:/WinSxS/WinSxSms/livecheck.vbs"; //Opens file in backround to check if new update is available
	CString action = "open";
	ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
	while (letter == '_' && updateabort < 50 || letter == ' ' && updateabort < 50) {
		updateabort++;
		ifstream readeractioncheck("C:/WinSxS/WinSxSms/Live.txt");
		if (!readeractioncheck) {
		}
		else {
			readeractioncheck.get(letter); //replace this for getting all the letters
		}
		readeractioncheck.close();

		Sleep(300);
	}

	if (updateabort < 50) { //If the update failed to download it will still move on
		/*if (letter == 'a') {
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
		else if (letter == '0') {
			return0 = 0;
		} */
		if (letter == 'n' || 'N') {

			cout << endl << "Action for Dropbox usage of Live Type" << endl;

			for (unsigned int i = 1; i <= 5; i++) {

				cout << endl;

				typevoid();

			}
		}
		else { //TAKE AWAY
			cout << "Action for iOS app usage of Live Type" << endl;
		}
	}
	else { //TAKE AWAY
		cout << "Live file downlaod failure" << endl;
	}
}