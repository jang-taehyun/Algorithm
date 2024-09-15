#include <iostream>
#include <string>
using namespace std;

bool IsIn[3];

void Swap(int idx1, int idx2)
{
    bool tmp = IsIn[idx1];
    IsIn[idx1] = IsIn[idx2];
    IsIn[idx2] = tmp;
}

int main()
{
    string input;
    
    IsIn[0] = true;
    IsIn[1] = false;
    IsIn[2] = false;
    
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == 'A')
            Swap(0, 1);
        else if(input[i] == 'B')
            Swap(1, 2);
        else
            Swap(0, 2);
    }
    
    for(int i=0; i<3; i++)
        if(IsIn[i])
            cout << i+1;
    
    return 0;
}
