#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string a;
    //a = "dcz.z xc@sda.asd.sda";
    cin>>a;
    char arr [10000];
    strncpy (arr, a.c_str(), a.length() + 1);

    int l, counter=0;
    for (int k=0; k<a.length(); k++) {
        l=arr[k];
        if (l<0) {
            cout << "error";
            return 0;
        }

        if (l==32) {
            cout << "error";
            return 0;
        }

        if (arr[k]=='@' and counter>0) {
            cout << "error";
            return 0;
        }

        if (arr[k]=='@') counter++;

        if (arr[k]=='.' and arr[k+1]=='.') {
            cout << "error";
            return 0;
        }
        if (arr[k]=='@' and arr[k+1]=='.') {
            cout << "error";
            return 0;
        }

        if (arr[k]=='.' and arr[k+1]=='@') {
            cout << "error";
            return 0;
        }

        if (arr[k]=='.' and counter==1) counter++;

    }
    if (arr[0]=='.' or arr[a.length()-1]=='.') {
        cout << "error";
        return 0;
    }


    if (counter>1) cout << "right";
    else cout << "error";
    return 0;
}
