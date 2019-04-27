#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string myData;
string SearchData;
ifstream inFile;

int main() {

	inFile.open("sampleTweets.csv"); //Open sampleTweets.csv

	if (!inFile) {
		cout << "Unable to open file" << endl;
	}



	system("pause");

	return 0;

}