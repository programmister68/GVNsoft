#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ifstream file ("Base_exp.txt");
    int b[5000],b_max=0, index=1, char_number=0;
    while (!file.eof())
    {
        file >> b[index];
        index++;
    }
    for (int i=1; i<index; i=i+2)
    {
        if (b[i+1]*log(b[i])> b_max)
        {
            b_max = log(b[i])*b[i+1];
            char_number = (i+1)/2;

        }
    }
    cout << "Answer: " << char_number;
    return 0;
}
