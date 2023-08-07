//https://www.acmicpc.net/problem/2573

#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int map[301][301];
int map_check[301][301];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int bfs(int &x, int &y, int year, int &erased_ice) {
	queue<pair<int, int>> Q;
	pair<int, int> p;
	Q.push({ x,y });
	int new_x, new_y;
	int count_ice = 0;
	while (!Q.empty()) { //이어진 빙산 모두 추적
		p = Q.front();
		Q.pop();
		int erase = 0;
		map_check[p.first][p.second] = year; //방문여부체크
		for (int i = 0; i < 4; i++) { //상하좌우 방문
			new_x = p.first + dx[i];
			new_y = p.second + dy[i];
			if (map_check[new_x][new_y] == year) continue;
			if (map[new_x][new_y] <= 0) erase++; //0일경우
			else { // 빙산일 경우 해당 좌표 큐에 push
				Q.push({ new_x, new_y });
				map_check[new_x][new_y] = year;
			}
		}
		map[p.first][p.second] -= erase; //현재좌표 빙산 녹이기
		if (map[p.first][p.second] <= 0) erased_ice++;
		else {
			x = p.first;
			y = p.second;
		}
		count_ice++;
	}
	return count_ice;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int x_v, x, y, total_ice = 0;;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x_v;
			map[i][j] = x_v;
			if (x_v > 0) {
				x = i; //bfs시작좌표
				y = j; // bfs시작좌표	
				total_ice++;
			}
			map_check[i][j] = 0;
		}
	}

	int current_ice, year_count = 1, erased_ice=0;
	while (1) {
		current_ice = bfs(x,y, year_count, erased_ice);
		if (erased_ice == total_ice) { //빙산 분리 x
			cout << 0;
			break;
		}
		if (current_ice != total_ice) { //빙산 분리 o
			cout << year_count-1;
			break;
		}
		total_ice -= erased_ice; // 남은 빙산 업뎃
		year_count++; // year+1
		erased_ice = 0;
	}
}