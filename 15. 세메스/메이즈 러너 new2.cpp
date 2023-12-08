/*
1. ��� �̵�
 1) �����¿� ����
  - �� �� : ��� x < �ⱸ x &
  - �� �� : 
2. map �̵�

*/

#include<iostream>
#include<utility>
using namespace std;

int N, M, K;  // (��ũ��, ������ ��, K��)
int map[15][15] = {}; // �̷� �� ���� = 1~9, exit = -1
int exit_x, exit_y;  // �ⱸ ��ǥ

int print_on = false;  // �˻縦 ���� print 

// ��� ���� ����ü�� ����
struct person {
	int x, y;  // ���� ��ǥ
	int dist;  // �̵��� �Ÿ�
	bool exit;  // Ż�� ���� 
};

person P[15];  // ����� ����ü ����

void print_map() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= M; i++)
		cout << "person " << i << "(x,y,dist,exit) :" <<  P[i].x << " " << P[i].y << " " << P[i].dist << " " << P[i].exit << "\n";
	cout << "eixt : " << exit_x << " " << exit_y << "\n";
	cout << "\n";
}

void is_finish(int i) {  // ������ Ż�������� ����.
	if (P[i].x == exit_x && P[i].y == exit_y)
		P[i].exit = true;
}

void move_person() {
	// ������ 1~M���� ���� �ⱸ�� ��������� �������� 1ĭ �̵�
	// ���� ��ġ���� ������� �ϸ�, �����δ� �̵� �Ұ�
	// �̵� �켱������ �����¿�
	for (int i = 1; i <= M; i++) {
		if (P[i].exit)  // ������ Ż��� 
			continue;

		// ������ x,y ��ǥ ����
		int& x = P[i].x;
		int& y = P[i].y;

		// �켱������ ������� �ϳ��� �Ǻ��Ͽ� ������ �̵��Ѵ�.
		// �ⱸ�� �����ں��� ����(row ����)�� ���� ��
		if (x > exit_x && map[x - 1][y] <= 0) {  // ���� �̵�
			x--;
			P[i].dist++;
			is_finish(i);
		}
		// �ⱸ�� �����ں��� �Ʒ���(row ����)�� ���� ��
		else if (x < exit_x && map[x + 1][y] <= 0) {  // �Ʒ��� �̵�
			x++;
			P[i].dist++;
			is_finish(i);
		}
		// �ⱸ�� �����ں��� ������(column ����)�� ������
		else if (y < exit_y && map[x][y + 1] <= 0) {  // ��� �̵�
			y++;
			P[i].dist++;
			is_finish(i);
		}
		// �ⱸ�� �����ں��� ����(column ����)�� ������
		else if (y > exit_y && map[x][y - 1] <= 0)  // �·� �̵� 
		{
			y--;
			P[i].dist++;
			is_finish(i);
		}
	}
}

void get_coord(int& r, int& c, int& a, int& b) {
	// �ڽ��� ũ�⸦ �÷����鼭, �ڽ� ���� �ⱸ�� ����� �ִ��� ����.
	for (int d = 2; d <= N; d++) {
		for (int rx = 1; rx <= N - d + 1; rx++) {
			for (int cy = 1; cy <= N - d + 1; cy++) {
				int ax = rx + d - 1;
				int by = cy + d - 1;

				if (exit_x < rx || exit_x > ax || exit_y < cy || exit_y > by)  // �ⱸ�� �ڽ� ���� ���� ��� 
					continue;

				bool is_person = false;
				for (int i = 1; i <= M; i++) {
					if (P[i].x < rx || P[i].x > ax || P[i].y < cy || P[i].y > by || P[i].exit)  // ����� �ڽ� ���� ���� ��� 
						continue;
					is_person = true;
				}

				if (is_person) {  //�ڽ��� ��� �����.
					r = rx;
					c = cy;
					a = ax;
					b = by;

					return;
				}
			}
		}
	}
}

void rotation() {
	int r, c, a, b;  // �»��, ���ϴ� ��ǥ

	get_coord(r, c, a, b);  // get �»��, ���ϴ�

	if (print_on) {
		cout << "r c a b :" << r << " " << c << " " << a << " " << b << "\n";
	}

	int map_buf[15][15] = {};  // ȸ���� �迭�� �ӽ� ������ ����.

	// rotate map block and exit
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			if (map[i][j] == -1) {  // �ⱸ �� ���
				exit_x = r + j - c; // x��ǥ 90�� ȸ�� ����
				exit_y = b - (i - r);  // y��ǥ 90�� ȸ�� ����
				map_buf[r + j - c][b - (i - r)] = map[i][j];  // �ӽ� ����
			}
			if(map[i][j] > 0)
				map_buf[r + j - c][b - (i - r)] = map[i][j] - 1;  // block ����
		}
	}

	// rotate again, ���� map�� �ٽ� ����.
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			map[i][j] = map_buf[i][j];
		}
	}

	// person rotate
	int is_rotate_person[15] = {};  // ȸ���� ��ǥ�� ����
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			for (int k = 1; k <= M; k++) {  // ��� ������� ��ǥ���� box ���� �� ����� �̵�.
				if (P[k].exit || is_rotate_person[k] == 1)
					continue;
				if (P[k].x == i && P[k].y == j) {  // ����� �̵�
					P[k].x = r + j - c;  // x��ǥ 90�� �̵� ����
					P[k].y = b - (i - r);  // y��ǥ 90�� �̵� ����
					is_rotate_person[k] = 1;  // ȸ�� ���� üũ
				}
			}
		}
	}
}

bool check() {
	for (int i = 1; i <= M; i++)
		if (!P[i].exit)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;  // ��ũ��, ������ ��, �ݺ� �� 

	//�� ���� �ޱ�, ��(1~9) or �����(0)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	//������ �ʱ� ��ǥ �ޱ�, �ߺ�x, �ʱ�ȭ(dist, exit)
	for (int i = 1; i <= M; i++) {
		cin >> P[i].x >> P[i].y;
		P[i].dist = 0;
		P[i].exit = false;
	}

	cin >> exit_x >> exit_y;  // �ⱸ ��ǥ �ޱ�
	map[exit_x][exit_y] = -1;  // �ⱸ�� -1�� map�� ǥ��

	if (print_on) {
		cout << "init\n";
		print_map();
	}

	for (int i = 1; i <= K; i++) {
		move_person();  // ��� �̵�
		if (print_on) {
			cout << "moved person\n";
			print_map();
		}

		if (check())  // ��� ����� exit �ߴ��� Ȯ��
			break;

		rotation();  // �� ȸ��
		if (print_on) {
			cout << "rotation\n";
			print_map();
		}
	}	

	int ans = 0;
	for (int i = 1; i <= M; i++) {  // ��� ������ �̵��� �Ÿ� �ջ�
		ans += P[i].dist;
	}

	// ��� ���
	cout << ans << "\n";
	cout << exit_x << " " << exit_y;

}
