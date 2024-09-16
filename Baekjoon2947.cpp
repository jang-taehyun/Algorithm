#include <iostream>
using namespace std;

int arr[5];

void Swap(int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int main()
{
    bool IsSwap = true;
    for(int i=0; i<5; i++)
        cin >> arr[i];
    
    while(IsSwap)
    {
        IsSwap = false;
        
        for(int i=0; i<4; i++)
            if(arr[i] > arr[i+1])
            {
                IsSwap = true;
                Swap(i, i+1);
                
                for(int j=0; j<5; j++)
                    cout << arr[j] << ' ';
                cout << '\n';
            }
    }
    
    return 0;
}
