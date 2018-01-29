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
 */
int main(int argc, char** argv) {

//regex defines:
	regex year_regex("[0-9][0-9][0-9][0-9]?");
 /*	regex month_regex("^[jJ]anuary | [jJ]an | 
					   [fF]ebruary | [fF]eb | 
					   [mM]arch | [mM]ar | 
					   [aA]pril | [aA]pr | 
					   [mM]ay | 
					   [jJ]une | [jJ]un |
					   [jJ]uly | [jJ]ul |
					   []"); */
	regex day_regex(".[0-9][0-9]?");
//	regex holiday_regex();
	regex e("/[mM]organ/");

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

	smatch m;
	string STRING;
    while(!inFile.eof()) {
		getline(inFile, STRING); 
	    if (regex_search(STRING, m, day_regex)) {
            cout << m[0] << endl;
        }
    }
	inFile.close();
	cout << "" << endl;
	return 0;
}
