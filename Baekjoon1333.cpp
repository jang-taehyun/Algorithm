#include <iostream>
using namespace std;

// Baekjoon Q.1333
int main() {
	int N, L, D,time=0,res=0;
	cin >> N >> L >> D;
	
    // 노래의 개수만큼 반복
	for (int i = 1; i <= N; i++) {
    	// 노래의 길이만큼 반복, 시간++
		for (int j = 1; j <= L; j++) time++;
        // 노래가 끝나는 시간부터 5번(5초) 반복하며 조건 검사
		for (int t = 1; t <= 5; t++) {
        	// 현재 시간(time)이 벨 간격(D)와 일치할때 종료시킴
			if ((time % D) == 0) {
				res = time;
				i = N;
				break;
			}
			time++;
		}
        // 만약 노래가 모두 끝날때까지 조건을 만족하지 않으면 반복
		if (i == N && res == 0) {
			while (1) {
            	// 현재 시간(time)이 벨 간격(D)와 일치할때 종료시킴
				if ((time % D) == 0) {
					res = time;
					break;
				}
				time++;
			}
		}
	}
	cout << res;

	return 0;
}