/*
problem : 집합 S에 관한 6개의 명령어를 수행하는 프로그램을 만들어라.
input : 명령어의 개수 n, 명령어 line
output : 명령어 수행 결과

idea : bit 연산자를 이용해 명령어를 만든다.
*/
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int commandCount;
    cin >> commandCount;
    
    int storage=0;
    
    string command;
    int input;
    while(commandCount--)
    {
        cin >> command;
        
        if(command == "add")
        {
            cin >> input;
            
            // OR 연산 이용
            storage |= (1 << input);
        }
        else if(command == "remove")
        {
            cin >> input;
            
            // AND 연산, NOT 연산 이용
            storage &= ~(1 << input);
        }
        else if(command == "check")
        {
            cin >> input;
            
            if((1 << input) & storage)
                cout << true << '\n';
            else 
                cout << false << '\n';
        }
        else if(command == "toggle")
        {
            cin >> input;
            
            // XOR 연산 이용
            storage ^= (1 << input);
        }
        else if(command == "all")
        {
            storage = (1 << 21) - 1;
        }
        else if(command == "empty")
        {
            storage=0;
        }
    }
    
    return 0;
}
