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
	cin >> m >> n; // ��ũ�� ����

	// �� ����
	vector<vector<int>> map(n,vector<int>(m));

	// �丶�� ��ǥ ������ ť ���� ������
	queue<pair<int, int>> Q;

	int not_tomato = 0; // �Է½� ������ �丶�� ���� count
	int input_x; // �� �Է� ����

	// �丶�� ���� �Է�
	// ������ �丶�� ���� ī��Ʈ.
	// ���� �丶�� ��ǥ ť�� ����.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input_x;
			map[i][j] = input_x;
			if (input_x == 0) not_tomato++;
			else if (input_x == 1) Q.push({ i,j }); 
		}
	}

	if (not_tomato == 0) cout << 0; // ������ �丶�� ������
	else {
		// Ž���� ��,��,��,�� ��ǥ
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };

		pair<int, int> p;

		int x, y;
		int max_day = 0; // ��¥ ī��Ʈ
		int tomato_change_count = 0; // ���� �丶��� �ٲ� ���� ī��Ʈ
		while (!Q.empty()) { // BFS
			p = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				x = p.first + dx[i];
				y = p.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				else if (map[x][y] >= 1 || map[x][y] == -1) continue;
				Q.push({ x,y });
				map[x][y] = map[p.first][p.second] + 1; // map�� ��¥�� ī��Ʈ���ش�
				if (map[x][y] > max_day) max_day = map[x][y]; // max_day ����
				tomato_change_count++; // �丶�䰡 �ٲ� ������ ī��Ʈ
			}
		}
		// ������ �丶��� �ٲ� �丶���� ������ �����ϴٸ�,
		if (tomato_change_count == not_tomato) cout << max_day-1;
		else cout << -1;
	}
}
