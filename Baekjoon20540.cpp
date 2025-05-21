#include <iostream>
using namespace std;

char input[5] = {0, };

void Choose(int idx, char cmp1, char cmp2)
{
    if(cmp1 == input[idx])
        cout << cmp2;
    else
        cout << cmp1;
}

int main()
{
    cin >> input;
    
    Choose(0, 'I', 'E');
    Choose(1, 'S', 'N');
    Choose(2, 'T', 'F');
    Choose(3, 'J', 'P');
    
    return 0;
}
