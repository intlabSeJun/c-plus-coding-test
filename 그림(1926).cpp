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

	// 2차원 가변배열 생성
	vector<vector<int>> v(n, vector<int>(m)); // 초기값은 0으로 세팅됨.

	// 배열에 입력받은 숫자들 차례로 저장
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

	// 방문확인을 위한 그리드 생성, 모두 0.
	vector<vector<int>> v_check(n, vector<int>(m)); 

	// search할 방향, 상하좌우
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0, 0,-1,1 };

	// 탐색좌표를 담을 큐 공간
	queue<pair<int, int>> q;

	int x, y; // 갱신된 상하좌우 좌표 넣을 공간
	pair<int, int> p; // 탐색좌표를 하나씩 가져올 공간
	int count = 0; // 도형의 개수 
	int bigsize = 0, size_count=0; // 가장 큰 사이즈와, 현재 사이즈

	// 이중 반복문으로 모든 그리드 영역 탐색
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < m; j++) {
			// 이미 탐색했거나, 0인 좌표는 pass
			if (v_check[k][j] == 1 || v[k][j] == 0) continue;
			count++; // 도형 개수 +1
			size_count = 0; // 현재 도형 크기 초기화
			q.push({ k,j }); // 현재 좌표 쌓음
			v_check[k][j] = 1; 
			while (!q.empty()) { // BFS 알고리즘
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