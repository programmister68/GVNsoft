#include <iostream>
using namespace std;
struct dis_set
{
    int parent[ 1000 ] ;
    int size[ 1000 ];
    void make_set(int v)
    {
        parent[ v ] = v;
        size[ v ] = 1;
    }
 
    int find_set(int v)
    {
        if(v == parent[ v ] ) return v;
        return parent[ v ] = find_set ( parent[ v ]);
    }
 
    void merge_set(int x, int y)
    {
        x = find_set(x) ;
        y = find_set(y);
        if( x != y)
        {
            {
                if (size[ x ] < size[ y ])
                {
                    swap (x, y);
                }
                parent[ y ] = x;
                size[ x ] += size[ y ];
            }
        }
    }
};
int main ()
{
    dis_set st;
    string s;
    while(cin >> s)
    {
        if(s == "RESET")
        {
            int x;
            cin >> x;
            for(int i = 0; i < 1000; i++)
                st.make_set(i);
            cout << "RESET DONE" << endl;
        }
        if(s == "JOIN")
        {
            int x, y;
            cin >> x >> y;
            if(st.find_set(x) == st.find_set(y))
            {
                cout << "ALREADY " << x << ' ' << y << endl;
            }
            st.merge_set(x, y);
        }
        if(s == "CHECK")
        {
            int x, y;
            cin >> x >> y;
            if(st.find_set(x) == st.find_set(y))cout << "YES" << endl;
            else cout << "NO" << endl;
        }
 
    }
 
}
