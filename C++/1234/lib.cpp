#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "lib.h"
using namespace std;

void seave_up(vector <int> &h, int index)
{
    int par = (index-1)/2;
    while(h[par] > h[index])
    {
        swap(h[par], h[index]);
        index = par;
        par=(index-1)/2;
    }
}

void push(vector <int> &h, int elem)
{
    h.push_back(elem);
    seave_up(h, h.size()-1);
}
void seave_down(vector <int> &h, int elem)
{
    int left = elem*2+1;
    int right = elem*2+2;
    while(right<h.size() and (h[elem] > h[right] || h[elem] > h[left]))
    {
        if(h[left]>h[right])
        {
            swap(h[elem], h[right]);
            elem = right;
        }
        else
        {
            swap(h[elem], h[left]);
            elem = left;
        }
        left = elem * 2+1;
        right = elem * 2+2;
    }
    if(left< h.size() and h[elem] > h[left])
        swap(h[elem], h[left]);
}
int pop(vector <int> &h)
{
    swap(h[0], h[h.size()-1]);
    int returned = h[h.size()-1];
    h.pop_back();
    seave_down(h, 0);
    return returned;
}
