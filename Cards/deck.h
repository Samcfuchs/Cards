#include <iostream>
#include <string>
#include "card.h"
#include <algorithm>
#include <time.h>
using namespace std;

class deck
{
public:
	// Attributes
	bool isShuffled;
	card list[52];
	card hands[4][14];
	card topCard;
	int deckPosition = 0;

	// Functions
	void display()
	{
		for (int i = 0; i < 52; i++)
		{
			cout << i << ' ' << list[i].display() << endl;
		}
	}
	void shuffle()
	{
		// Shuffle the deck in place
		srand(time(NULL));
		random_shuffle(&list[0], &list[52]);
		isShuffled = true;
	}

	// Constructors
	deck()
	{
		for (int i = 0; i < 13; i++)
		{
			list[i] = card(i + 2, 'S');
		}
		for (int i = 0; i < 13; i++)
		{
			list[i + 13] = card(i + 2, 'D');
		}
		for (int i = 0; i < 13; i++)
		{
			list[i + 26] = card(i + 2, 'C');
		}
		for (int i = 0; i < 13; i++)
		{
			list[i + 39] = card(i + 2, 'H');
		}
	}

};

void deal(deck &deck)
{
	if (deck.isShuffled != true) { deck.shuffle(); }
	// Deal cards
	for (int i = 0; i < 2; i++) // Cycle through hand position
	{
		for (int j = 0; j < 4; j++) // Cycle through players
		{
			deck.topCard = deck.list[deck.deckPosition];
			deck.deckPosition++;
			deck.hands[j][i] = deck.topCard;
		}
	}
}
card dealOne(deck &deck)
{
	deck.topCard = deck.list[deck.deckPosition];
	deck.deckPosition++;
	return deck.topCard;
}
