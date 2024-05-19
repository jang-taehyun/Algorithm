#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
bool visited[1000001];

int BFS()
{
    queue<int> search;
    int cur, next;
    int level = 0;
    int size;

    visited[s] = true;
    search.push(s);

    while (!search.empty())
    {
        size = search.size();
        while (size--)
        {
            cur = search.front();
            search.pop();

            if (cur == g)
                return level;

            next = cur + u;
            if ((next > 0 && next <= f) && !visited[next])
            {
                visited[next] = true;
                search.push(next);
            }

            next = cur - d;
            if ((next > 0 && next <= f) && !visited[next])
            {
                visited[next] = true;
                search.push(next);
            }
        }

        level++;
    }

    return -1;
}

int main()
{
    int res;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    res = BFS();
    if (-1 == res)
        cout << "use the stairs";
    else
        cout << res;

    return 0;
}