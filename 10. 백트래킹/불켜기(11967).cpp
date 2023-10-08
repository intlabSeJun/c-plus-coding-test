//https://www.acmicpc.net/problem/11967

#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int map[101][101];
queue<pair<int, int>> Q[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int N) {
	pair<int, int> p;
	while (!Q[x][y].empty()) {
		p = Q[x][y].front();
		Q[x][y].pop();
		map[p.first][p.second] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int x, y, a, b;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> a >> b;
		if (i == 1) {
			map[x][y] = 1;
			map[a][b] = 1;
		}
		else {
			if (map[x][y] == 1) {
				map[a][b] = 1;
				dfs(x, y, N);
			}
			else Q[x][y].push({ a,b });
		}
	}



	int total = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) if (map[i][j] == 1) total++;
	}

	cout << total;

}

