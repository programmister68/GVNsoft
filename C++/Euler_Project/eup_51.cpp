#include <iostream>

using namespace std;

int main()
{
    int a, b=100000, nomer1er, n, z=0, k, r, m, t, h, j, g, x, i=1, q, c, s;
    int nomer1 [100];
    int nomer2 [100];
    int p [100];
    int d [100];
    int prostye [100000];
    for (a=10001; a<b; a+=2) {
        if (a>b/10) {
            r=z;
            s=1;
            j=x;
            for (s; s<=z; s++) {
                k=0;
                nomer1er = prostye [s];
                    for (nomer1er; nomer1er>0; nomer1er) {
                        k++;
                        nomer1[k] = nomer1er%10;
                        nomer1er /= 10;
                    }

                    for (t=0; t<10; t++) {
                        g=0;
                        h=0;
                        for (m=k; m>0; m--) {
                            if (nomer1 [m] == t) {
                                g++;
                                p [g] = m;
                            }
                            else {
                                h++;
                                d [h] = m;
                            }
                        }
                        i=0;
                        if (g>2) {
                            for (j=r; j>0; j--) {
                                nomer1er = prostye [j];
                                x=0;
                                for (nomer1er; nomer1er>0; nomer1er) {
                                    x++;
                                    nomer2[x] = nomer1er%10;
                                    nomer1er /= 10;
                                    }
                                for (q=h; q>0; q--) {
                                    if (nomer1 [d [q]] == nomer2 [d [q]]) {
                                        if (q==1) {
                                            for (c=g; c>1; c) {
                                                if (nomer2 [p[c]] == nomer2 [p[c-=1]]) {
                                                    if (c==1) {
                                                        i++;
                                                        if (i==8) {
                                                        cout << " The smallest prime of an eight prime value family is " << prostye  [j] << endl;
                                                        cout << " Answer: " << prostye  [j] << endl;
                                                        return 0;
                                                        }                                                    }
                                                }
                                                else break;
                                            }
                                        }
                                    }
                                    else break;
                                }
                            }
                        }
                    }
                if (z==s) {
                    z=0;
                    b*=10;
                }
                }
            }

        for (n=3; n>0; n+=2) {
                if (a%n==0) break;
                if (n*n>=a) {
                    z++;
                    prostye [z] = a;
                    break;
                }
            }

    }

    return 0;
}
