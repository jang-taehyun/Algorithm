#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    int arr[7];
    int Min = 101;
    int sum = 0;
    
    cin >> test;
    while(test--)
    {
        for(int i=0; i<7; i++)
            cin >> arr[i];
        
        sort(arr, arr+7);
        for(int i=0; i<7; i++)
            if(!(arr[i] % 2))
            {
                if(Min == 101)
                    Min = arr[i];
                
                sum += arr[i];
            }
        
        cout << sum << ' ' << Min << '\n';
        
        sum=0;
        Min=101;
    }
    
    return 0;
}
