//https://www.acmicpc.net/problem/1600
/*
원숭이가 말처럼 점프할 때마다 map_check의 층수를 늘린다.
- 각 층의 번호는 원숭이가 점프한 횟수에 대한 map_check
- 각 층의 방문여부가 곧 최단거리가 된다. 즉, 2번 점프한 층에서 이미 방문한 곳은 다시 안하게 설정
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int map[205][205] = {};
int map_check[35][205][205] = {};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int jump_x[8] = { 2,2, 1, -1, -2,-2, 1, -1 };
int jump_y[8] = { 1, -1, 2, 2,  1, -1, -2, -2 };


int target_check(int x, int y, int w, int h) {
	if (x == h - 1 && y == w - 1) return 1;
	else return 0;
}

int layer_check(int layer, int x, int y, int future) {
	int flag = 0;
	if (future == 1) layer++;
	
	for (int i = 0; i <= layer; i++) {
		if (map_check[i][x][y] != 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int bfs(int k, int w, int h) {
	queue<pair<pair<int, int>, int>> Q;
	Q.push({ {0,0}, 0 });
	map_check[0][0][0] = 1;

	int new_x, new_y, layer;
	pair<int, int> p;
	
	while (!Q.empty()) {
		p = Q.front().first;
		layer = Q.front().second;
		Q.pop();

		if (layer != k) {
			for (int i = 0; i < 8; i++) {
				new_x = p.first + jump_x[i];
				new_y = p.second + jump_y[i];

				if (new_x < 0 || new_x >= h || new_y < 0 || new_y >= w) continue;
				if (map[new_x][new_y] == 1) continue;

				int flag_target = 0;
				flag_target = target_check(new_x, new_y, w, h);
				if (flag_target == 1) return map_check[layer][p.first][p.second];

				int flag_layer = 0;
				flag_layer = layer_check(layer, new_x, new_y, 1); // 이전 레이어 모두와 다음 레이어 방문여부 체크
				if (flag_layer == 1) continue;

				map_check[layer+1][new_x][new_y] = map_check[layer][p.first][p.second] + 1;
				Q.push({ { new_x,new_y }, layer+1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			new_x = p.first + dx[i];
			new_y = p.second + dy[i];
			if (new_x < 0 || new_x >= h || new_y < 0 || new_y >= w) continue;
			if (map[new_x][new_y] == 1 || map_check[layer][new_x][new_y] != 0) continue;

			int flag_target = 0;
			flag_target = target_check(new_x, new_y, w, h);
			if (flag_target == 1) return map_check[layer][p.first][p.second];

			int flag_layer = 0;
			flag_layer = layer_check(layer, new_x, new_y, 0); // 이전 레이어 방문 여부만 체크 
			if (flag_layer == 1) continue;

			map_check[layer][new_x][new_y] = map_check[layer][p.first][p.second] + 1;
			Q.push({ {new_x, new_y}, layer});
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, w, h;
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> map[i][j];
	}

	if (w == h && w == 1) cout << 0;
	else cout << bfs(k,w,h);
}
