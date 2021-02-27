#include <iostream>

using namespace std;

int voz_in_step (int number) {
    int sum=0, mod;
    for (number; number>0; number) {
        mod = number % 10; //drobnaya chast
        sum = sum + (mod*mod);
        number = number / 10; //tselaya chast
    }
    return sum;
}

int main()
{
    int prime, counter=0;
    for (int i=0; i<10000000; i++) {
        prime=i;
        for (prime; prime>0; prime) {
            if (prime==1) 
                break;
            if (prime==89) 
            {
                counter++;
                break;
            }
            prime = voz_in_step(prime);
        }
    }
    cout << "Answer: " << counter;
    return 0;
}
