#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    string tmp;
    int happy=0, sad=0;
    
    getline(cin, input);
    for(int i=0; i<input.length()-2; ++i)
    {
        tmp = input[i];
        tmp += input[i+1];
        tmp += input[i+2];
        
        if(":-)" == tmp)
            ++happy;
        else if(":-(" == tmp)
            ++sad;
    }
    
    if(!happy && !sad)
        cout << "none";
    else if(happy > sad)
        cout << "happy";
    else if(happy < sad)
        cout << "sad";
    else
        cout << "unsure";
    
    return 0;
}
