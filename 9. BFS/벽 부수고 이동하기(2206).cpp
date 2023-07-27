//https://www.acmicpc.net/problem/2206

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<string>
using namespace std;


//void print_map(vector<vector<int>> &map) {
//	for (int i = 0; i < map.size(); i++) {
//		for (int j = 0; j < map[0].size(); j++)
//			cout << map[i][j];
//		cout << "\n";
//	}
//	cout << "\n";
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map_check(N, vector<int>(M));
	vector<vector<int>> broken_map_check(N, vector<int>(M));
	char map[1002][1002];

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
		}
	}

	map_check[0][0] = 1;
	map_check[N - 1][M - 1] = 7777;

	broken_map_check[0][0] = 1;
	broken_map_check[N - 1][M - 1] = 7777;

	queue<pair<pair<int, int>, int>> Q;
	Q.push({ {0,0}, 0 });

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int x, y;
	pair<int, int> p;
	int broken;

	int short_cut=0, flag = 0;
	if (N == 1 && M == 1) cout << 1;
	else {
		while (!Q.empty()) {
			p = Q.front().first;
			broken = Q.front().second;
			Q.pop();
			//print_map(broken_map_check);
			for (int i = 0; i < 4; i++) {
				x = p.first + dx[i];
				y = p.second + dy[i];
				if (x < 0 || x >= N || y < 0 || y >= M) continue;
				if (broken == 1) {
					if (map[x][y] == '1') continue;
					else if ((broken_map_check[x][y] >= 1 && broken_map_check[x][y] != 7777) || (map_check[x][y] >=1&& map_check[x][y] != 7777)) continue;
					if (broken_map_check[x][y] == 7777) {
						flag = 1;
						short_cut = broken_map_check[p.first][p.second] + 1;
						break;
					}
					broken_map_check[x][y] = broken_map_check[p.first][p.second] + 1;
					Q.push({ {x,y}, 1 });
				}
				else {
					if (map_check[x][y] >= 1 && map_check[x][y] != 7777) continue;
					else if (map[x][y] == '1') {
						if (broken_map_check[x][y] != 0) continue;
						broken_map_check[x][y] = map_check[p.first][p.second] + 1;
						Q.push({ {x,y}, 1 });
					}
					else Q.push({ {x,y},0 });
					if (map_check[x][y] == 7777) {
						flag = 1;
						short_cut = map_check[p.first][p.second] + 1;
						break;
					}
					map_check[x][y] = map_check[p.first][p.second] + 1;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) cout << short_cut;
		else cout << -1;
	}
}