#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

bool map[101][101]; // 불 켜기 
bool visited[101][101]; // 방문 여부 
int N, M;
int yd[] = { 1, -1, 0,0 };
int xd[] = { 0,0,1, -1 };
vector <pair<int, int>> v[101][101];

int BFS() {
	int ans = 1;
	queue <pair<int, int>> q;
	q.push({ 1,1 }); // start
	visited[1][1] = true;
	map[1][1] = true;
	bool flag = false;

	while (!q.empty()) {
		flag = false;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] != 2) {
			for (int i = 0; i < v[x][y].size(); i++) { // 방에 불켜기
				int a = v[x][y][i].first;
				int b = v[x][y][i].second;
				if (map[a][b] == 1) continue;
				map[a][b] = 1;
				ans++; // 불 켜졌다~!
				flag = true;
			}
			map[x][y] = 2; // 불켜기 진행 완료 체크 
		}

		if (flag) {
			memset(visited, 0, sizeof(visited)); // 불 켜진데부터 다시 출발
			visited[x][y] = true;
			while (!q.empty()) q.pop();
		}

		for (int i = 0; i < 4; i++) { // 이동 
			int nx = x + xd[i];
			int ny = y + yd[i];
			if (nx <= 0 || nx > N)continue;
			if (ny <= 0 || ny > N)continue;
			if (visited[nx][ny] == true)continue;
			if (map[nx][ny] == 0)continue; // 불꺼져있음 
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	return ans;
}
void Input() {
	int x, y, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		v[x][y].push_back({ a,b });
	}
}
int main() {
	Input();
	printf("%d\n", BFS());
}
