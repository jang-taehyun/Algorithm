#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int score(char sg, char fr) {	//상근이와 친구의 가위바위보 점수 계산하는 함수
	if (sg == 'S') {
		if (fr == 'S') return 1;
		else if (fr == 'P') return 2;
		else if (fr == 'R') return 0;
	}
	else if (sg == 'P') {
		if (fr == 'S') return 0;
		else if (fr == 'P') return 1;
		else if (fr == 'R') return 2;
	}
	else if (sg == 'R') {
		if (fr == 'S') return 2;
		else if (fr == 'P') return 0;
		else if (fr == 'R') return 1;
	}
}
int main(void) {
	int r, n;
	char sg[51] = {};			//상근이의 패
	char fr[51][51] = {};	//친구들 패

	cin >> r >> sg >> n;		//라운드 수, 상근이의 패, 친구 수 입력
	for (int i = 0; i < n; i++) cin >> fr[i];		//친구들 패 입력

	int point = 0;
	for (int i = 0; i < n; i++) {	//상근이의 현재 점수 구한 후 출력.
		for (int j = 0; j < r; j++) {
			int p = score(sg[j], fr[i][j]);
			point += p;
		}
	}

	int max = 0;
	for (int i = 0; i < r; i++) {
		int best_point=0;
		int s_point = 0;
		int p_point = 0;
		int r_point = 0;
		for (int j = 0; j < n; j++) {      //입력받은 문자열의 세로줄별로 상근이가 가위, 바위,보를
			 s_point += score('S', fr[j][i]); // 냈을 때 얻을 수 있는 점수를 각각 구하여 더한다.
			 p_point += score('P', fr[j][i]);
			 r_point += score('R', fr[j][i]);
		}
        //가위, 바위, 보 중 최대 점수를 얻을 수 있는 수를 구하고, 그 점수를 max에 더한다.
		if (s_point >= p_point && s_point >= r_point) best_point = s_point;
		else if (p_point > s_point && p_point >= r_point) best_point = p_point;
		else if (r_point > s_point && r_point > p_point) best_point = r_point;
		max += best_point;
	}
	cout << point << endl << max; // 상근이의 현재 점수와 최대 점수 출력.
	return 0;
}