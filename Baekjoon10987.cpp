#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[101] = {0, };
    int res=0;
    
    cin >> input;
    for(int i=0; i<strlen(input); ++i)
        switch(input[i])
        {
            case 'a': case 'e': case 'i':
            case 'o': case 'u':
                ++res;
        }
    
    cout << res;
    
    return 0;
}
