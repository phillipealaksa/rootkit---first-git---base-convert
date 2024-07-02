#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

bool isValidNum(int base, string num)
{
	for (char& c : num)
	{
		if (!(isdigit(c) && 0 <= c - 48 && c - 48 <= base))
		{
			return false;
		}
	}
	return true;
}

string convert(int pb, int sb, string pn)
{
	int btn = 0;
	for (int i = 0; i < pn.length(); i++)
	{
		btn += pow(pn[i] - 48, pn.length() - i - 1);
	}
	if (sb == 10)
	{
		return to_string(btn);
	}
	else
	{
		string newn = "";
		int maxp = 0;
		while (pow(sb, maxp + 1) <= btn)
		{
			maxp++;
		}
		int mult;
		for (int i = maxp; i >= 0; i--)
		{
			mult = 0;
			while ((mult + 1) * pow(sb, i) <= btn)
			{
				mult++;
			}
			newn.insert(0, to_string(mult));
			btn -= mult * pow(sb, i);
		}
		return newn;
	}
}

void getInParams()
{
	string input, pn;
	int pb, sb;
	do
	{
		system("cls");
		cout << "Enter primary base (2-9):\n";
		cin >> input;
	} while (!(input.length() == 1 && isdigit(input[0]) && 2 <= (input[0] - 48) && (input[0] - 48) <= 9));
	pb = input[0] - 48;
	do
	{
		system("cls");
		cout << "Enter secondary base (2-9):\n";
		cin >> input;
	} while (!(input.length() == 1 && isdigit(input[0]) && 2 <= (input[0] - 48) && (input[0] - 48) <= 9));
	sb = input[0] - 48;
	do
	{
		system("cls");
		cout << "Enter valid primary number:\n";
		cin >> input;
	} while (!isValidNum(pb, input));
	pn = input;
	system("cls");
	cout << pn << " base " << pb << " in base " << sb << " is " << convert(pb, sb, pn) << '\n';
	_getch();
}


int main()
{
	int cursIndex = 0;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << (i == cursIndex ? " > " : "   ");
			switch (i)
			{
			case 0:
				cout << "Convert Bases\n";
				break;
			case 1:
				cout << "Exit\n";
				break;
			}
		}

		int c = _getch();
		if (c == 224)
		{
			c = _getch();

			switch (c)
			{
			case 72:
				if (cursIndex > 0)
				{
					cursIndex--;
				}
				break;
			case 80:
				if (cursIndex < 1)
				{
					cursIndex++;
				}
				break;
			}
		}
		else if (c == 13)
		{
			if (cursIndex == 0)
			{
				getInParams();
				return 0;
			}
			else
			{
				return 0;
			}
		}
		system("cls");
	}
}