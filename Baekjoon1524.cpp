#include <iostream>
using namespace std;

typedef unsigned int UINT;

int main()
{
    int test;
    UINT sc, bc;
    UINT tmp;
    UINT sm, bm;
    
    cin >> test;
    while(test--)
    {   
        sm = 0;
        bm = 0;
        
        cin >> sc >> bc;
        for(int i=0; i<sc; i++)
        {
            cin >> tmp;
            if(tmp > sm)
                sm = tmp;
        }
        
        for(int i=0; i<bc; i++)
        {
            cin >> tmp;
            if(tmp > bm)
                bm = tmp;
        }
        
        cout << (bm > sm ? 'B' : 'S') << '\n';
    }
    
    return 0;
}
