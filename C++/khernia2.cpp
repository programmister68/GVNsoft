#include <iostream>

using namespace std;

int main()
{
    int racounter=0, answ[10] = { 1, 3, 4, 3, 2, 1, 3, 2, 1, 4}, uansw[10];
    cout<<"enter answers for the test"<<endl;
    for (int i=0; i<10; i++){
        cin>>uansw[i];
    }
    for (int i =0; i<10; i++)
    {
        if(uansw[i]==answ[i]){
            racounter++;
        }
    }
    if(racounter>=9){
        cout<<"Your final mark is 5 "<<endl;
    }
     if(racounter==8 or racounter==7){
        cout<<"Your final mark is 4 "<<endl;
    }
    if(racounter==6 or racounter==5 or racounter==4){
        cout<<"Your final mark is 3 "<<endl;
    }
    if(racounter<4){
        cout<<"Your final mark is 2 "<<endl;
    }
    return 0;
}
