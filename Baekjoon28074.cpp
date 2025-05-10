#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[101] = {0, };
    int alpha[26] = {0, };
    
    cin >> input;
    for(int i=0; i<strlen(input); ++i)
        ++(alpha[input[i] - 'A']);
    
    if(alpha['M' - 'A'] && alpha['O' - 'A'] && alpha['B' - 'A'] &&
      alpha['I' - 'A'] && alpha['S' - 'A'])
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
