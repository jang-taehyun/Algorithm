#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 1, 2, 2, 2, 8};
    int minus[6];
    
    for(int i=0; i<6; i++)
        cin >> minus[i];
    
    for(int i=0; i<6; i++)
        cout << arr[i] - minus[i] << ' ';
    
    return 0;
}
