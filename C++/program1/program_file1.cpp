#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int v=0;
    int number [1000];
    fstream pyramid ("file.txt", ios_base::in);
        while (!pyramid.eof()) {
            v++;
            pyramid >> number [v];
            //cout << v << ' ';
        }
        setlocale (LC_ALL, "rus");
        int x=15, sum[1000];  /// 15 - длина основания
        for (v=106; v>0; v) {
            x--;
            for (int t=x; t>0; t--) {
                v--;
                if (number[v+x]>number[v+x+1]) {
                    cout << number[v] << ' ' << number[v+x] << " - больше" << endl;
                    number[v]+=number[v+x];
                }
                else {
                    cout << number[v] << ' ' << number[v+x+1] << " - больше" << endl;
                    number[v]+=number[v+x+1];
                }
            }
            if (v==1) break;
        }
        cout << number [1];
    return 0;
} 