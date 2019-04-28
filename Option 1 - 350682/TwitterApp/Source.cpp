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

vector<string>currentVector;

vector<string> KeywordMenu = {
	"1 - Show tweets that mention Paris",
	"2 - Show tweets that mention Dreamworks",
	"3 - Show Tweets that mention Uber"
};

vector<string> CountMenu = {
	"1 - ",
	"2 - ",
	"3 - "
};

int MenuChoice = 0;
bool keywords;
bool countTweets;

void Menu() {
	cout << "       {{{{{{{{{}}}}}}}}}" << endl;
	cout << "{{{{{{{{  Search Tweets }}}}}}}}" << endl;
	cout << "       {{{{{{{{{}}}}}}}}}" << endl;
	vector<string> menuChoices = {
		"1 - Show Tweets from Keywords",
		"2 - Count Tweets",
		"3 - Search for a Tweet",
		"4 - Count Total Tweets",
		"5 - Close Software"
	};
	for (int i = 0; i < menuChoices.size(); i++) {
		cout << endl;
		cout << menuChoices[i] << endl;
		cout << endl;
	}
	cout << endl;

	cin >> MenuChoice;
}

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

void CurrentMenu() { //Get current menu and display it
	cout << endl;

	if (keywords) {
		currentVector = KeywordMenu;
	}

	if (countTweets) {

	}

	for (int i = 0; i < currentVector.size(); i++) {
		cout << currentVector[i];
		cout << endl;
		cout << "---------------" << endl;
	}
}


int main() {

	inFile.open("sampleTweets.csv");

	if (!inFile) {
		cout << "Unable to open file" << endl;
	}

	Menu();
	cout << "Enter your choice corressponding to the menu: " << endl;
	cin >> MenuChoice;

	do {
		Menu();
		cout << "Enter a word to search: " << endl;
		if (cin.fail()) {
			cout << "Invalid Input ..." << endl;
		}
	} while (MenuChoice != 5);

	switch (MenuChoice)
	{
	case 1:
		system("CLS");
		keywords = true;
		CurrentMenu();
		break;
	case 2:
		system("CLS");
		countTweets = true;
		break;
		CurrentMenu();
		break;
	case 3:
		system("CLS");
		cout << "Enter a word to search and all tweets with that word will be shown: " << endl;
		cin >> searchWord;
		DisplayTweets();
		break;

	}

	system("pause");
}