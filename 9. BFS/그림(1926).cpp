//https://www.acmicpc.net/problem/1926

#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m)); // 초기값은 0으로 세팅됨.
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

	vector<vector<int>> v_check(n, vector<int>(m));  // 방문확인을 위한 그리드.

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0, 0,-1,1 };

	queue<pair<int, int>> q;

	int x, y;
	pair<int, int> p;
	int count = 0;
	int bigsize = 0, size_count=0;

	for (int k = 0; k < n; k++) {
		for (int j = 0; j < m; j++) {
			if (v_check[k][j] == 1 || v[k][j] == 0) continue;
			count++;
			size_count = 0;
			q.push({ k,j });
			v_check[k][j] = 1;
			while (!q.empty()) {
				p = q.front();
				q.pop();
				size_count++;
				for (int i = 0; i < 4; i++) {
					x = p.first + dx[i];
					y = p.second + dy[i];
					if (x<0 || x>=n || y<0 || y>=m) continue;
					else if (v_check[x][y] == 1 || v[x][y] == 0) continue;
					q.push({ x,y });
					v_check[x][y] = 1;
				}
			}
			
			if (bigsize < size_count) bigsize = size_count;
		}
	}
	cout << count << "\n" << bigsize;

}