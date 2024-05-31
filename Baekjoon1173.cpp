#include <iostream>
#include <queue>
using namespace std;

bool visited[200][200];
int target, MinPulse, MaxPulse, Adder, Subtract;

int BFS()
{
    queue<pair<int, int>> search;
    int level = 0;
    int size;
    int curP, curT, nextP, nextT;

    search.push(make_pair(MinPulse, 0));
    visited[MinPulse][0] = true;

    while (!search.empty())
    {
        size = search.size();
        while (size--)
        {
            curP = search.front().first;
            curT = search.front().second;
            search.pop();

            if (curT == target)
                return level;

            if (curP + Adder <= MaxPulse && !visited[curP + Adder][curT + 1])
            {
                search.push(make_pair(curP + Adder, curT + 1));
                visited[curP + Adder][curT + 1] = true;
            }

            nextP = curP - Subtract;
            if (nextP < MinPulse)
                nextP = MinPulse;

            if (!visited[nextP][curT])
            {
                search.push(make_pair(nextP, curT));
                visited[nextP][curT] = true;
            }
        }

        level++;
    }

    return -1;
}

int main()
{
    cin >> target >> MinPulse >> MaxPulse >> Adder >> Subtract;
    cout << BFS();

    return 0;
}