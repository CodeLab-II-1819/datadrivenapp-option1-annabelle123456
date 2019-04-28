#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string Tweets; 
string searchWord; 
string searchCounter;
ifstream inFile; 
size_t fileLength; 
vector<string> currentVector; 

int linecount = 0;
int TweetCount = 0;

vector<string> KeywordMenu = { 
	" 1 - Show tweets that mention Paris",
	" 2 - Show tweets that mention Dreamworks",
	" 3 - Show Tweets that mention Uber",
	" 4 - Return to Main Menu"
};

vector<string> CountMenu = { 
	" 1 - Count Tweets mentioning LGBT",
	" 2 - Count Tweets mentioning politics",
	" 3 - Count Tweets mentioning technology",
	" 4 - Count Tweets mentioning money"
};

vector<string> politicalWords = { "congress","Congress","abortion","Abortion","president","President","immigration","Immigration", "election", "Election" }; // These vectors are search terms to accurately count the amount of tweets relating to a search term
vector<string> Inclusivness = { "LGBT", "gay", "Gay", "lesbian", "Lesbian", "#TransWeek", "transgender", "Transgender" };
vector<string> Technology = { "Phone", "phone", "Computer", "computer", "Tech", "tech", "coding", "c++", "C++", "Java", "iPhone", "Android", "iOS", "Samsung" };
vector<string> Money = { "$", "cash", "money", "Cash", "Money" };

int MenuChoice = 0; 
bool keywords; 
bool countTweets;
bool otherMenu; 
bool politics; 
bool LGBT;
bool tech;
bool money;

void Menu() { 
	cout << "       {{{{{{{{{}}}}}}}}}" << endl;
	cout << "{{{{{{{{  Search Tweets }}}}}}}}" << endl;
	cout << "       {{{{{{{{{}}}}}}}}}" << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	vector<string> menuChoices = {
		" 1 - Show Tweets from Keywords",
		" 2 - Count Tweets",
		" 3 - Custom Search",
		" 4 - Count Total Tweets",
		" 5 - Show ReTweets",
		" 6 - Show Teets @realDonaldTrump",
		" 7 - Show Tweets @Jlo",
		" 8 - Exit Program"
	};
	for (int i = 0; i < menuChoices.size(); i++) {
		cout << menuChoices[i] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	cout << endl;
}

void Keywords() {

	for (int i = 0; i < KeywordMenu.size(); i++) {
		cout << KeywordMenu[i] << endl;
	}
}

void DisplayTweets() {

	while (inFile.good()) {
		getline(inFile, Tweets);
		fileLength = Tweets.find(searchWord);
		if (fileLength != string::npos) {
			cout << Tweets << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
		}
		if (cin.fail()) {
			cout << "Invalid Input" << endl;
		}
	}
	inFile.close();
}

void CurrentMenu() {
	cout << endl;

	if (keywords) {
		currentVector = KeywordMenu;
	}

	if (countTweets) {
		currentVector = CountMenu;
	}

	for (int i = 0; i < currentVector.size(); i++) {
		cout << currentVector[i];
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	cout << endl;
}

void CountTweets() { 

	if (politics) {
		currentVector = politicalWords;
	}

	if (LGBT) {
		currentVector = Inclusivness;
	}

	if (tech) {
		currentVector = Technology;
	}

	if (money) {
		currentVector = Money;
	}

	while (!inFile.eof()) {
		for (int i = 0; i < currentVector.size(); i++) { 

			getline(inFile, searchCounter);
			if (searchCounter.find(currentVector[i]) != searchCounter.npos) {
				TweetCount++;
			}
		}
	}
	inFile.close();
}

int main() {

	inFile.open("sampleTweets.csv");  
	if (!inFile) {
		cout << "Unable to open file" << endl;
	}

	otherMenu = false; 

	do {

		Menu(); 
		cout << "Enter a number corressponding to the menu: " << endl;
		cin >> MenuChoice;

		switch (MenuChoice) 
		{
		case 1:
			system("CLS");
			keywords = true;
			otherMenu = true;
			CurrentMenu(); 
			cout << "Enter a number from the menu: " << endl;
			cin >> MenuChoice;
			if (MenuChoice == 1 && otherMenu) { 
				searchWord = "Paris";
				DisplayTweets(); 
			}
			if (MenuChoice == 2 && otherMenu) {
				searchWord = "Dreamworks";
				DisplayTweets();
			}
			if (MenuChoice == 3 && otherMenu) {
				searchWord = "Uber";
				DisplayTweets();
			}
			if (MenuChoice && otherMenu >= 4) {
				cout << "Invalid input" << endl;
			}
			break;
		case 2:
			system("CLS");
			countTweets = true; 
			otherMenu = true;
			CurrentMenu();
			cout << "Enter a number from the menu: " << endl;
			cin >> MenuChoice;
			if (MenuChoice && otherMenu <= 0) {
				cout << "Invalid input" << endl;
			}
			if (MenuChoice == 1 && otherMenu) {
				LGBT = true;
				CountTweets();
				cout << "The number of tweets that mention about LGBT is: " << TweetCount << endl;
				cout << endl;
			}
			if (MenuChoice == 2 && otherMenu) {
				politics = true;
				CountTweets();
				cout << "The number of tweets that mention about politics is: " << TweetCount << endl;
				cout << endl;
			}
			if (MenuChoice == 3 && otherMenu) {
				tech = true;
				CountTweets();
				cout << "The number of tweets that mention about Technology is: " << TweetCount << endl;
				cout << endl;
			}
			if (MenuChoice == 4 && otherMenu) {
				money = true;
				CountTweets();
				cout << "The number of tweets that mention about Money is: " << TweetCount << endl;
				cout << endl;
			}
			if (MenuChoice && otherMenu >= 5) {
				cout << "Invalid input" << endl;
			}
			break;
		case 3:
			system("CLS");
			cout << "Enter a word to search and all tweets with that word will be shown: " << endl;
			cin >> searchWord;
			DisplayTweets();
			if (cin.fail()) {
				cout << "Invalid Input...";
			}
			break;
		case 4:
			cout << "Please wait ..." << endl;
			while (getline(inFile, Tweets)) {
				linecount++;
			}
			system("CLS");
			cout << "Please wait ..." << endl;
			cout << "The total number of tweets is: " << linecount << endl;
			cout << endl;
			break;
		case 5:
			system("CLS");
			searchWord = "RT";
			DisplayTweets();
			break;
		case 6:
			system("CLS");
			searchWord = "@realDonaldTrump";
			DisplayTweets();
		case 7:
			system("CLS");
			searchWord = "@JLo";
			DisplayTweets();
		}

		inFile.open("sampleTweets.csv");
	} while (MenuChoice != 8);

	system("pause");
}