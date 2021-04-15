//-------------------------------------------------------------------------
// Name: Music Info Formatter
//
// Purpose: This program formats user input for song/album info and outputs
//	it in an easy to read format. The user will input the artist name,
//	album name, and track name (separated by hyphens), the length of the
//	track in seconds, and the copyright date of the song/album. The
//  program will list the song and album names, format the time into
//  minutes and seconds, and list the copyright owner and date of the song.
//
// Programmer: Josh Megahan
//
// Created: 10/17/15
//
// Modified: 10/18/15 Josh Megahan - finished formatting output
//-------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(void)
{
	string input;			  //input for artist, album, and track name
	string artist;			  //artist name
	string album;			  //album name
	string track;			  //track name
	string day;			      //despite never being used in the output the assignment asks that day be determined as well.
	string month;		      //despite never being used in the output the assignment asks that month be determined as well.
	string date;		      //input for copyright date
	string year;		      //the year to be taken from the date
	int hyphen1, hyphen2;	  //positions of the hypen delimeters used for separating the input
	int seconds, minutes;     //input for time in seconds, and the minutes for the conversion
	int slashPos1, slashPos2; //positions of forward slashes in the date input 
	int yearBint;			  //the last two digits of the year as integer values
	char y3, y4;              //the last two digits of the year as individual char values

	ofstream outfile ("year.txt");


	//Input Artist, Album, and Track
	//--------------------------------------------------------------------
	//First, the needed input will be described to the user.
	//The first line will ask for the artist name, album name, and track
	//name, all separated by hyphens (-)
	cout << "This program organizes and formats info about your music. "<< endl
		 << "Start by inputing: Artist Name - Album Name - Track Name " << endl
		 << "Type useing the above format with hyphens and spaces: " << endl;
	getline(cin,input);
	cout << endl;

	//Take sbstrings of the input using the hyphens as delimiters.
	//Assign substrings to appropriate variables.
	hyphen1 = input.find('-', 0);
	artist = input.substr(0, hyphen1 - 1);
	hyphen2 = input.find('-', hyphen1 + 1);
	album = input.substr(hyphen1 + 2, hyphen2 - hyphen1 - 2);
	hyphen1 = input.rfind('-');
	track = input.substr(hyphen1 + 2);



	//Input Time
	//--------------------------------------------------------------------
	//next input request will be for the track length in seconds;
	cout << "Input the track length in seconds: " << endl;
	cin >> seconds;
	cin.ignore();
	cout << endl;

	//The seconds will be recalculated into minutes and seconds using division and modular division.
	minutes = seconds / 60;
	seconds = seconds % 60;
	//Padding for any zeroes that may occur in the seconds section will be taken care of in the output at the end.



	//Input Date
	//--------------------------------------------------------------------
	//Lastly the program will ask for the copyright date, separating day month and year with '/'s
	cout << "Input the copyright date for this music." << endl
		 << "Format the day, month, and year with forward slashes (/): " << endl;
	getline(cin, date);
	cout << endl;

	//--------------------------------------------------------------------
	//Despite never being used in the output, this assignmnet asks for the
	//month and day to be determined from the input as well. The assignment
	//does not specify or give suggestion to what variabe type they
	// should be assigned to, since these values are never used.
	//--------------------------------------------------------------------
	slashPos1 = date.find('/');
	month = date.substr(0, slashPos1);
	slashPos2 = date.find('/', slashPos1 + 1);
	day = date.substr(slashPos1 + 1, slashPos2 - slashPos1 - 1);

	//The year will be extracted from the input using '/' as a delimiter
	year = date.substr(slashPos2 + 1);
	year = year;

	//the last two digits of the year are extracted
	string yearSecondHalf = year.substr(year.length() - 2, 2);

	//--------------------------------------------------------------------
	//If they user only typed out 2 digits for the year, the program
	//will assume any number between 00 and the current year's last two
	//digits, to be in the 21st century. Any higher double digit number
	//will be assumed to be in the last century. The two digits of the
	//assumed century, and the user defined digits will be written to a
	//text file for converting the assumed century to string format.
	//--------------------------------------------------------------------
	y3 = yearSecondHalf.front();
	y4 = yearSecondHalf.back();
	yearBint = ((y3 - 48) * 10) + y4 - 48;
	outfile << (20) - ((2000 + yearBint) / 2016) << endl << year;

	//close the open file, before it can be read from
	outfile.close();
	string assumedCentury;
	ifstream infile ("year.txt");
	infile >> assumedCentury >> year;
	cout << assumedCentury << "	" << year << endl << endl;
	year = assumedCentury + year;
	cout << year << endl<< endl;
	//take only the last 4 charcters of the string in case the user
	//defined 4 digits for the year. If such is the case the assumed
	//century will be removed from the string.
	year = year.substr(year.length() - 4, 4);



	//Output
	//---------------------------------------------------------------
	//The information will be output like so:
	//Album Name: Album Name
	//Track Name: Track Name
	//Run Time:	  00:00
	//Copyright (c) Artist Name, Year
	//---------------------------------------------------------------

	cout << left;
	cout << setw(13) << "Album Name:" << album << endl
		 << setw(13) << "Track Name:" << track << endl
		 << setw(13) << "Run Time:"  << minutes << ":" << right << setfill('0') << setw(2) << seconds << endl
		 << "Copyright (c) " << artist << ", " << setw(4) << year << endl << endl;

	infile.close();

	return 0;
}