#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string Tweets;
string TweetCount;
string searchWord;
ifstream inFile;
size_t pos;

void DisplayTweets() {

	while (inFile.good()) {
		getline(inFile, Tweets);
		pos = Tweets.find(searchWord);
		if (pos != string::npos) {
			cout << Tweets << endl;
			cout << endl;
		}
	}
	inFile.close();
}

int main() {

	inFile.open("sampleTweets.csv");

	if (!inFile) {
		cout << "Unable to open file" << endl;
	}

	cout << "Enter a word to search: " << endl;
	cin >> searchWord;
	if (cin.fail()) {
		cout << "Invalid Input ..." << endl;
	}
	DisplayTweets();

	system("pause");
}