#include "colorize.h"
#include "WordList.h"
#include "BetterRand.h"

#include <string>

#define _WIN32_WINNT 0x0500

using namespace std;

string word = { 0 };
string guess = { 0 };
bool correctspaces[5] = { 0 };

template<typename C, typename T>
bool contains(C&& c, T e) {
	return find(begin(c), end(c), e) != end(c);
};

bool checkGuess(string g, string w)
{
	for (int i = 0; i <= 4; i++)
	{
		
		if (!contains(wordlist, guess) && !contains(answerlist, guess))
		{
			cout << "guess not in dictionary" << endl;

			return false;
		}
		else if (g.at(i) == w.at(i))
		{
			correctspaces[i] = true;
			cout << colorize(GREEN) << g.at(i) << colorize(BLACK);
		}
		else if (w.find(g.at(i)) != string::npos)
		{
			cout << colorize(YELLOW) << g.at(i) << colorize(BLACK);
		}
		else
		{
			correctspaces[i] = false;
			cout << colorize(BLACK) << g.at(i) << colorize(BLACK);
		}
	}
	cout << colorize(BLACK) << endl;
	return true;
}

int main()
{
#ifdef _WIN32
	activateVirtualTerminal();
#endif
	
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 475, 500, TRUE);

	string mode;

	cout << colorize(GREEN, WHITE) << "\n\n\n\n\n\n\n\n\n\n\n\n\n                         Welcome to                         \n\n" << "                        W O R D L E                        " << "\n\n                        Lite Edition                       \n\n\n\n\n\n\n\n\n\n\n" << "              Enter Mode (\"archive\",\"random\") :              " << colorize(BLACK, WHITE) << endl;
mode:
	getline(cin, mode);

	system("cls");

	if (mode == "random") {
		srand(time(NULL));
		int r = randint(listSize);
		word = answerlist[r];
	}
	else if (mode == "archive")
	{
		string level;


		cout << "Choose Wordle Number:" << endl;
		getline(cin, level);
		int l = stoi(level);

		word = answerlist[l - 1];
		system("cls");
	}
	else
	{
		cout << "invalid mode, choose archive or random" << endl;
		goto mode;
	}
	
	//cout << word;
	//cout << answerlist[278];

	for (int i = 1; i <= 6;)
	{
	restart:
		//cout << endl;
		getline(cin, guess);
		cout << i << ": ";
		
		if (!checkGuess(guess, word))
		{
			goto restart;
		}
		else
		{
			i++;
		}
		if (correctspaces[0, 1, 2, 3, 4] == true)
		{
			goto end;
		}

	}
	cout << "The Word was: " << word << endl;

end:
	return 0;
}
