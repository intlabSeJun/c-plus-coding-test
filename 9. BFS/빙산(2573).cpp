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
	while (!Q.empty()) { //�̾��� ���� ��� ����
		p = Q.front();
		Q.pop();
		int erase = 0;
		map_check[p.first][p.second] = year; //�湮����üũ
		for (int i = 0; i < 4; i++) { //�����¿� �湮
			new_x = p.first + dx[i];
			new_y = p.second + dy[i];
			if (map_check[new_x][new_y] == year) continue;
			if (map[new_x][new_y] <= 0) erase++; //0�ϰ��
			else { // ������ ��� �ش� ��ǥ ť�� push
				Q.push({ new_x, new_y });
				map_check[new_x][new_y] = year;
			}
		}
		map[p.first][p.second] -= erase; //������ǥ ���� ���̱�
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
				x = i; //bfs������ǥ
				y = j; // bfs������ǥ	
				total_ice++;
			}
			map_check[i][j] = 0;
		}
	}

	int current_ice, year_count = 1, erased_ice=0;
	while (1) {
		current_ice = bfs(x,y, year_count, erased_ice);
		if (erased_ice == total_ice) { //���� �и� x
			cout << 0;
			break;
		}
		if (current_ice != total_ice) { //���� �и� o
			cout << year_count-1;
			break;
		}
		total_ice -= erased_ice; // ���� ���� ����
		year_count++; // year+1
		erased_ice = 0;
	}
}