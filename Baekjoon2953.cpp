#include <iostream>
using namespace std;

int arr[5];
int res_sum=0;
int res_idx=0;

int main()
{
    int tmp;
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> tmp;
            arr[i] += tmp;
        }
        
        if(arr[i] > res_sum)
        {
            res_sum = arr[i];
            res_idx = i;
        }
            
    }
    
    cout << res_idx+1 << ' ' << res_sum;
    
    return 0;
}
