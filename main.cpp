#include <iostream>
#include "ratio.h"
;using namespace std;

/*int strsymtest(const char* str, int c)
{
    int i = 0;
	for (i < strlen(str); str[i] != c; i++);
	return ++i;
}*/
void menu();

void main()
{
	setlocale(LC_ALL,"Russian");
	menu();
	system("pause");
}

void menu()
{
	ratio a,b;
	short int sel;
	do
	{
		system("cls");
		cout << "\n\n1. enter a\n2. enter b\n3. show a b\n4. show overloaded operators\n0. exit\n\n";
		cin >> sel;
		switch (sel)
		{
		case 0: { break; }
		case 1:	{ system("cls"); cin >> a; break; }
		case 2: { system("cls"); cin >> b; break; }
		case 3: { system("cls"); cout << "\na = " << a << "\nb = " << b; system("pause"); break; }
		case 4: { system("cls"); 
				  cout << "\na + b = " << a + b << "\na - b = " << a - b;
				  if ((a * b) != (1, -1))
					  cout << "\na * b = " << a * b; 
					  cout << "\na / b = " << a / b;
				  system("pause");
				  break;}
		default: { cout << "\nthere is no such function"; }
		}
	}
	while ( sel != 0);
}
