#include <iostream>

using namespace std;

int main() {
int x, first_prime, second_prime, k, i, n, m, r, t;
int first_number [15];
int second_number [15];
int poryad1 [15];
int poryad2 [15];

for (x=1; x>0; x++) {
    i=0;                             
    k=0;
    m=0;                            
    first_prime=x*2;
        for (first_prime; first_prime>0; first_prime) {
            i++;                     
            first_number[i] = first_prime % 10;   
            first_prime /= 10;
        }
        m=0;
        for (n=0; n<10; n++) {
            for (r=i; r>0; r--) {
                if  (first_number[r]==n) {
                m++;
                poryad1[m] = n;       
                }
            }
        }

        for (t=3; t<=6; t++) {          
            m=0;
            k=0;
            second_prime = x*t;
            for (second_prime; second_prime>0; second_prime) {
                k++;                     
                second_number[k] = second_prime % 10;  
                second_prime /= 10;
        }
            if (k!=i) break; 


            for (n=0; n<10; n++) {
                for (r=k; r>0; r--) {
                    if  (second_number[r]==n) {
                        m++;
                        poryad2[m] = n;      
                    }
                }
            }

            if (k==i) {
                for (k; k>0; k--) {  
                    if (poryad1[k]!=poryad2[k]) {
                    t=7;
                    break;
                    }
                }
            }
            if (t==6) {       
                cout << x << endl;
                return 0;
            }
        }
}
    return 0;
}
