#include <iostream>
#include <conio.h>

using namespace std;

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

			}
			else
			{
				return 0;
			}
		}
		system("cls");
	}

}