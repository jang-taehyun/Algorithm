#include <iostream>
#include <deque>
#define BOUND 100001
#define MAX 99999999
using namespace std;

int Start = 0, End = 0;
int VisitedCount[BOUND];

int BFS()
{
    deque<pair<int, int>> next;
    next.push_front(make_pair(Start, 0));
    VisitedCount[Start] = 0;

    int DequeSize, CurrentPoint, CurrentTime;
    while (!next.empty())
    {
        DequeSize = next.size();
        for (int i = 0; i < DequeSize; i++)
        {
            CurrentPoint = next.front().first;
            CurrentTime = next.front().second;
            next.pop_front();

            if (CurrentPoint == End)
            {
                VisitedCount[End] = VisitedCount[End] < CurrentTime ? VisitedCount[End] : CurrentTime;
                continue;
            }

            if (CurrentPoint && 2 * CurrentPoint < BOUND
                && (VisitedCount[2 * CurrentPoint] == MAX || VisitedCount[2 * CurrentPoint] > CurrentTime))
            {
                next.push_front(make_pair(2 * CurrentPoint, CurrentTime));
                VisitedCount[2 * CurrentPoint] = CurrentTime;
            }

            if (CurrentPoint + 1 < BOUND
                && (VisitedCount[CurrentPoint + 1] == MAX || VisitedCount[CurrentPoint + 1] > CurrentTime + 1))
            {
                next.push_back(make_pair(CurrentPoint + 1, CurrentTime + 1));
                VisitedCount[CurrentPoint + 1] = CurrentTime + 1;
            }

            if (CurrentPoint - 1 >= 0
                && (VisitedCount[CurrentPoint - 1] == MAX || VisitedCount[CurrentPoint - 1] > CurrentTime))
            {
                next.push_back(make_pair(CurrentPoint - 1, CurrentTime + 1));
                VisitedCount[CurrentPoint - 1] = CurrentTime + 1;
            }
        }
    }

    return VisitedCount[End];
}

int main()
{
    for (int i = 0; i < BOUND; i++)
        VisitedCount[i] = MAX;

    cin >> Start >> End;

    cout << BFS();

    return 0;
}