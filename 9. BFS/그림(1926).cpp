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

	// 2���� �����迭 ����
	vector<vector<int>> v(n, vector<int>(m)); // �ʱⰪ�� 0���� ���õ�.

	// �迭�� �Է¹��� ���ڵ� ���ʷ� ����
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

	// �湮Ȯ���� ���� �׸��� ����, ��� 0.
	vector<vector<int>> v_check(n, vector<int>(m)); 

	// search�� ����, �����¿�
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0, 0,-1,1 };

	// Ž����ǥ�� ���� ť ����
	queue<pair<int, int>> q;

	int x, y; // ���ŵ� �����¿� ��ǥ ���� ����
	pair<int, int> p; // Ž����ǥ�� �ϳ��� ������ ����
	int count = 0; // ������ ���� 
	int bigsize = 0, size_count=0; // ���� ū �������, ���� ������

	// ���� �ݺ������� ��� �׸��� ���� Ž��
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < m; j++) {
			// �̹� Ž���߰ų�, 0�� ��ǥ�� pass
			if (v_check[k][j] == 1 || v[k][j] == 0) continue;
			count++; // ���� ���� +1
			size_count = 0; // ���� ���� ũ�� �ʱ�ȭ
			q.push({ k,j }); // ���� ��ǥ ����
			v_check[k][j] = 1; 
			while (!q.empty()) { // BFS �˰���
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