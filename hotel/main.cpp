#include "hotel.h"
int main()
{
	hotel h;
	int x = 0;
	char ch='a';
	while (ch != 'e')
	{
		system("cls");
		x = h.menu();
		h.cheack_menu(x);
		cout << "\n\nif you want continue press 'c' if you want exit press 'e'\n";
		cin >> ch;
	}
	cout << "\n";
	system("pause");
	exit(0);
	return 0;
}
