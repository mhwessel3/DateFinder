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
	regex month_regex("/[jJ]an|[jJ]an|[fF]ebruary|[fF]eb|[mM]arch|[mM]ar|[aA]pril|[aA]pr|[mM]ay|[jJ]une|[jJ]un|[jJ]uly|[jJ]ul/g");
					//	[aA]ugust|[aA]ug|[sS]eptember|[sS]ept/");
					//	[oO]ctober|[oO]ct|[nN]ovember|[nN]ov|[dD]ecember|[dD]ec/");
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

	smatch month_match;
	string STRING;
    while(!inFile.eof()) {
		getline(inFile, STRING); 
        //at least one match
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
