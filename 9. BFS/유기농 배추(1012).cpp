// https://www.acmicpc.net/problem/1012

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	while (T != 0) {
		int N, M, K;
		cin >> M >> N >> K;
		queue<pair<int, int>> Q;
		queue<pair<int, int>> Q2;
		pair<int, int> p;
		vector<vector<int>> map(N, vector<int>(M,0));
		for (int i = 0; i < K; i++) {
			cin >> p.second >> p.first;
			Q.push(p);
			map[p.first][p.second] = 1;
		}
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };
		int x, y;
		int count = 0;
		while (!Q.empty()) {
			p = Q.front();
			Q.pop();
			if (map[p.first][p.second] == 2) continue;
			Q2.push(p);
			map[p.first][p.second] = 2;
			while (!Q2.empty()) {
				p = Q2.front();
				Q2.pop();
				for (int i = 0; i < 4; i++) {
					x = p.first + dx[i];
					y = p.second + dy[i];
					if (x<0 || x>=N || y<0 || y>=M) continue;
					else if (map[x][y] == 0 || map[x][y] == 2) continue;
					Q2.push({ x,y });
					map[x][y] = 2;
				}
			}
			count++;
		}
		cout << count << "\n";
		count = 0;
		T--;
	}
}