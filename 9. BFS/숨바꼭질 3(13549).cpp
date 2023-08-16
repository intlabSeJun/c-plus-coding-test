// https://www.acmicpc.net/problem/13549

/*
1. 시작좌표에서 곱 2를 해서 해당 좌표를 모두 큐에 쌓음
   - 단, K좌표를 한 번만 넘도록 함

2. 큐에 쌓은 좌표들에서 +, -를 한번씩 해줌.
   - 다음 좌표가 target일 경우에 현재까지 걸린시간 출력 및 종료
   - 다음 좌표를 이미 방문했을 시에는 패스
 
*/
#include<iostream>
#include<queue>
using namespace std;

int map_check[200005];

int dx[2] = { -1,1 };

// 현재 위치(x)가 동생의 위치인지 체크
int check_target(int x, int K) {
	if (x == K) {
		cout << map_check[x]-1;
		return 1;
	}
	return 0;
}

// 인접한 좌표를 탐색하고, 방문여부 및 시간(초)를 +1
int bfs(int x, int K, queue<int>& Q) {
	int new_x, flag=0;
	for (int i = 0; i < 2; i++) {
		new_x = x + dx[i];
		if (map_check[new_x] >= 1 || new_x < 0) continue;
		map_check[new_x] = map_check[x] + 1;
		flag = check_target(new_x, K);
		if (flag == 1) break;
		Q.push(new_x);
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	if (N > K) cout << N-K; //수빈 > 동생
	else if (N == K) cout << 0; // 같은 위치
	else { // 수빈 < 동생
		map_check[N] = 1;

		int x_org, x, x_2, flag=0;
		queue<int> Q1, Q2; 
		// Q1 : 인접좌표 좌표 큐
		// Q2 : 순간이동 좌표 큐
		Q1.push(N);
		while (!Q1.empty()) {
			x_org = Q1.front();
			Q1.pop();
			Q2.push(x_org);

			// 순간이동으로 모든 좌표 구함
			while (!Q2.empty()) { 
				x = Q2.front();
				Q2.pop();
				x_2 = x * 2;
				if (K * 2 <= x_2) continue; //limit 설정
				if (map_check[x_2] >= 1) continue;
				map_check[x_2] = map_check[x];
				Q2.push(x_2);
				Q1.push(x_2);

				// 순간이동시 동생을 만나는지 치크
				flag = check_target(x_2, K);
				if (flag == 1) break;
			}
			if (flag == 1) break;

			// 인접 X-1, X+1 좌표 탐색 및 Q1에 쌓음
			flag = bfs(x_org, K, Q1);
			if (flag == 1) break;
		}
	}
}