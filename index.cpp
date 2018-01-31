#include <fstream>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

/**
 * AUTHOR: Morgan Wessel
 * COURSE: LING406 
 * SOURCES: 
 * (1) http://www.cplusplus.com/forum/beginner/8388/
 * Compile with: clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra index.cpp -o exe
 */
int main(int argc, char** argv) {
/*
	//REGEX DEFINES:
	regex year_regex("[0-9][0-9][0-9][0-9]");
	//January or jan
	regex month_regex("Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?");
	//EX: 11/5/17
	regex slash_regex("(([1][0-2])|([0]?[1-9]))[. /-][0-9][0-9]?[. /-][0-9][0-9]([0-9][0-9])?");
	//EX: christmas, easter, etc.
	regex holiday_regex("Easter|[nN]ew [yY]ear'?s( [dD]ay)?|[cC]hristmas ([dD]ay)?|[hH]alloween|[mM]emorial [dD]ay|[lL]abor [dD]ay|[cC]olumbus [dD]ay|[vV]eterans [dD]ay|[tT]hanksgiving [dD]ay|[mM]artin [lL]uther [kK]ing,? (Jr. )?[dD]ay|George Washington’?s Birthday|[iI]ndependence [dD]ay");
	//EX: January 8th, 2016
	regex month_day_year_regex("(Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?)( [0-9]?[0-9](st|nd|rd|th)?,?( [0-9][0-9][0-9][0-9])?)?");
	//EX: Monday, January 18th??
	regex wkday_month_num_year("(Sun|Mon|Tues|Wed(nes)?|Thurs|Fri|Sat(ur)?)(day)?(, )?(Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?)? ?([0-9]?[0-9])?(st|nd|rd|th)?(, )?([0-9][0-9][0-9][0-9])?");
*/
	regex whole_regex("(Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?) ?(([0-9][0-9][0-9][0-9])|([0-9]?[0-9])(st|nd|rd|th)?)?(, [0-9][0-9][0-9][0-9])?|(Sun|Mon|Tues|Wed(nes)?|Thurs|Fri|Sat(ur)?)(day)?(, )?(Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?)? ?([0-9]?[0-9])?(st|nd|rd|th)?(, )?([0-9][0-9][0-9][0-9])?|Easter|[nN]ew [yY]ear'?s( [dD]ay)?|[cC]hristmas ([dD]ay)?|[hH]alloween|[mM]emorial [dD]ay|[lL]abor [dD]ay|[cC]olumbus [dD]ay|[vV]eterans [dD]ay|[tT]hanksgiving [dD]ay|[mM]artin [lL]uther [kK]ing,? (Jr. )?[dD]ay|George Washington’?s Birthday|[iI]ndependence [dD]ay|(([1][0-2])|([0]?[1-9]))[. /-][0-9][0-9]?[. /-][0-9][0-9]([0-9][0-9])?|[0-9][0-9][0-9][0-9]");

	//checks that we have correct number of arguments
	if (argc != 2) {
    	cerr << "ERR: Incorrect number of arguments." << endl;
    	return -1;
  	}

	//makes sure the file can be read
	ifstream inFile; //stores the reference to the inputted file
	inFile.open(argv[1]);
	if (!inFile) {
		cerr << "Unable to open " << argv[1] << endl;
		return -1;
	}

	smatch line_match;
	string current_line;
    //read file line by line
	while(!inFile.eof()) {
		getline(inFile, current_line); 
		while (regex_search(current_line, line_match, whole_regex)) {
			cout << line_match[0] << endl;
			//reset the current line to the rest of the line to continue searching this line for matches
            current_line = line_match.suffix();
		}
    }
	
	inFile.close();
	return 0;
}
