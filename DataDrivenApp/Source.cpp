#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string Tweets;
string SearchingTweets;
string mySearch;
ifstream inFile;
size_t myTweet;

int main() {

	inFile.open("sampleTweets.csv"); //Open sampleTweets.csv

	cout << "type in a word to search: " << endl;
	cin >> mySearch;

	if (!inFile) {
		cout << "Unable to open file" << endl;
	}

	while (inFile.good()) {
		getline(inFile, SearchingTweets);
		myTweet = Tweets.find(mySearch);
	}

	system("pause");

	return 0;

}