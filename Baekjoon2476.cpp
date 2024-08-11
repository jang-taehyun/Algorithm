#include <iostream>
using namespace std;

int main()
{
    int count;
    int arr[3];
    int res=0, tmp=0;
    
    cin >> count;
    
    while(count--)
    {
        for(int i=0; i<3; i++)
            cin >> arr[i];
        
        if(arr[0] == arr[1] && arr[1] == arr[2])
            tmp = 10000+(arr[0] * 1000);
        else if(arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
        {
            if(arr[0] == arr[1])
                tmp = 1000 + (arr[0] * 100);
            else if(arr[1] == arr[2])
                tmp = 1000 + (arr[1] * 100);
            else
                tmp = 1000 + (arr[2] * 100);
        }
        else
        {
            int idx=0;
            for(int i=0; i<3; i++)
                if(arr[i] > arr[idx])
                    idx=i;
            
            tmp = arr[idx] * 100;
        }
        
        if(res < tmp)
            res = tmp;
    }
    
    cout << res;
    
    return 0;
}
