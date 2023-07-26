//https://www.acmicpc.net/problem/10026

#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<queue>
using namespace std;


int dx[4] = { -1,1, 0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(vector<string> &map, vector<vector<int>> &map_check, int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	char c = map[i][j];
	pair<int, int> p;
	int x, y;
	int N = map.size();
	map_check[i][j] = 1; 
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			else if (map_check[x][y] == 1 || map[x][y] != c) continue;
			Q.push({ x,y });
			map_check[x][y] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<string> map(N);
	vector<string> map_2(N);
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		map[i] = s;
		for (int j = 0; j < N; j++) if (s[j] == 'G') s[j] = 'R';
		map_2[i] = s;
	}

	vector<vector<int>> map_check(N, vector<int>(N));
	vector<vector<int>> map_check_2(N, vector<int>(N));

	int count=0, count2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map_check[i][j] != 1) {
				BFS(map, map_check, i,j);
				count++;
			}
			if (map_check_2[i][j] != 1) {
				BFS(map_2, map_check_2, i, j);
				count2++;
			}
		}
	}
	cout << count << " " << count2;
}