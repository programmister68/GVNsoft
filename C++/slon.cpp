#include <iostream>

using namespace std;

int main ()
{
	setlocale (LC_ALL, "rus");
	int x1, x2, y1, y2;
	cout << "Введите координаты клеток шахматной доски" << endl;
	cout << "Первая клетка (x1, y1): ";
	cin >> x1 >> y1;
	cout << "Первая клетка (x2, y2): ";
	cin >> x2 >> y2;
	if ((x1-x2)==(y1-y2))
	{
		cout << "Пройдём!";
	}
	else 
	{
		cout << "Прости, но я здесь не пройду";
	}
return 0;
}
