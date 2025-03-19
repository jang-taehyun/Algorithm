#include <iostream>
#include <string>
using namespace std;

int king_y, king_x, rock_y, rock_x;
int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void Move(int dir);

int main()
{
    char tmp1, tmp2;
    int count;
    string command;
    int dir;
    int tmp3;
    
    cin >> tmp1 >> tmp2;
    king_y = 8 - (int)(tmp2 - '0');
    king_x = (int)tmp1 - 'A';
    
    cin >> tmp1 >> tmp2;
    rock_y = 8 - (int)(tmp2 - '0');
    rock_x = (int)tmp1 - 'A';
    
    cin >> count;
    while(count--)
    {
        cin >> command;
        
        if("R" == command)
            dir = 0;
        else if("L" == command)
            dir = 1;
        else if("B" == command)
            dir = 2;
        else if("T" == command)
            dir = 3;
        else if("RT" == command)
            dir = 4;
        else if("LT" == command)
            dir = 5;
        else if("RB" == command)
            dir = 6;
        else if("LB" == command)
            dir = 7;
        
        Move(dir);
    }
    
    tmp1 = king_x + 'A';
    tmp2 = (8 - king_y) + '0';
    cout << tmp1 << tmp2 << '\n';
    
    tmp1 = rock_x + 'A';
    tmp2 = (8 - rock_y) + '0';
    cout << tmp1 << tmp2 << '\n';
    
    return 0;
}

void Move(int dir)
{
    int king_ny, king_nx, rock_ny, rock_nx;
    
    king_ny = king_y + dy[dir];
    king_nx = king_x + dx[dir];
    
    if(king_ny < 0 || king_ny >= 8 || king_nx < 0 || king_nx >= 8)
        return;
    
    if(king_ny == rock_y && king_nx == rock_x)
    {
        rock_ny = rock_y + dy[dir];
        rock_nx = rock_x + dx[dir];
        
        if(rock_ny < 0 || rock_ny >= 8 || rock_nx < 0 || rock_nx >= 8)
            return;
        
        rock_y = rock_ny;
        rock_x = rock_nx;
    }
    
    king_y = king_ny;
    king_x = king_nx;
}
