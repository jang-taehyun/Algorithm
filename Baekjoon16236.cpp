#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int N;

int board[20][20];
int visited[20][20];
int cnt;
int sharkSize = 2;
const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, -1, 1, 0 };

struct cmp {
    bool operator()(pair<int, int >& a, pair<int, int>& b) {
        if (visited[a.X][a.Y] > visited[b.X][b.Y]) return true; //�Ÿ� ��
        else if (visited[a.X][a.Y] == visited[b.X][b.Y]) {
            if (a.X > b.X) return true; // ���� ����
            else if (a.X == b.X) return a.Y > b.Y; // ���� ����
            else return false;
        }
        else return false;
    }
};
queue<pair<int, int> > Q;
priority_queue < pair<int, int>, vector<pair<int, int> >, cmp >pq;


void bfs() {
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] != -1) continue;
            if (board[nx][ny] != 0 && board[nx][ny] > sharkSize)continue; //�ڽ� ���� ū ����Ⱑ �ִ� ĭ�� ������ �� ����

            if (board[nx][ny] == sharkSize || board[nx][ny] == 0) {//ũ�Ⱑ ���ų� ��ĭ�̸� �׳� ��������.
                Q.push({ nx, ny });
                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            }
            else { // ũ�Ⱑ ���� ����Ⱑ ������
                Q.push({ nx, ny });
                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                pq.push({ nx, ny });
            }
        }
    }
}
int solve() {
    int ret = 0;
    int ate = 0;
    while (cnt) {
        pq = {}; // init 
        fill(&visited[0][0], &visited[19][20], -1);

        pair<int, int> start = Q.front();
        visited[start.X][start.Y] = 0;
        bfs();
        if (pq.size() == 0) break; //���� �� �ִ� ����Ⱑ ���� ��

        auto target = pq.top();
        board[start.X][start.Y] = 0;
        board[target.X][target.Y] = 9;
        ret += visited[target.X][target.Y];
        Q.push({ target.X, target.Y });
        ate++;
        if (ate == sharkSize) {
            ate = 0;
            sharkSize++;
        }
        cnt--;
    }
    return ret;

}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 6) cnt++;
            else if (board[i][j] == 9) Q.push({ i, j });
        }
    }
    cout << solve();

    return 0;
}

// https://seokjin2.tistory.com/133