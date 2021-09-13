#include <iostream>
#include <string>


using namespace std;

int main()
{   setlocale(LC_ALL, "RUS");
    char sname[]="Plug", snam[10], ret;
    int arr[10];

    cout<<"Enter the surname: ";
    cin>> sname;
    string stsname = sname;
    for(unsigned int i = 0; i<stsname.size(); i++){
        snam[i] = stsname[i];
        cout<<snam[i]<<" ";
    }
    cout<<endl;
        for (int i = stsname.size(); i>0; i--){
             arr[i] = (snam[i]*2)-1;
             ret = arr[i];
             cout<<ret;
        }
    return 0;
}
