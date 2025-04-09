#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[5][16] = {0, };
    int maxLen = 0;
    
    for(int i=0; i<5; ++i)
        cin >> input[i];
    
    for(int i=0; i<5; ++i)
        if(maxLen < strlen(input[i]))
            maxLen = strlen(input[i]);
    
    for(int i=0; i<maxLen; ++i)
        for(int j=0; j<5; ++j)
            if(input[j][i])
                cout << input[j][i];
    
    return 0;
}
