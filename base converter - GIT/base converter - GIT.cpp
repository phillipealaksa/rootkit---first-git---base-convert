#include <iostream>
#include <conio.h>


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
			}
			else
			{
				return 0;
			}
		}
		system("cls");
	}
}