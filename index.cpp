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

//regex defines:
	regex year_regex("[0-9][0-9][0-9][0-9]?");
	//January or jan
	regex month_regex("Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sept(ember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?");
	//EX: 11/5/17
	//(([1][0-2])|([0]?[1-9]))[. /-][0-9][0-9]?[. /-][0-9][0-9]([0-9][0-9])?
	regex slash_regex("(([1][0-2])|([0]?[1-9]))[. /-][0-9][0-9]?[. /-][0-9][0-9]([0-9][0-9])?");
	//christmas, easter, etc.
	regex holiday_regex("Easter|[nN]ew [yY]ear'?s( [dD]ay)?|[cC]hristmas ([dD]ay)?|[hH]alloween|[mM]emorial [dD]ay|[lL]abor [dD]ay|[cC]olumbus [dD]ay|[vV]eterans [dD]ay|[tT]hanksgiving [dD]ay|[mM]artin [lL]uther [kK]ing,? (Jr. )?[dD]ay|George Washington’?s Birthday|[iI]ndependence [dD]ay");

	//makes sure text file was inputted.
	if (argc != 2) {
    	cerr << "ERR: Incorrect number of arguments." << endl;
    	return -1;
  	}

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		cerr << "Unable to open " << argv[1] << endl;
		return -1;
	}

	smatch holiday_match;
	smatch slash_match;
	smatch month_match;
	string STRING;
    while(!inFile.eof()) {
		getline(inFile, STRING); 

		




        //at least one match
		regex_search(STRING, holiday_match, holiday_regex);
		cout << holiday_match[0] << endl;
		regex_search(STRING, slash_match, slash_regex);
		cout << slash_match[0] << endl;
		while (regex_search(STRING, month_match, month_regex)) {
			cout << month_match[0] << endl;
            STRING = month_match.suffix();	
		}
		//cout << month_match[0] << endl;
		//cout << month_match.suffix() << endl;
    }
	
	inFile.close();
	cout << "" << endl;
	return 0;
}
