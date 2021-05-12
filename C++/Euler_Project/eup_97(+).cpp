#include <iostream>

using namespace std;

unsigned long long int voz_in_step (unsigned long long int a, unsigned long long int p)
{
    for (unsigned long long int i=0; i<7830457; i++)
    {
        p=p*2;
        p=p%10000000000;
    }
    cout << endl;
    a = ((28433*p) + 1)%10000000000;
    cout << "Answer : " << a << endl;
    return 0;
}

int main()
{
    unsigned long long int p = 1, a = 0;
    voz_in_step (a, p);
    //prime =  (28433 * p) + 1;//
    return 0;
}
