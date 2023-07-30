//https://www.acmicpc.net/problem/2206
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<tuple>
using namespace std;

int BFS(vector<string> &map, vector<vector<vector<int>>> &map_check, int N, int M) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	queue<tuple<int, int, int>> Q; // tuple ������ 3�� ���ڸ� ���� ť ����.
	Q.push(make_tuple(0, 0, 0));

	int x, y, broken; // ���� ��ǥ�� broken �ߴ��� ������ �޽��ϴ�.
	int new_x, new_y; // ���ο� ��ǥ�� �����մϴ�.
	int distance; // ��������� �̵��� �Ÿ��� ���մϴ�.
	while (!Q.empty()) {
		tie(x, y, broken) = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			new_x = x + dx[i];
			new_y = y + dy[i];
			distance = map_check[broken][x][y] + 1;
			if (new_x == N - 1 && new_y == M - 1) {
				cout << distance + 1;
				return 0;
			}
			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
			if (map[new_x][new_y] == '1' && broken == 0 && map_check[1][new_x][new_y] == -1) {
				Q.push(make_tuple(new_x, new_y, 1));
				map_check[1][new_x][new_y] = distance;
			}
			else if (map[new_x][new_y] == '0' && map_check[broken][new_x][new_y] == -1) {
				Q.push(make_tuple(new_x, new_y, broken));
				map_check[broken][new_x][new_y] = distance;
			}
		}
	}
	cout << -1;
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> map(N);
	string s; 
	for (int i = 0; i < N; i++) {
		cin >> s;
		map[i] = s;
	}

	vector<vector<vector<int>>> map_check(2, vector<vector<int>>(N,vector<int>(M, -1)));
	map_check[0][0][0] = 0; 

	if (N == 1 && M == 1) cout << 1;
	else BFS(map, map_check, N, M);

}