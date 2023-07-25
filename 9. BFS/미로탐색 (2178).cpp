// https://www.acmicpc.net/problem/2178

#include<iostream>
#include<utility> // for pair
#include<queue>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<string> map; // 문자열로 맵 생성
	string s; 

	for (int i = 0; i < n; i++) {
		cin >> s;
		map.push_back(s);
	}

	// map에서 이동한 경로 count
	vector<vector<int>> map_check(n, vector<int>(m, 0));

	queue<pair<int, int>> Q; // 큐 스택, 쌍 입력
	Q.push({ 0,0 });

	pair<int, int> p;

	// 상,하,좌,우
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	int x, y; 
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) { // 상,하,좌,우 탐색
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			else if (map_check[x][y] != 0 || map[x][y] != '1') continue;
			Q.push({ x,y });
			map_check[x][y] = map_check[p.first][p.second] + 1;
			if (x == n - 1 && y == m - 1) cout << map_check[x][y] + 1;
		}
	}
}