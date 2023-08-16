// https://www.acmicpc.net/problem/13549

/*
1. ������ǥ���� �� 2�� �ؼ� �ش� ��ǥ�� ��� ť�� ����
   - ��, K��ǥ�� �� ���� �ѵ��� ��

2. ť�� ���� ��ǥ�鿡�� +, -�� �ѹ��� ����.
   - ���� ��ǥ�� target�� ��쿡 ������� �ɸ��ð� ��� �� ����
   - ���� ��ǥ�� �̹� �湮���� �ÿ��� �н�
 
*/
#include<iostream>
#include<queue>
using namespace std;

int map_check[200005];

int dx[2] = { -1,1 };

// ���� ��ġ(x)�� ������ ��ġ���� üũ
int check_target(int x, int K) {
	if (x == K) {
		cout << map_check[x]-1;
		return 1;
	}
	return 0;
}

// ������ ��ǥ�� Ž���ϰ�, �湮���� �� �ð�(��)�� +1
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

	if (N > K) cout << N-K; //���� > ����
	else if (N == K) cout << 0; // ���� ��ġ
	else { // ���� < ����
		map_check[N] = 1;

		int x_org, x, x_2, flag=0;
		queue<int> Q1, Q2; 
		// Q1 : ������ǥ ��ǥ ť
		// Q2 : �����̵� ��ǥ ť
		Q1.push(N);
		while (!Q1.empty()) {
			x_org = Q1.front();
			Q1.pop();
			Q2.push(x_org);

			// �����̵����� ��� ��ǥ ����
			while (!Q2.empty()) { 
				x = Q2.front();
				Q2.pop();
				x_2 = x * 2;
				if (K * 2 <= x_2) continue; //limit ����
				if (map_check[x_2] >= 1) continue;
				map_check[x_2] = map_check[x];
				Q2.push(x_2);
				Q1.push(x_2);

				// �����̵��� ������ �������� ġũ
				flag = check_target(x_2, K);
				if (flag == 1) break;
			}
			if (flag == 1) break;

			// ���� X-1, X+1 ��ǥ Ž�� �� Q1�� ����
			flag = bfs(x_org, K, Q1);
			if (flag == 1) break;
		}
	}
}