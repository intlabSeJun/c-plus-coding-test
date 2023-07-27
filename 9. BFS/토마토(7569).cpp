//https://www.acmicpc.net/problem/7569

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

//for (int i = 0; i < H; i++) {
	//	for (int j = 0; j < N; j++) {
	//		for (int k = 0; k < M; k++) {
	//			cout << map[i][j][k] << " ";
	//		}
	//		cout << "\n";
	//	}
	//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, H;
	cin >> M >> N >> H;

	// 가로 M, 세로 N, 높이 H, 형태의 3차원 벡터 생성 및 초기화
	vector<vector<vector<int>>> map(H, vector<vector<int>>(N,vector<int>(M))); // 모두 0으로 초기화

	int a;
	int un_tomato = 0;
	queue<pair<int, pair<int, int>>> Q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> a;
				if (a == 0) un_tomato++;
				else if (a == 1) Q.push({ i, { j,k } });
				map[i][j][k] = a;
			}
		}
	}

	if (!un_tomato) cout << 0;
	else {
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };
		int dz[2] = { 1,-1 };

		pair<int, pair<int, int>> p;
		int x, y, z;
		int short_day, change_tomato = 0;

		while (!Q.empty()) {
			p.first = Q.front().first;
			p.second = Q.front().second;
			Q.pop();
			for (int i = 0; i < 6; i++) {
				if (i < 4) {
					x = p.second.first + dx[i];
					y = p.second.second + dy[i];
					z = p.first;
				}
				else {
					x = p.second.first;
					y = p.second.second;
					z = p.first + dz[i - 4];
				}
				if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= H) continue;
				else if (map[z][x][y] == -1 || map[z][x][y] >= 1) continue;
				Q.push({ z, {x,y} });
				map[z][x][y] = map[p.first][p.second.first][p.second.second] + 1;
				change_tomato++;

				if (change_tomato == un_tomato) {
					short_day = map[z][x][y];
					break;
				}
			}
		}
		//cout << change_tomato << " " << un_tomato << "\n";
		if (change_tomato != un_tomato) cout << -1;
		else cout << short_day-1;
	}
}