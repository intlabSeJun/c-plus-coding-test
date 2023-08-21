// https://www.acmicpc.net/problem/16933

#include<iostream>
#include<tuple>
#include<queue>
#include<string>
using namespace std;

int map[1001][1001];

// 11������ �����Ͽ�, 0������ ���� �μ� ������ ��+1���Ͽ� ���
int map_check[11][1001][1001]; 

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int bfs(int N, int M, int K) {
	if (N == 1 && M == 1) return 1; // ���� 1x1�϶� ���ǹ�
	queue<tuple<int, int, int, int, int>> Q; //cur_x, cur_y, floor, sun_or_moon, stay
	Q.push(make_tuple(1, 1, 0, 1, 0)); // (1,1)���� ����, �� = 1, �� = -1
	map_check[0][1][1] = 1; // 0�� (1,1)�������� count

	tuple<int, int, int, int, int> T;
	int cur_x, cur_y, new_x, new_y, floor, sun_or_moon, stay;
	while (!Q.empty()) {
		T = Q.front();
		Q.pop();
		tie(cur_x, cur_y, floor, sun_or_moon, stay) = T;
		for (int i = 0; i < 4; i++) {
			new_x = cur_x + dx[i];
			new_y = cur_y + dy[i];
			if (new_x <1 || new_x >N || new_y < 1 || new_y > M) continue;
			if (new_x == N && new_y == M) return map_check[floor][cur_x][cur_y] + 1;
			if (map[new_x][new_y] == 1) { // ���� ���
				if (floor == K) continue; // �̹� ���� K����ŭ �μ� ���
				if (map_check[floor + 1][new_x][new_y] != 0) continue; // ���� ���� �̹� �湮�� ���
				if (sun_or_moon == 1) { // ���� ���
					map_check[floor + 1][new_x][new_y] = map_check[floor][cur_x][cur_y] + 1 + stay;
					Q.push({ new_x,new_y,floor + 1, sun_or_moon * -1 , 0});
				}
				else  //���� ��� 
					Q.push({ cur_x, cur_y, floor, sun_or_moon * -1 , 1});
			}
			else { // ���� �ƴ� ���
				if (map_check[floor][new_x][new_y] != 0) continue;
				map_check[floor][new_x][new_y] = map_check[floor][cur_x][cur_y] + 1;
				Q.push({ new_x,new_y,floor, sun_or_moon * -1 , 0});
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	string s;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) map[i][j] = s[j - 1] - '0';
	}

	cout << bfs(N, M, K);

}