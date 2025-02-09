#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int arr1[200000] = {0, };
    unsigned int arr2[200000] = {0, };
    int alen, blen;
    int aIdx = 0, bIdx = 0;
    int res = 0;
    
    cin >> alen >> blen;
    
    for(int i=0; i<alen; i++)
        cin >> arr1[i];
    
    for(int i=0; i<blen; i++)
        cin >> arr2[i];
    
    sort(arr1, arr1+alen);
    sort(arr2, arr2+blen);
    
    while(1)
    {
        if(aIdx == alen || bIdx == blen)
            break;
        
        if(arr1[aIdx] == arr2[bIdx])
        {
            res++;
            aIdx++;
            bIdx++;
        }
        else if(arr1[aIdx] > arr2[bIdx])
            bIdx++;
        else
            aIdx++;
    }
    
    cout << ((alen + blen) - (res * 2));
    
    return 0;
}
