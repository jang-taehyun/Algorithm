#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input1[101] = {0, };
    char input2[101] = {0, };
    
    cin >> input1;
    
    for(int i=0; i<strlen(input1); ++i)
        input2[strlen(input1)-i-1] = input1[i];
    
    cout << !strcmp(input1, input2) << '\n';
    
    return 0;
}
