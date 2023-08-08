//https://www.acmicpc.net/problem/2146

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int map[101][101]; // ��(1)�� �ٴ�(0) ������ ��
int map_check[101][101]; // �湮���� üũ

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// ���� ��ǥ�� ��ȣ(���̺�)�� ������ 3���� ����
vector<vector<pair<int, int>>> V(10000, vector<pair<int, int>>());


void bfs(int x, int y, int number) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	map_check[x][y] = 1;
	pair<int, int> p;
	int new_x, new_y;
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();

		// ���� �� ��ȣ�� ����ǥ ����
		V[number].push_back({ p.first,p.second });

		for (int i = 0; i < 4; i++) {
			new_x = p.first + dx[i];
			new_y = p.second + dy[i];
			if (map_check[new_x][new_y] == 1) continue;
			else if (map[new_x][new_y] == 1) {
				Q.push({ new_x, new_y });
				map_check[new_x][new_y] = 1;
			}
		}
	}
}

int calcul_dist(int cluster_num) {
	pair<int, int> p1, p2;
	int length, short_length = 999;

	// ���� �� ��ǥ���� �Ÿ��� ��� ���ϰ�, �ִܰŸ� ��ȯ
	for (int i = 1; i < cluster_num; i++) {
		for (int j = i + 1; j < cluster_num; j++) {
			for (int k = 0; k < V[i].size(); k++) {
				p1 = V[i][k];
				for (int p = 0; p < V[j].size(); p++) {
					p2 = V[j][p];
					length = abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1;
					if (short_length > length) short_length = length;
				}
			}
		}
	}

	return short_length;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<pair<int, int>> Q;
	int input_x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input_x;
			map[i][j] = input_x;
			map_check[i][j] = 0; 
			// ���� ��ǥ�� ť�� ����
			if (input_x == 1) Q.push({ i,j }); 
		}
	}

	pair<int, int> p;
	int cluster_number = 1; // ���� ��ȣ �ű�

	while (!Q.empty()) { // ���� Ž��
		p = Q.front();
		Q.pop();
		if (map_check[p.first][p.second] == 1) continue;

		// ���� ���� �̾��� ��� ���� ��ǥ �� ����ȣ ����
		bfs(p.first, p.second, cluster_number++);
	}
	// �ٸ� ���� ���� ��ǥ�� ���� �Ÿ����, �ִܰŸ� ���
	cout << calcul_dist(cluster_number);
}