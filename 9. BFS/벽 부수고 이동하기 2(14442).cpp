//https://www.acmicpc.net/problem/14442

#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;

int map[1005][1005] = {};
int map_check[11][1005][1005] = {};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int N, int M, int K) {
	if (N == 1 && M == 1) return 1;

	map_check[0][1][1] = 1;
	queue<tuple<int, int, int>> Q; // 0,1 : ÁÂÇ¥ | 2 : current_floor
	Q.push(make_tuple(1, 1, 0));

	tuple<int, int, int> T;
	int cur_x, cur_y, new_x, new_y, cur_floor;
	while (!Q.empty()) {
		T = Q.front();
		Q.pop();

		cur_x = get<0>(T);
		cur_y = get<1>(T);
		cur_floor = get<2>(T);
		for (int i = 0; i < 4; i++) {
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (new_x < 1 || new_x >N || new_y<1 || new_y>M) continue;
			if (new_x == N && new_y == M) return map_check[cur_floor][cur_x][cur_y] + 1;

			if (map[new_x][new_y] == 1) {
				if(cur_floor == K) continue;
				if(map_check[cur_floor + 1][new_x][new_y] != 0)continue;
				map_check[cur_floor + 1][new_x][new_y] = map_check[cur_floor][cur_x][cur_y] + 1;
				Q.push(make_tuple(new_x, new_y, cur_floor + 1));
			}
			else {
				if (map_check[cur_floor][new_x][new_y] != 0) continue;
				map_check[cur_floor][new_x][new_y] = map_check[cur_floor][cur_x][cur_y] + 1;
				Q.push(make_tuple(new_x, new_y, cur_floor));
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <=M; j++) map[i][j] = s[j-1]-'0';
	}

	cout << bfs(N, M, K);
}