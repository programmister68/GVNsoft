#include <iostream>
#include <stdio.h>

using namespace std;

int main() // надо это переименовать и интегрировать в проект в виде отдельной функции;
{
	setlocale(LC_ALL, "rus");
	int funtion_table_select, coefficient, coefficient_x, coefficient_a, degree;
	char cont1;

		/*
		Описание переменных:

		coefficient - коэфф. при уравнении;
		coefficient_x - коэфф. при х;
		coefficient_a - коэфф. при а и е; 
		degree - степень числа.
		*/

		while (1) {
		cout << "Выберете функцию:" << endl;
		cout << "1. dx" << endl << "2. x^n*dx" << endl << "3. dx/x" << endl << "4. a^x*dx" << endl << "5. e^x*dx" << endl << "6. sin(x)*dx" << endl << "7. cos(x)*dx" << endl << "8. dx/cos^2(x)" << endl << "9. dx/sin^2(x)" << endl << "10. dx/(x^2-a^2)" << endl << "11. dx/sqrt(x^2+-a^2)" << endl << "12. dx/sqrt(x^2-a^2)" << endl << "13. dx/sqrt(a^2-x^2)" << endl << "14. dx/(x^2+a^2)" << endl << endl;
		cin >> funtion_table_select;

		if (funtion_table_select <= 0) cout << "Вы ввели неверный номер функции";

		if (funtion_table_select == 1) 
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient;
			cout << coefficient << "dx" << endl;
		}
		if (funtion_table_select == 2)
		{
			cout << "Введите значение коэффициента при х и степень n: ";
			cin >> coefficient_x >> degree;
			cout << coefficient_x << "^" << degree << "*dx" << endl;
		}
		if (funtion_table_select == 3)
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient_x;
			cout << "dx/" << coefficient_x << "x" << endl;
		}
		if (funtion_table_select == 4)
		{
			cout << "Введите значение коэффициента при а и при х: ";
			cin >> coefficient_a >> coefficient_x;
			cout << coefficient_a << "a^" << coefficient_x << "*dx" << endl;
		}
		if (funtion_table_select == 5)
		{
			cout << "Введите значение коэффициента при х и при экспаненты е: ";
			cin >> coefficient_a >> coefficient_x;
			cout << coefficient_a << "e^" << coefficient_x << "x*dx" << endl;
		}
		if (funtion_table_select == 6)
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient_x;
			cout << "sin(" << coefficient_x << "x)*dx" << endl;
		}
		if (funtion_table_select == 7)
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient_x;
			cout << "cos(" << coefficient_x << "x)*dx" << endl;
		}
		if (funtion_table_select == 8)
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient_x;
			cout << "dx/cos^2(" << coefficient_x << "x)" << endl;

		}
		if (funtion_table_select == 9)
		{
			cout << "Введите значение коэффициента при х: ";
			cin >> coefficient_x;
			cout << "dx/sin^2(" << coefficient_x << "x)" << endl;

		}
		if (funtion_table_select == 10)
		{
			cout << "Введите значение коэффициента при х и при а: ";
			cin >> coefficient_x >> coefficient_a;
			cout << "dx/(" << coefficient_x << "x^2-" << coefficient_a << "a^2)" << endl;

		}
		if (funtion_table_select == 11)
		{
			cout << "Введите значение коэффициента при х и при а: ";
			cin >> coefficient_x >> coefficient_a;
			cout << "dx/sqrt(" << coefficient_x << "x^2+" << coefficient_a << "a^2)" << endl;
		}
		if (funtion_table_select == 12)
		{
			cout << "Введите значение коэффициента при х и при а: ";
			cin >> coefficient_x >> coefficient_a;
			cout << "dx/sqrt(" << coefficient_x << "x^2-" << coefficient_a << "a^2)" << endl;
		}
		if (funtion_table_select == 13)
		{
			cout << "Введите значение коэффициента при а и при х: ";
			cin >> coefficient_a >> coefficient_x;
			cout << "dx/sqrt(" << coefficient_a << "a^2-" << coefficient_x << "x^2)" << endl;
		}
		if (funtion_table_select == 14)
		{
			cout << "Введите значение коэффициента при х и при а: ";
			cin >> coefficient_x >> coefficient_a;
			cout << "dx/(" << coefficient_x << "x^2+" << coefficient_a << "a^2)" << endl;
		}

		if (funtion_table_select > 14) cout << "Вы ввели неверный номер функции";

		cout << ("Ввести данные повторно? (любая клавиша/n): ");
		cin >> cont1;
		if (cont1 == 'n' or cont1 == 'N') {
			break;
		}
	}
	return 0;
}
