#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int N, K, D;
int map[105][105] = {};
pair<int, int> apple_coord[105];
pair<int, int> snake_dir[105];
queue<pair<int, int>> snake_path;

void print_arr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (K != 0) {
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) cin >> apple_coord[i].first;
				else cin >> apple_coord[i].second;
			}
			map[apple_coord[i].first-1][apple_coord[i].second-1] = 2;
		}
	}

	cin >> D;
	char c;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) cin >> snake_dir[i].first;
			else {
				cin >> c;
				if (c == 'D') snake_dir[i].second = 1;
				else snake_dir[i].second = -1;
			}
		}
	}

	map[0][0] = 1;
	snake_path.push({ 0,0 });
	int cnt = 0;
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };
	int dir = 2;
	
	int cur_x = 0, cur_y = 0;
	int new_x, new_y;
	int dir_point = 0;

	//print_arr();
	while (1) {
		new_x = cur_x + dx[dir];
		new_y = cur_y + dy[dir];

		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N || map[new_x][new_y] == 1) break;
		if (map[new_x][new_y] != 2) {
			pair<int, int> p;
			p = snake_path.front();
			map[p.first][p.second] = 0;
			snake_path.pop();
		}
		map[new_x][new_y] = 1;
		snake_path.push({ new_x, new_y });

		cur_x = new_x;
		cur_y = new_y;
		cnt++;

		if (snake_dir[dir_point].first == cnt) {
			dir += snake_dir[dir_point].second;
			if (dir == 4) dir = 0;
			else if (dir == -1) dir = 3; 
			dir_point++;
		}
	}
	cout << cnt+1;
}