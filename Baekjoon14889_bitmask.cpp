/*
problem : n명의 사람을 두 팀으로 나눴을 때 두 팀간의 weight의 차이의 최소값을 구해라.
input : 전체 인원 n, 사람마다 시너지 weigth
output : 두 팀으로 나눴을 때 두 팀간의 weigth의 차이의 최소값

idea : bit 마스크를 이용해 수열 array의 부분 집합 중 bit의 0과 1이 같은 개수인 경우를 찾는다.
이후 시너지 weight를 계산 후 차이를 구한다.
*/
#include <iostream>
using namespace std;

int main()
{
    int people;                // 전체 인원 people == n
    int synergy[20][20];       // 사람마다 시너지 weight
    int result=999999999;      // 두 팀으로 나눴을 때 두 팀간의 시너지의 차이의 최소값
    
    // input 입력
    cin >> people;
    for(int i=0; i<people; i++)
        for(int j=0; j<people; j++)
            cin >> synergy[i][j];
    
    // 전체 인원을 부분 집합으로 나누는 방법 중 bit의 0과 1이 같은 개수인 경우를 찾아 차이를 구한다.
    for(int testcase=1; testcase<(1 << people); testcase++)
    {
        int team1[20];            // team1
        int team2[20];            // team2 
        int teamLength=0;         // 한 팀의 팀원 수 teamLength
        
        int synergyTeam1=0;       // team1의 시너지  
        int synergyTeam2=0;       // team2의 시너지
        
        // 각 경우에서 1의 개수(한 팀의 팀원 수)를 구한다.
        for(int i=0, index1=0, index2=0; i<people; i++)
        {
            if(testcase & (1 << i))
            {
                team1[index1++] = i;
                teamLength++;
            }
            else
                team2[index2++] = i;
        }       
        
        // 만약 두 팀의 팀원이 같지 않다면 다음 경우로 넘어간다.
        if(teamLength != people/2)
            continue;
        
        // 각 팀의 시너지 계산
        for(int i=0; i<teamLength; i++)
        {
            for(int j=0; j<teamLength; j++)
            {
                synergyTeam1 += synergy[team1[i]][team1[j]];
                synergyTeam2 += synergy[team2[i]][team2[j]];
            }
        }
        
        // 시너지 차이 계산 후 이전에 얻은 값과 비교
        result = abs(synergyTeam1-synergyTeam2) < result ? abs(synergyTeam1-synergyTeam2) : result;
    }
    
    // 결과 출력
    cout << result;
    
    return 0;
}
