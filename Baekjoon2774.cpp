#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int test;
    string input;
    int arr[10];
    int res=0;
    
    cin >> test;
    while(test--)
    {
        cin >> input;
        
        memset(arr, 0, sizeof(arr));
        res=0;
        
        for(int i=0; i<input.length(); i++)
            arr[input[i] - '0']++;
        for(int i=0; i<10; i++)
            if(arr[i])
                res++;
        
        cout << res << '\n';
    }
    
    return 0;
}
