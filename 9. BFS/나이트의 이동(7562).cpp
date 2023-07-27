//https://www.acmicpc.net/problem/7562

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int l;
	pair<int, int> current_knite_pos;
	pair<int, int> target_knite_pos;

	int dx[8] = { 2,2,-2,-2,-1,1,-1,1 };
	int dy[8] = { 1,-1,1,-1,2,2,-2,-2 };
	int x, y;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> l >> current_knite_pos.first >> current_knite_pos.second;
		cin >> target_knite_pos.first >> target_knite_pos.second;
		
		queue<pair<int, int>> Q;
		vector<vector<int>> map(l, vector<int>(l));

		Q.push(current_knite_pos);
		map[current_knite_pos.first][current_knite_pos.second] = 1;

		int flag = 0, short_cut = 0;
		while (!Q.empty()) {
			current_knite_pos = Q.front();
			Q.pop();
			for (int i = 0; i < 8; i++) {
				x = current_knite_pos.first + dx[i];
				y = current_knite_pos.second + dy[i];
				if (x < 0 || x >= l || y < 0 || y >= l) continue;
				else if (map[x][y] >= 1) continue;
				Q.push({ x,y });
				map[x][y] = map[current_knite_pos.first][current_knite_pos.second] + 1;
				if (x == target_knite_pos.first && y == target_knite_pos.second) {
					flag = 1;
					short_cut = map[x][y]-1;
					break;
				}
			}
			if (flag == 1) break;
		}
		cout << short_cut << "\n";
	
	}
}