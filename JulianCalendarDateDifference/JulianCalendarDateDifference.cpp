//----------------------------------------------------
// Purpsoe: This program calculates the differecne in
//          the number of days between a user-defined
//          current data and date in the past,
//          accounting for the change between the
//          Julian and Gregorian Calenders.
//
//          Task completed by parsing date input
//          strings to a printed file, reading values
//          back in as integers and then calculating.
// Author:	Josh Megahan
//----------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

long julian (int year, int month, int day);

long processDate(string &date);
void printOut(string date);
void readIn(int (&arr)[3]);
void assignDates(int &y, int &m, int &d, int(&arr)[3]);
void julianModify(int &y, int &m);

int main(void)
{
	string date;
	
	cout << "Let's calculate the number of days between today and some date in the past." << endl
		 << "Input the date using MM/DD/YYYY format. Use a negative (-) sign in front of" << endl
		 << "the year number to indicate the year as \"B.C.\" if it's meant to be B.C." << endl << endl
		 << "Input today's date: ";
	getline (cin, date);
	cout << endl << endl;

	long julPresent = processDate(date);

	cout << "Input date from past: ";
	getline (cin, date);
	cout << endl << endl;

	long julPast = processDate(date);

	cout << "The number of days between now and then is " << julPresent - julPast << "." << endl << endl;

	return 0;
}

long processDate(string &date)
{
	int dateArr[3];
	int d, m, y;

	printOut(date);
	readIn(dateArr);
	assignDates(y, m, d, dateArr);
	julianModify(y, m);
	return julian(y, m, d);
}

void printOut(string date)
{
	ofstream outfile("date.txt");
	outfile << date.substr(0, date.find('/')) << endl << date.substr(date.find('/') + 1, date.rfind('/') - date.find('/') - 1) << endl << date.substr(date.rfind('/') + 1);
	outfile.close();
}

void readIn(int (&arr)[3])
{
	ifstream infile("date.txt");
	infile >> arr[0] >> arr[1] >> arr[2];
	infile.close();
}

void assignDates(int &y, int &m, int &d, int(&dateArr)[3])
{
	m = dateArr[0];
	d = dateArr[1];
	y = dateArr[2];
}

void julianModify(int &y, int &m)
{
	if (y < 0) {
		y = y + 1;
	}
	if (m > 2) {
		m = m + 1;
	}
	else {
		m = m + 13;
		y = y - 1;
	}
}

long julian (int jy, int jm, int jd)
{
	long jul = floor(365.25 * jy) + floor (30.6001 * jm) + jd + 1720995.0;
	if (jy < 1582 || (jy == 1582 && jm < 9) || ( jy == 1582 && jm == 9 && jd < 15)) {
	} else {
		int ja = 0.01 * jy;
		jul = jul + 2 - ja + 0.25 *ja;
		return jul;
	}
	return jul;
}