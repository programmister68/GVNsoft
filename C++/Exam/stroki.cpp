#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[100];
    cin >> str1;
    char str2[50];
    cin >> str2;
    int len1 = strlen (str1);
    int len2 = strlen (str2);
    int flg;
    int i, j;
    for (i = 0; i < len2; i++)
    {
        flg = 0;
        for (j = 0; j < len1; j++)
            if (str2[i] == str1[j])
            {
                flg = 1;
                break;
            }
        if (flg == 0)
            break;
    }
    if (flg == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
