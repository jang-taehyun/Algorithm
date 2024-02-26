/*
problem : 각 vertex에서 A->B->C->D->E와 같은 관계가 있다면 true를, 아니라면 false를 출력해라.
input : vertex의 개수 n, vertex간의 관계
output : A->B->C->D->E와 같은 관계가 있다면 true를, 아니라면 false

idea : DFS 방식으로 graph를 탐색해 5개의 vertex를 모두 탐색했다면 true를 출력하고, 아니라면 false를 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;

int vertexNumber;             // vertex의 개수 vertexNumber == n
vector<int> relation[2000];   // vertex간의 관계 relation
int relationNumber;           // 관계의 수 relationNumber
bool isVisited[2000];         // vertex 방문 여부 isVisited
bool result=false;            // 관계 탐색 결과 result

void DFS(int currentCount, int searchIndex)
{ 
    // 현재 vertex를 포함한 5개의 vertex을 방문했다면, 결과를 true로 만든 후 탐색 종료
    if(currentCount == 4)
    { 
        result = true;
        return;
    }
    
    isVisited[searchIndex] = true;
    
    // DFS 방식으로 각 연결된 vertex를 방문한다.
    for(int i=0; i<relation[searchIndex].size(); i++)
        if(!isVisited[relation[searchIndex][i]])
            DFS(currentCount+1, relation[searchIndex][i]);
    
    isVisited[searchIndex] = false;
}

int main()
{
    // input 입력
    cin >> vertexNumber >> relationNumber;
    for(int i=0; i<relationNumber; i++)
    {
        int index1, index2;
        cin >> index1 >> index2;
        relation[index1].push_back(index2);
        relation[index2].push_back(index1);
    }
    
    // DFS 방식으로 그래프 탐색
    for(int i=0; i<vertexNumber; i++)
        DFS(0, i);
    
    // 결과 출력
    cout << result;
    
    return 0;
}
