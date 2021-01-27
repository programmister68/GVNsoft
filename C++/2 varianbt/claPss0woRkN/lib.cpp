#include <iostream>
using namespace std;

int get_min(int *arr, int n){
int returned = arr[0];
for(int i = 0; i<n; i++){
    if (arr[i] < returned)
        returned = arr[i];
}
return returned;
}
