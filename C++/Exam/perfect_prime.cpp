#include <iostream>


using namespace std;

/*
    Найти все совершенные числа до 10000. Совершенное число - это такое число, которое равно сумме всех своих делителей, кроме себя самого.
    Например, число 6 является совершенным, т.к. кроме себя самого делится на числа 1, 2 и 3, которые в сумме дают 6.
*/



int filter (int summa_delitelej, int perfprime, int prime)
{
    for (perfprime=0; perfprime<10000; perfprime++)
    {
        summa_delitelej=0; ///Здесь мы обнуляем сумму делителей, без этого действия программа не работает должным образом.
        for (prime=1; prime<perfprime; prime++)
            {
                if (perfprime%prime == 0)
                    summa_delitelej = summa_delitelej+prime;
            }
        if (summa_delitelej == perfprime)
        cout << summa_delitelej << " ";
    }
}
int main()
{
    int perfprime, summa_delitelej, prime;
    sort (summa_delitelej, perfprime, prime);
    return 0;
}
