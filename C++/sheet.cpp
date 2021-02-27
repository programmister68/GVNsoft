#include <iostream>
#include <string>
using namespace std;
struct studentb
{
    char* name;
    char* groupID;
    float midmar;
};
int main()
{
    setlocale (LC_ALL, "rus");
    studentb Igor = {"С.А.Шепелёв", "ИСП-21", 4.5};
    cout << "===================================================" << endl;
    cout << "Кривая таблица кривого кода Beta 1.1 (работа от 28.10.2020)" << endl;
    cout << "===================================================" << endl;
    cout << "               " << endl;
    for (int i=1; i<4; i++){
        cout << "|----------------------|";
    }
    cout << "  " << endl; //строка имени, строка номера группы, строка среднего балла учащегося
            cout << "|        #Имя          |";
            cout << "|       #Группа        |";
            cout << "|      #Ср.оценка      |";
                cout << "                        " << endl;
            for (int k=1; k<4; k++){
                cout << "|----------------------|";
            }
    cout << ' ' << endl;
    for (int k=1; k<3; k++){
        for (int j=1; j<4; j++){
            cout << "|                      |";
        }
    cout << "               " << endl;
    }
    cout << "|  ";
    cout << Igor.name;
    cout << "         "; //9 пробелов
    cout << "|";
    cout << "|  ";
    cout<< Igor.groupID;
    cout << "              "; //14 пробелов
    cout<< "|";
    cout << "|  ";
    cout<< Igor.midmar;
    cout << "                 "; //17 пробелов
    cout<< "|";
    cout << "               " << endl;
    for (int k=1; k<2; k++){
        for (int j=1; j<4; j++){
            cout << "|                      |";
        }
    cout << "               " << endl;
    }
    for (int i=1; i<4; i++){
        cout << "|----------------------|";
    }
    cout << "               " << endl;
    cout << "=================================" << endl;
    cout << "https://github.com/doggunovich68" << endl;
    cout << "=================================" << endl;
    cout << "               " << endl;
    return 0;
}
