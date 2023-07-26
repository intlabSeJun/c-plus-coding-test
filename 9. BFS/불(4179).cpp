//https://www.acmicpc.net/problem/4179

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
using namespace std;

void print_map(vector<string> &map) {
	/* map�� ���� ���� ���.
	�ڵ尡 �ǵ��Ѵ�� �����ϴ��� Ȯ��.*/
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++)
			cout << map[i][j];
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;

	vector<string> map(R); // ���ڿ� �� ����
	vector<vector<int>> map_check(R, vector<int>(C)); //�̵����� �� �̵��Ÿ� üũ
	queue<pair<int, int>> Q; // ����� ť
	queue<pair<int, int>> Q_for_Fire;  // �ӽ� ť, F�� ��Ƽ� ���� Q�� �Ű��� ����

	for (int i = 0; i < R; i++) { //���ڿ� �޾Ƽ� map�� Q, Q_for_Fire�� �Ҵ�.
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'J') {
				Q.push({ i, j });
				map_check[i][j] = 1;
			}
			else if (map[i][j] == 'F') Q_for_Fire.push({ i,j });
		}
	}

	while (!Q_for_Fire.empty()) {
		// F���� ��ǥ�� Q�� �״´�.
		// Q���� front()�� J ��ǥ�� �����ϱ� ����.
		Q.push(Q_for_Fire.front());
		Q_for_Fire.pop();
	}

	int dx[4] = { -1, 1, 0,0 };
	int dy[4] = { 0,0,-1,1 };

	pair<int, int> p;
	int x, y; // ������ �����¿� ��ǥ
	int short_cut=0; //���� ª�� �Ÿ� ��Ÿ��
	int flag_F = 0; // 1�̸�, F�� J�� ��� ���� ��.
	int flag_J = 0;  // 1�̸�, J�� Ż��. -1�̸� J�� �̵�.
	int J_count = 1; // F�� J�� ����� ��, 1�̸� ��� J�� ���� ��.
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		flag_J = 0; // J�� �̵����� �� Ż�� ���� �ʱ�ȭ
		for (int i = 0; i < 4; i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if ((x == R || y == C || x == -1 || y==-1) && map[p.first][p.second] == 'J') {
				// J�� Ż���� �� ����.
				short_cut = map_check[p.first][p.second]+1;
				flag_J = 1;
				break;
			}
			else if (x < 0 || x >= R || y < 0 || y >= C) continue;
			else if (map[x][y] == '#'|| map[x][y] == 'F') continue;
			else if (map[p.first][p.second] == 'J' && map_check[x][y] == 0) {
				// J�� �̵��� ����.
				Q.push({ x,y });
				map[x][y] = 'J'; // �ʿ� ���ο� J �Ҵ�
				map_check[x][y] = map_check[p.first][p.second] + 1; // �̵��Ÿ� ����������
				flag_J = -1; // J �̵��ߴٰ� ǥ��.
				J_count++; // ���� ���ܳ� J����ŭ count.
			}
			else if (map[p.first][p.second] == 'F') {
				// F�� �̵��� ����
				if (map[x][y] == 'J' && J_count == 1) {
					// J�� ���, J�� ������ 1�� ������ ��, ��� J�� ���� ��.
					flag_F = 1; // J �� ��Ҵٰ� ǥ��.
					break;
				}
				map[x][y] = 'F'; // �ʿ� ���ο� F �Ҵ�
				Q.push({x,y});
			}
			//cout << J_count << "\n";
		}
		
		/*cout << "\n";
		print_map(map);*/
	
		if (flag_J == -1) {
			// J�� �̵����� ��
			J_count--; // �� J�� ���� ����
			map[p.first][p.second] = '.'; // ���� J�� �� ����
		}
		if (flag_J == 1) {
			// J�� Ż������ ��
			cout << short_cut-1; // �ִܰŸ� ���
			break;
		}
		else if (flag_F==1) {
			// J�� ��� ����� ��
			cout << "IMPOSSIBLE";
			break;
		}
	}
	// J�� ���� ���� ��쿡 ����.
	if (flag_J!=1 && flag_F!=1) cout << "IMPOSSIBLE";
}