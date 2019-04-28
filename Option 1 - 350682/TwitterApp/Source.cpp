#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string Tweets; // The string sampleTweets.csv ill be read as
string searchWord; // The search query 
string searchCounter;// The string sampleTweets.csv ill be read as for counting tweets
ifstream inFile; // SampleTweets.csv
size_t fileLength; // Size_t stores the maximum size of the Tweets string
vector<string> currentVector; // A temporary vector to reduce code replication

int linecount = 0;
int TweetCount = 0;

vector<string> KeywordMenu = { // Keyword Menu
	" 1 - Show tweets that mention Paris",
	" 2 - Show tweets that mention Dreamworks",
	" 3 - Show Tweets that mention Uber",
	" 4 - Return to Main Menu"
};

vector<string> CountMenu = { // Tweet Count Menu
	" 1 - Count Tweets mentioning LGBT",
	" 2 - Count Tweets mentioning politics",
	" 3 - Count Tweets mentioning technology",
	" 4 - Count Tweets mentioning money"
};

vector<string> politicalWords = { "congress","Congress","abortion","Abortion","president","President","immigration","Immigration", "election", "Election" }; // These vectors are search terms to accurately count the amount of tweets relating to a search term
vector<string> Inclusivness = { "LGBT", "gay", "Gay", "lesbian", "Lesbian", "#TransWeek", "transgender", "Transgender" };
vector<string> Technology = { "Phone", "phone", "Computer", "computer", "Tech", "tech", "coding", "c++", "C++", "Java", "iPhone", "Android", "iOS", "Samsung" };
vector<string> Money = { "$", "cash", "money", "Cash", "Money" };

int MenuChoice = 0; // The user's input in menus
bool keywords; //These booleans check if the user has entered a certain area of the menus or have selected specific items
bool countTweets;
bool otherMenu; // This checks if any menu other than the main one is being displayed
bool politics; // Like the ones that follow these booleans identify what query the user has selected
bool LGBT;
bool tech;
bool money;

void Menu() { //  Displays the Main menu
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

void Keywords() { // Prints the Keyword menu to console

	for (int i = 0; i < KeywordMenu.size(); i++) {
		cout << KeywordMenu[i] << endl;
	}
}

void DisplayTweets() {  // This function reads the sampleTweets.csv file and returns it based on the searchWord string

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

void CurrentMenu() { //Get current menu and display it
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

void CountTweets() { //This function prints the current selected vector to console

	if (politics) { //Depending on the boolean selected this fumction prints the desired vector to console
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
		for (int i = 0; i < currentVector.size(); i++) { //This for loop counts the number of tweets based of the search terms in the vector selected

			getline(inFile, searchCounter);
			if (searchCounter.find(currentVector[i]) != searchCounter.npos) {
				TweetCount++;
			}
		}
	}
	inFile.close();
}

int main() {

	inFile.open("sampleTweets.csv");  //Open sampleTweets.csv
	if (!inFile) {
		cout << "Unable to open file" << endl;
	}

	otherMenu = false; // By default otherMenu is false when the Main Menu is active

	do {

		Menu(); // Calls the Menu() function
		cout << "Enter a number corressponding to the menu: " << endl;
		cin >> MenuChoice; // User enters their choice

		switch (MenuChoice) // This switch handles input
		{
		case 1:
			system("CLS"); // Clears the screen
			keywords = true; // Sets the keyword menu as the desired menu
			otherMenu = true;
			CurrentMenu(); //Displays the desired menu
			cout << "Enter a number from the menu: " << endl;
			cin >> MenuChoice;
			if (MenuChoice == 1 && otherMenu) { // These inputs will only work if otherMenu is active 
				searchWord = "Paris";
				DisplayTweets(); // Calls the DisplayTweets function
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
			countTweets = true; // Sets the count tweets menu as the desired menu
			otherMenu = true;
			CurrentMenu();
			cout << "Enter a number from the menu: " << endl;
			cin >> MenuChoice;
			if (MenuChoice && otherMenu <= 0) {
				cout << "Invalid input" << endl;
			}
			if (MenuChoice == 1 && otherMenu) {
				LGBT = true; // Sets the Inclusivness vector as the current vector
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
			cin >> searchWord; // Allows user to set the search term
			DisplayTweets();
			if (cin.fail()) {
				cout << "Invalid Input...";
			}
			break;
		case 4:
			cout << "Please wait ..." << endl;
			while (getline(inFile, Tweets)) {
				linecount++; // Counts the lines in sampleTweets.csv
			}
			system("CLS");
			cout << "Please wait ..." << endl;
			cout << "The total number of tweets is: " << linecount << endl; // Displays number of lined in sampleTweets.csv
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