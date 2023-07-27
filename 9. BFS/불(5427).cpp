//https://www.acmicpc.net/problem/5427

#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<string>
using namespace std;


void print_map(vector<string>& map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	int W, H;

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int x, y;

	for (int k = 0; k < T; k++) {
		cin >> W >> H;

		vector<string> map;
		vector<vector<int>> map_check(H, vector<int>(W));
		string s;
		queue<pair<int, int>> Q2;
		queue<pair<int, int>> Q;
		pair<int, int> p;
		for (int i = 0; i < H; i++) {
			cin >> s;
			map.push_back(s);
			for (int j = 0; j < W; j++) {
				if (s[j] == '@') p = { i,j };
				else if (s[j] == '*') Q2.push({ i,j });
			}
		}
		Q.push(p);
		while (!Q2.empty()) {
			Q.push(Q2.front());
			Q2.pop();
		}
		map_check[p.first][p.second] = 1;

		int short_cut, flag = 0;
		while (!Q.empty()) {
			p = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				x = p.first + dx[i];
				y = p.second + dy[i];
				if (x < -1 || x > H || y < -1 || y > W) continue;
				else if (x == H || y == W || x==-1 || y==-1) {
					if (map[p.first][p.second] == '@') {
						flag = 1;
						short_cut = map_check[p.first][p.second];
						break;
					}
					continue;
				}
				else if (map[x][y] == '#' || map[x][y] == '*') continue;
				if (map[p.first][p.second] == '@') {
					if (map_check[x][y] >= 1) continue;
					map_check[x][y] = map_check[p.first][p.second] + 1;
				}
				Q.push({ x,y });
				map[x][y] = map[p.first][p.second];
			}
			if (flag == 1) break;
			//print_map(map);
		}
		if (flag == 1) cout << short_cut << "\n";
		else cout << "IMPOSSIBLE\n";
	}

}