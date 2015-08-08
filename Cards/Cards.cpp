#include <iostream>
#include <string>
#include "deck.h"
#include <windows.h>
using namespace std;

void motif();
void showHands(deck deck);
void showPlayerHand(deck deck);
bool calcAI(deck &deck, int playerNum);
bool continues(bool stati[4]);
bool over21(int playerNum, card hands[4][14]);

int main()
{
	char heart = 3;
	char diamond = 4;
	char club = 5;
	char spade = 6;

	motif();
	cout << endl;



	// Play Blackjack
	char userPlay;
	cout << "Would you like to play? (y/n) ";
	cin >> userPlay;
	if (userPlay == 'y')
	{
		// Game on!
		deck deck; // Generate the deck (with all cards)
		deck.shuffle(); // Shuffle the deck
		deal(deck); // Deal the deck
		int round = 0;
		bool quits[4] = { false, false, false, false };
		//int totals[4] = { 0, 0, 0, 0 };

		while (continues(quits))
		{
			cout << endl;
			cout << "ROUND " << round << endl;
			// Player input
			showPlayerHand(deck);
			//cout << "over 21 :" << over21(0, deck.hands) << endl;
			//showHands(deck);
			//for (int i = 0; i < 4; i++) { cout << quits[i] << ' '; }
			cout << endl;
			char hitYN;

			if ((over21(0, deck.hands)) || quits[0] == true)
			{
				cout << "You passed or you busted" << endl;
				quits[0] = true;
			}
			else
			{
				cout << "Take a card? (y/n) ";
				cin >> hitYN;
				if (hitYN == 'y')
				{
					// Append dealOne to hands[0]
					deck.hands[0][round + 2] = dealOne(deck);
				}
				else
				{
					quits[0] = true;
				}
			}


			// AI loop
			for (int i = 1; i < 4; i++)
			{
				if ((calcAI(deck, i) == false) || (over21(i, deck.hands)) || quits[i])
				{
					quits[i] = true;
				}
				else
				{
					deck.hands[i][round + 2] = dealOne(deck);
				}
			}
			round++;

		}
		// Game is over
		cout << endl;
		cout << "Game Over!" << endl;
		showHands(deck);
		int margins[4] = { 0, 0, 0, 0 };
		for (int player = 0; player < 4; player++)
		{
			for (int pos = 0; pos < 14; pos++)
			{
				margins[player] += deck.hands[player][pos].realValue;
				//cout << deck.hands[player][pos].realValue << endl;
			}
		}
		// Reveal
		cout << endl;
		cout << "Player 1: " << margins[0] << endl;
		for (int player = 1; player < 4; player++)
		{
			cout << "AI " << player << ": " << margins[player] << endl;
		}
		// Find a winner
		for (int i = 0; i < 4; i++)
		{
			margins[i] -= 21;
		}
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			if (margins[i] > 0)
			{
				margins[i] = -100;
			}
		}
		int winner;
		winner = *max_element(&margins[0], &margins[4]);

		for (int i = 0; i < 4; i++)
		{
			if (margins[i] == 0)
			{
				if (i == 0)
				{
					cout << "You win!" << endl;
				}
				else
				{
					cout << "AI " << i << " wins!" << endl;
				}
			}
			else if (winner == margins[i])
			{
				if (i == 0)
				{
					cout << "You win!" << endl;
				}
				else
				{
					cout << "AI " << i << " wins!" << endl;
				}
			}
		}
	}

	else
	{
		cout << "Ok, killing";
		for (int i = 0; i < 6; i++)
		{
			Sleep(500);
			cout << '.';
		}
	}

	cout << endl;
	int end;
	cin >> end;
	return 0;
}

void motif()
{
	for (int i = 6; i < 13; i++)
	{
		if (i % 2 == 0)
		{
			char j = i / 2;
			cout << j;
		}
		else { cout << ' '; }
	}
}
void showHands(deck deck)
{
	for (int player = 0; player < 4; player++)
	{
		for (int position = 0; position < 14; position++)
		{
			cout << deck.hands[player][position].display();
		}
		cout << endl;
	}
}
void showPlayerHand(deck deck)
{
	for (int i = 0; i < 14; i++) { cout << deck.hands[0][i].display(); }
	cout << endl;
}
bool calcAI(deck &deck, int playerNum)
{
	int total = 0;
	for (int i = 0; i < 14; i++)
	{
		total += deck.hands[playerNum][i].realValue;
	}

	if (total < 17)
	{
		cout << "AI " << playerNum << " hit. " << total << endl;
		return true;
	}
	else
	{
		cout << "AI " << playerNum << " stayed. " << total << endl;
		return false;
	}
}
bool continues(bool quits[4])
{
	if (quits[0] && quits[1] && quits[2] && quits[3])
	{
		// End game
		return false;
	}
	else
	{
		// Continue
		return true;
	}
}
bool over21(int playerNum, card hands[4][14])
{
	int total = 0;
	for (int i = 0; i < 14; i++)
	{
		total += hands[playerNum][i].realValue;
	}

	if (total > 21)
	{
		//cout << "true " << total << endl;
		return true;
	}
	//cout << "false " << total << endl;
	return false;
}