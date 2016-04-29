#include <iostream>
#include <fstream>		
#include <iomanip>      // std::setprecision
#include "CJsonDeserializer.h"
#include "Profile.h"
#include "Quote.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Take file input either from command line or from console
	string fileName;
	cout << "profile name: ";
	if(argc > 1 ) {
		fileName = argv[1];
	}
	else {
		cin >> fileName;
	}
	//cout << endl;
	cout << fileName << endl;


	/// Read the file till the end
	string inputData, line;
	
	/// Open the file stream
	ifstream inputFile (fileName); 
	
	/// If file stream succeeds
	if(inputFile) {
		while( getline (inputFile, line) ) {
			inputData.append(line);
		}
	}
	else {
		cout << "Error to open the profile file. Please check the file path." << endl;
		return -1;
	}

	/// Deserialized JSON fileName is represented in "pofile" object
	Profile profile;
	CJsonDeserializer::Deserialize( &profile, inputData );

	/// Generates quote with generated profile
	Quote q;
	cout << "Quote: " << std::fixed << std::setprecision(2) << q.GetQuote(profile) << endl;
 
	return 0;
}

