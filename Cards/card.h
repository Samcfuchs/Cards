#include <iostream>
#include <string>

using namespace std;

class card
{
public:
	// Attributes
	int value; // J = 11, Q = 12, K = 13, A = 14
	char suit; // C H D S
	int realValue = 0;

	// Functions
	string display()
	{
		string displayString = "";
		// Do some stuff
		if (value < 11 && value > 1)
		{
			displayString += "[";
			displayString += to_string(value);
		}
		switch (value)
		{
		case 11:
			displayString += "[";
			displayString += 'J';
			break;
		case 12:
			displayString += "[";
			displayString += 'Q';
			break;
		case 13:
			displayString += "[";
			displayString += 'K';
			break;
		case 14:
			displayString += "[";
			displayString += 'A';
			break;
		}
		if (value > 1)
		{
			displayString += ' ';
			displayString += getIcon();
			//displayString += realValue;
			displayString += ']';
		}

		return displayString;
	}
	char getIcon()
	{
		char icon;
		switch (suit)
		{
		case 'H':
			icon = 3;
			break;
		case 'D':
			icon = 4;
			break;
		case 'C':
			icon = 5;
			break;
		case 'S':
			icon = 6;
			break;
		case ' ':
			icon = ' ';
			break;
		default:
			cout << "[getIcon] Bad suit input" << endl;
		}
		return icon;
	}

	// Constructors
	card()
	{
		value = 0;
		suit = ' ';
		//value = 14;
		//suit = 'S';
	}
	card(int v, char s)
	{
		value = v;
		suit = s;

		if (value > 10) { realValue = 10; }
		if (value == 14) { realValue = 11; }
		if (value < 11) { realValue = value; }
	}

};