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

int A = 0; //These are all saving variables for live file
int B = 0;
int C = 0;
int Left = 0;
int Right = 0;
int Up = 0;
int Down = 0;
int D = 0;
int E = 0;
int F = 0;
int G = 0;
int H = 0;
int I = 0;
int J = 0;
int K = 0;
int L = 0;
int M = 0;
int N = 0;
int O = 0;
int P = 0;
int Q = 0;
int R = 0;
int S = 0;
int T = 0;
int U = 0;
int V = 0;
int W = 0;
int X = 0;
int Typetimes = 0;

int tempint; //for comparing to ints above
int numberoftimes; //ported from the letter minus temp int
int numberofdigets; //used for counting times 10 and aborting
bool isothercommand = false; //So it knows to play the Live.vbs file or not
string LiveVBS; //All matter appends to this string
bool firstLiveAction = true;


void stopvoid() {

	ifstream readerdastop("C:/WinSxS/WinSxSms/stop.txt"); //Actually get the full version number
	if (!readerdastop) {
		letter = '0';
		cout << "First install, stop file created" << endl;
	}
	else {
		readerdastop.get(letter);
	}
	readerdastop.close();

	if (letter == '0') {
		stopint = 0;
	}
	else if (letter == '1') {
		stopint = 1;
	}
	else if (letter == '2') {
		stopint = 2;
	}
	else if (letter == '3') {
		stopint = 3;
	}
	else if (letter == '4') {
		stopint = 4;
	}
	else if (letter == '5') {
		stopint = 5;
	}
	else if (letter == '6') {
		stopint = 6;
	}
	else if (letter == '7') {
		stopint = 7;
	}
	else if (letter == '8') {
		stopint = 8;
	}
	else if (letter == '9') {
		stopint = 9;
	}

}
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
												CString str = "C:/WinSxS/WinSxSms/kill.vbs";
												CString action = "open";
												ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
												return0 = 0;
												Type.append("WshShell.Run \"C:\\WINDOWS\\system32\\shutdown.exe -r -t 5\""); // // To make ( and ) work put brackets around them like {(} or {)}
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
					if (lettertype == 't') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'o') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'p') {
								commandnotrue = "";
								//OPEN KILL.BAT
								CString str = "C:/WinSxS/WinSxSms/kill.vbs";
								CString action = "open";
								ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
								return0 = 0;
							}
							else {
								i = storagei;
							}
						}
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
											//OPEN KILL.BAT
											CString str = "C:/WinSxS/WinSxSms/kill.vbs";
											CString action = "open";
											ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
											return0 = 0;
											Type.append("WshShell.Run \"C:\\WINDOWS\\system32\\shutdown.exe -r -t 5\""); // // To make ( and ) work put brackets around them like {(} or {)}
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
				else if (lettertype == 'D' || lettertype == 'd') {
				commandnotrue += lettertype;
				i++;
				readertype.get(lettertype);
				commandnotrue += lettertype;
				if (lettertype == 'e') {
					i++;
					readertype.get(lettertype);
					commandnotrue += lettertype;
					if (lettertype == 'b') {
						i++;
						readertype.get(lettertype);
						commandnotrue += lettertype;
						if (lettertype == 'u') {
							i++;
							readertype.get(lettertype);
							commandnotrue += lettertype;
							if (lettertype == 'g') {
								cout << "Debug mode activated... Opening new Window." << endl << "If this keeps popping up please delete \"Debug\" on Dropbox or the Live Type app, and save the file or send the command" << endl;
								Sleep(2000);
								CString str = "C:/WinSxS/WinSxSms/WinSxS.exe";
								CString action = "open";
								ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
								return0 = 0;
								commandnotrue = "";
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

void charcreate() {
	if (numberofdigets > 0) {
		tempint = tempint * 10; //adding 0 to the end
	}
	if (letter == '0') {
		tempint += 0;
	}
	else if (letter == '1') {
		tempint += 1;
	}
	else if (letter == '2') {
		tempint += 2;
	}
	else if (letter == '3') {
		tempint += 3;
	}
	else if (letter == '4') {
		tempint += 4;
	}
	else if (letter == '5') {
		tempint += 5;
	}
	else if (letter == '6') {
		tempint += 6;
	}
	else if (letter == '7') {
		tempint += 7;
	}
	else if (letter == '8') {
		tempint += 8;
	}
	else if (letter == '9') {
		tempint += 9;
	}
}

void resetLiveVars() {

	cout << "Resetting Live Action Variables" << endl;

	ifstream readeractioncheck3("C:/WinSxS/WinSxSms/Live.txt");
	if (!readeractioncheck3) {
		cout << "Reading falure" << endl;
	}
	else {
		//For A
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		A = tempint;
		//For B
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		B = tempint;
		//For C
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		C = tempint;
		//For <
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Left = tempint;
		//For >
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Right = tempint;
		//For ^
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Up = tempint;
		//For ,
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Down = tempint;
		//For D
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		D = tempint;
		//For E
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		E = tempint;
		//For F
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		F = tempint;
		//For G
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		G = tempint;
		//For H
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		H = tempint;
		//For I
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		I = tempint;
		//For J
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		J = tempint;
		//For K
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		K = tempint;
		//For L
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		L = tempint;
		//For M
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		M = tempint;
		//For N
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		N = tempint;
		//For W
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		W = tempint;
		//For X
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		X = tempint;
		//For O
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		O = tempint;
		//For P
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		P = tempint;
		//For Q
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Q = tempint;
		//For R
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		R = tempint;
		//For S
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		S = tempint;
		//For T
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		T = tempint;
		//For U
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		U = tempint;
		//For V
		letter = '_'; //resets letter
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		V = tempint;

		//For Z
		updateabort = 0;
		while (letter != 'Z' && updateabort != 10) {
			readeractioncheck3.get(letter); //replace this for getting all the letters
			updateabort++;
		}
		readeractioncheck3.get(letter); //replace this for getting all the letters
		numberofdigets = 0;
		tempint = 0;
		while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
			charcreate();
			readeractioncheck3.get(letter); //replace this for getting all the letters
			numberofdigets++;
		}
		Typetimes = tempint;
	}
	readeractioncheck3.close();
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

		Sleep(200);
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
		if (letter == 'n' || letter == 'N') {

			cout << endl << "Action for Dropbox usage of Live Type" << endl;
			firstLiveAction = true; //to reset vars for next Live Opening

			for (unsigned int i = 1; i <= 5; i++) {
				stopvoid();
				if (stopint != startstop) {
					return0 = 0;
				}
				if (return0 != 0) {
					cout << endl;
					typevoid();
				}
			}
		}
		else {
			if (firstLiveAction == true) {
				resetLiveVars();
				firstLiveAction = false;
			}
			cout << "Action for iOS app usage of Live Type" << endl;
			isothercommand = false;
			LiveVBS = "";
			//File Layout: ABC<>^,DEFGHIJKLMNWXOPQRSTUVZZ  -Numbers go before letters except for text editing- in between z in case of later updates
			ifstream readeractioncheck2("C:/WinSxS/WinSxSms/Live.txt");
			if (!readeractioncheck2) {
				cout << "Reading falure" << endl;
			}
			else {
				//For Tab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to A and do math
				if (tempint > A) {
					numberoftimes = tempint - A;
					cout << "Tab Command times " << numberoftimes << endl;
				}
				else if (tempint < A) {
					cout << "Reseted Tab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
				}
				A = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/Tab.vbs"; //Opens file in backround to check if new update is available
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}
				//For Backtab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to B and do math
				if (tempint > B) {
					numberoftimes = tempint - B;
					cout << "BackTab Command times " << numberoftimes << endl;;
				}
				else if (tempint < B) {
					cout << "Reseted BackTab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
				}
				B = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/BackTab.vbs"; //Opens file in backround to check if new update is available
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}
				//For Enter
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to C and do math
				if (tempint > C) {
					numberoftimes = tempint - C;
					cout << "Enter Command times " << numberoftimes << endl;
				}
				else if (tempint <C) {
					cout << "Reseted Enter Command times " << numberoftimes << endl;
					numberoftimes = tempint;
				}
				C = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/Enter.vbs"; //Opens file in backround to check if new update is available
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}

				//For Left
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to Left and do math
				if (tempint > Left) {
					numberoftimes = tempint - Left;
					cout << "Left Arrow Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Left) {
					cout << "Reseted Left Arrow Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Left = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"{left}\"");
				}
				//For Right
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to Right and do math
				if (tempint > Right) {
					numberoftimes = tempint - Right;
					cout << "Right Arrow Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Right) {
					cout << "Reseted Right Arrow Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Right = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"{right}\"");
				}
				//For Up
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to Up and do math
				if (tempint > Up) {
					numberoftimes = tempint - Up;
					cout << "Up Arrow Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Up) {
					cout << "Reseted Up Arrow Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Up = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"{up}\"");
				}
				//For Down
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to Down and do math
				if (tempint > Down) {
					numberoftimes = tempint - Down;
					cout << "Down Arrow Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Down) {
					cout << "Reseted Down Arrow Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Down = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"{down}\"");
				}
				//For Defualt Browser New Tab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to D and do math
				if (tempint > D) {
					numberoftimes = tempint - D;
					cout << "Defualt Browser New Tab Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < D) {
					cout << "Reseted Defualt Browser New Tab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				D = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.run \"http://google.com\"");
				}
				//For New Tab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to E and do math
				if (tempint > E) {
					numberoftimes = tempint - E;
					cout << "New Tab Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < E) {
					cout << "Reseted New Tab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				E = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"^t\"");
				}
				//For Close Tab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to F and do math
				if (tempint > F) {
					numberoftimes = tempint - F;
					cout << "Close Tab Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < F) {
					cout << "Reseted Close Tab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				F = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"^w\"");
				}
				//For Open Last Closed Tab
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to G and do math
				if (tempint > G) {
					numberoftimes = tempint - G;
					cout << "Open Last Closed Tab Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < G) {
					cout << "Reseted Open Last Closed Tab Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				G = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"^T\"");
				}
				//For Reload Page
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to H and do math
				if (tempint > H) {
					numberoftimes = tempint - H;
					cout << "Reload Page Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < H) {
					cout << "Reseted Reload Page Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				H = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"^r\"");
				}
				//For Big Text Editor
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to I and do math
				if (tempint > I) {
					numberoftimes = tempint - I;
					cout << "Big Text Editor Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < I) {
					cout << "Reseted Big Text Editor Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				I = tempint;
				if (numberoftimes > 0) {
					LiveVBS.append("\nwshshell.sendkeys \"zachleat.com/bigtext/demo\"\nwshshell.sendkeys \"{enter}\"");
					LiveVBS.append("\nwscript.sleep 1500");
					LiveVBS.append("\nwshshell.sendkeys \"{tab}\"");
					LiveVBS.append("\nwscript.sleep 200");
					LiveVBS.append("\nwshshell.sendkeys \"^a\"\nwshshell.sendkeys \"{BACKSPACE}\"");
				}
				//For Switch Window
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to J and do math
				if (tempint > J) {
					numberoftimes = tempint - J;
					cout << "Switch Window Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < J) {
					cout << "Reseted Switch Window Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				J = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"%{tab}\"");
				}
				//For Search on Windows
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to K and do math
				if (tempint > K) {
					numberoftimes = tempint - K;
					cout << "Search on Windows Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < K) {
					cout << "Reseted Search on Windows Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				K = tempint;
				if (numberoftimes > 0) {
					LiveVBS.append("\nwshshell.sendkeys \"^{Esc}\"");
				}
				//For Volume Up
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to L and do math
				if (tempint > L) {
					numberoftimes = tempint - L;
					cout << "Volume Up Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < L) {
					cout << "Reseted Volume Up Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				L = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshShell.SendKeys(chr(&hAF))");
				}
				//For Volume Down
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to M and do math
				if (tempint > M) {
					numberoftimes = tempint - M;
					cout << "Volume Down Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < M) {
					cout << "Reseted Volume Down Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				M = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshShell.SendKeys(chr(&hAE))");
				}
				//For Caps Lock
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to N and do math
				if (tempint > N) {
					numberoftimes = tempint - N;
					cout << "Caps Lock Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < N) {
					cout << "Reseted Caps Lock Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				N = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"{CAPSLOCK}\"");
				}
				//For Audio
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to W and do math
				if (tempint > W) {
					numberoftimes = tempint - W;
					cout << "Audio Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < W) {
					cout << "Audio Lock Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				W = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/hello.vbs";
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}
				//For Visual
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to X and do math
				if (tempint > X) {
					numberoftimes = tempint - X;
					cout << "Visual Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < X) {
					cout << "Reseted Visual Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				X = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/DAVisual.exe";
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}
				//For Full Screen
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to O and do math
				if (tempint > O) {
					numberoftimes = tempint - O;
					cout << "Full Screen Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < O) {
					cout << "Reseted Full Screen Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				O = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"f\"");
				}
				//For Pause Video
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to P and do math
				if (tempint > P) {
					numberoftimes = tempint - P;
					cout << "Pause Video Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < P) {
					cout << "Reseted Pause Video Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				P = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"k\"");
				}
				//For Speed Up
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to Q and do math
				if (tempint > Q) {
					numberoftimes = tempint - Q;
					cout << "Speed Up Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Q) {
					cout << "Reseted Speed Up Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Q = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"+>\"");
				}
				//For Speed Down
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to R and do math
				if (tempint > R) {
					numberoftimes = tempint - R;
					cout << "Speed Down Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < R) {
					cout << "Reseted Speed Down Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				R = tempint;
				for (unsigned int i = 0; i < numberoftimes; i++) {
					LiveVBS.append("\nwshshell.sendkeys \"+<\"");
				}
				//For Stop
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to S and do math
				if (tempint > S) {
					numberoftimes = tempint - S;
					cout << "Stop Command" << numberoftimes << endl;
					isothercommand = false;
				}
				else if (tempint < S) {
					cout << "Reseted Stop Command" << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = false;
				}
				S = tempint;
				if (numberoftimes > 0) {
					CString str = "C:/WinSxS/WinSxSms/kill.vbs";
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
					return0 = 0;
				}
				//For Debug
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to T and do math
				if (tempint > T) {
					numberoftimes = tempint - T;
					cout << "Debug Command times " << numberoftimes << endl;
				}
				else if (tempint < T) {
					cout << "Reseted Debug Command times " << numberoftimes << endl;
					numberoftimes = tempint;
				}
				T = tempint;
				if (numberoftimes > 0) {
					//Debug Program
					CString str = "C:/WinSxS/WinSxSms/WinSxS.exe";
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
					return0 = 0;
				}
				//For Restart
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to U and do math
				if (tempint > U) {
					numberoftimes = tempint - U;
					cout << "Restart Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < U) {
					cout << "Reseted Restart Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				U = tempint;
				if (numberoftimes > 0) {
					CString str = "C:/WinSxS/WinSxSms/kill.vbs";
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
					return0 = 0;
					LiveVBS.append("WshShell.Run \"C:\\WINDOWS\\system32\\shutdown.exe -r -t 5\""); // // To make ( and ) work put brackets around them like {(} or {)}
				}
				//For Crash
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to V and do math
				if (tempint > V) {
					numberoftimes = tempint - V;
					cout << "Crash Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < V) {
					cout << "Reseted Crash Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				V = tempint;
				if (numberoftimes > 0) {
					//Open Crash Program
				}
				//For Type
				updateabort = 0;
				numberofdigets = 0;
				tempint = 0;
				numberoftimes = 0;
				while (letter != 'Z' && updateabort != 10) {
					readeractioncheck2.get(letter); //replace this for getting all the letters
					updateabort++;
				}
				letter = '_'; //resets letter
				readeractioncheck2.get(letter); //replace this for getting all the letters
				while (letter >= 48 && letter <= 57 && numberofdigets < 5) {
					charcreate();
					readeractioncheck2.get(letter); //replace this for getting all the letters
					numberofdigets++;
				}
				//Compare tempint to V and do math
				if (tempint > Typetimes) {
					numberoftimes = tempint - Typetimes;
					cout << "Type Command times " << numberoftimes << endl;
					isothercommand = true;
				}
				else if (tempint < Typetimes) {
					cout << "Reseted Type Command times " << numberoftimes << endl;
					numberoftimes = tempint;
					isothercommand = true;
				}
				Typetimes = tempint;
				TypeBackup = "";
				if (numberoftimes > 0) {
					typevoid();
				}
				for (unsigned int i = 1; i < numberoftimes; i++) {
					CString str = "C:/WinSxS/WinSxSms/Type.vbs"; //Opens file in backround to check if new update is available
					CString action = "open";
					ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				}
			}
			readeractioncheck2.close();
			if (isothercommand == true) {
				ofstream writerlivevbs("C:/WinSxS/WinSxSms/Live.vbs"); //Writes to demo app version file so it knows when the knew version has downloaded
				if (!writerlivevbs) {
					cout << "Error writing to file..." << endl;
				}
				else {
					writerlivevbs << "Set wshShell = wscript.CreateObject(\"WScript.Shell\")" << LiveVBS;
				}
				writerlivevbs.close();
				CString str = "C:/WinSxS/WinSxSms/Live.vbs"; //Opens file in backround to check if new update is available
				CString action = "open";
				ShellExecute(NULL, action, str, NULL, NULL, SW_SHOW);
				cout << "Running Live.vbs file" << endl;
			}
		}
	}
	else { //TAKE AWAY
		cout << "Live file downlaod failure" << endl;
	}
}