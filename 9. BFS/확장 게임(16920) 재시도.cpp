//https://www.acmicpc.net/problem/16920
#include<iostream>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

int map[1001][1001];
int iter_num[10];
int castle_num[10];
queue < tuple<int, int, int >> QT[10];

void print_map(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, P;
	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++) cin >> iter_num[i];

	string s;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') map[i][j] = -1;
			else if (s[j] == '.') continue;
			else {
				x = s[j] - '0';
				map[i][j] = x;
				QT[x].push({ i,j,0 });
				castle_num[x]++;
			}
		}
	}
	int new_x, new_y, cur_x, cur_y, step, castle;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	while (1) {
		int flag = 0;
		for (int i = 1; i <= P; i++) {
			queue<tuple<int, int, int>> nextQT;
			while (!QT[i].empty()) {
				tie(cur_x, cur_y, step) = QT[i].front();
				QT[i].pop();
				castle = map[cur_x][cur_y];

				if (step >= iter_num[castle]) {
					nextQT.push({ cur_x, cur_y, 0 });
					continue;
				}

				for (int j = 0; j < 4; j++) {
					new_x = cur_x + dx[j];
					new_y = cur_y + dy[j];
					if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
					else if (map[new_x][new_y] != 0) continue;
					QT[i].push({ new_x, new_y, step + 1 });
					map[new_x][new_y] = castle;
					castle_num[castle]++;
					flag = 1;
					//print_map(N, M);
				}
			}
			QT[i] = nextQT;
		}
		if (flag == 0) break;
	}

	for (int i = 1; i <= P; i++) cout << castle_num[i] << " ";
}