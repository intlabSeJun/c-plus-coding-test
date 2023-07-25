//https://www.acmicpc.net/problem/7576

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n; // 맵크기 받음

	// 맵 생성
	vector<vector<int>> map(n,vector<int>(m));

	// 토마토 좌표 저장할 큐 공간 새엇ㅇ
	queue<pair<int, int>> Q;

	int not_tomato = 0; // 입력시 안익은 토마토 개수 count
	int input_x; // 매 입력 받음

	// 토마토 정보 입력
	// 안익은 토마토 개수 카운트.
	// 익은 토마토 좌표 큐에 쌓음.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input_x;
			map[i][j] = input_x;
			if (input_x == 0) not_tomato++;
			else if (input_x == 1) Q.push({ i,j }); 
		}
	}

	if (not_tomato == 0) cout << 0; // 안익은 토마토 없을시
	else {
		// 탐색할 상,하,좌,우 좌표
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };

		pair<int, int> p;

		int x, y;
		int max_day = 0; // 날짜 카운트
		int tomato_change_count = 0; // 익은 토마토로 바뀐 개수 카운트
		while (!Q.empty()) { // BFS
			p = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				x = p.first + dx[i];
				y = p.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				else if (map[x][y] >= 1 || map[x][y] == -1) continue;
				Q.push({ x,y });
				map[x][y] = map[p.first][p.second] + 1; // map에 날짜를 카운트해준다
				if (map[x][y] > max_day) max_day = map[x][y]; // max_day 갱신
				tomato_change_count++; // 토마토가 바뀔 때마다 카운트
			}
		}
		// 안익은 토마토와 바뀐 토마토의 개수가 동일하다면,
		if (tomato_change_count == not_tomato) cout << max_day-1;
		else cout << -1;
	}
}
