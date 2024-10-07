#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int arr[3];
    string input;
    
    for(int i=0; i<3; i++)
        cin >> arr[i];
    cin >> input;
    
    sort(arr, arr+3);
    
    for(int i=0; i<input.length(); i++)
        cout << arr[input[i] - 'A'] << ' ';
    
    return 0;
}
