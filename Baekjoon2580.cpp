#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>blank;
bool finish = false;

//1~9 üũ
bool check(int a, int b, vector<vector<int>>& sudoku) {
	//���� üũ
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][b] == sudoku[a][b] && i != a) return false; //�� Ȯ��
		if (sudoku[a][i] == sudoku[a][b] && i != b) return false; //�� Ȯ��
	}

	//3*3Ȯ��
	int sa = (a / 3) * 3;
	int sb = (b / 3) * 3;
	for (int i = sa; i < sa + 3; i++) {
		for (int j = sb; j < sb + 3; j++) {
			if (i == a && j == b) continue;
			if (sudoku[i][j] == sudoku[a][b]) return false; //��ġ�°� ����
		}
	}

	//��ġ�°� ���ٸ� true��ȯ
	return true;
}

//backtracking �Լ�
void backtracking(int n, vector<vector<int>>& sudoku) {
	if (n == blank.size()) { //��� ĭ �� ä��
		finish = true;
		return;
	}

	//n��° ��ĭ ��ǥ
	int a = blank[n].first;
	int b = blank[n].second;

	for (int i = 1; i <= 9; i++) {
		sudoku[a][b] = i; //1~9�־��
		if (check(a, b, sudoku)) {
			backtracking(n + 1, sudoku);
		};

		if (finish) return; //������ �ϼ� => ��� ����
	}

	sudoku[a][b] = 0; //��ä��� �ǵ�����
	return;
}

//solution�Լ�
vector<vector<int>> solution(vector<vector<int>> sudoku) {
	//blank�� �� ���� ����
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (sudoku[i][j] == 0)
				blank.push_back(make_pair(i, j));


	backtracking(0, sudoku);
	return sudoku;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//�Է�
	vector<vector<int>>sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	//���� �ذ�
	auto output = solution(sudoku);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << output[i][j] << ' ';
		}cout << '\n';
	}
	return 0;
}