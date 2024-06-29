#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arrayLen, loopCount;
    vector<int> arr;
    string input="", tmp2="";
    int tmp;
    
    cin >> arrayLen >> loopCount;
    cin >> input;
    
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == ',')
        {
            arr.push_back(stoi(tmp2));
            tmp2 = "";
        }
        else
        {
            tmp2 += input[i];
        }
    }
    arr.push_back(stoi(tmp2));
    
    while(loopCount--)
    {
        tmp = arr.size() - 1;
        while(tmp--)
        {
            arr.push_back(arr[1] - arr[0]);
            arr.erase(arr.begin());
        }
        
        arr.erase(arr.begin());
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        if(arr.size() - 1 == i)
            cout << arr[i];
        else
            cout << arr[i] << ',';
    }
    
    return 0;
}
