#include <iostream>

using namespace std;

int main()
{
    long long x, y, n;
        for (x=0; x<2000000; x)
        {
            x++;
           for (y=0; y<2000000; y)
           {
            y++;
            answer = (x*(x+1)/2) * (y*(y+1)/2);
            if(answer<= 2000000){
               x=2000000-answer;
            }
            else{
               x=answer-2000000;
               break;
            }
            if(x < y){
                y = x;
                cout<<x*y;
                }

           }
        }
    return 0;
