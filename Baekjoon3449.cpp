#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    string str1, str2;
    int res = 0;
    
    cin >> test;
    while(test--)
    {
        cin >> str1 >> str2;
        
        for(int i=0; i<str1.length(); i++)
            if(str1[i] != str2[i])
                res++;
        
        cout << "Hamming distance is " << res << ".\n";
        res = 0;
    }
    
    return 0;
}
