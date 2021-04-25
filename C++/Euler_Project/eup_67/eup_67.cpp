#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int v=0;
    int prime [100000];
    int p=0;
    fstream pyramidka ("triangle.txt", ios_base::in);
        while (!pyramidka.eof()) {
            p++;
            for (int i=p; i>0; i--){
            v++;
            pyramidka >> prime [v];
            }
        }
        int x=p;
        for (v=1+v-p; v>0; v) {
            x--;
            for (int j=x; j>0; j--) {
                v--;
                if (prime[v+x]>prime[v+x+1]) {
                    prime[v]+=prime[v+x];
                }
                else {
                    prime[v]+=prime[v+x+1];
                }
            }
            if (v==1) break;
        }
        cout << "Answer: " << prime [1];
    return 0;
}
