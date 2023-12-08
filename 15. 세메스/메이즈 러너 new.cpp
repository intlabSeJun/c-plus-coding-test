/*
������ ����ü ����
- ��ǥ, �̵�Ƚ��, Ż�� ����

���� ���� ���� map�� ����

exit ��ǥ�� ������ ����

1. ������ �̵�
 - �ּ� �Ÿ��� �켱���� ������ �̵�
 - �̵� �Ŀ� exit���� �Ÿ��� ����
 - ���� �Ÿ��߿� ���� ª�� �Ÿ��� ���� ������ ��ȣ ����
 - Ż�� ��, ������ exit ���� ����
 - Ż���� �����ڴ� ����

2. ȸ��
 - �տ��� ���� ������ ��ȣ�� �����ϴ� ���� ���� ���簢�� ���� ����
 - 8�������� ��Ÿ�� �� ����.
   - �� ���⸶���� �ٸ� ������ ���ϵ��� ���ǹ�
   - �»��(x,y)�� �ʺ�(w), ����(h)�� ����.
 - �»�ܺ��� �ð����(����)���� �ݺ���
   - ���簪�� �����ϰ�, �������� ���� ��ǥ�� �Ҵ��ϴ� ���(swap)
 - ȸ���� block�� �� -1

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, M, K; //(��ũ��, ������ ��, K��)
int map_block[15][15] = {};  // block ����
int exit_x, exit_y;  // �ⱸ ��ǥ 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int print_on = true;

struct person {
	int x, y, dist;  // (��ǥ), �̵��� �Ÿ�
	bool exit;  // Ż�� ����
};

person P[12];  // ��� ����, 1~M����.

void print_map() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map_block[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= M; i++) {
		cout << "person (" << i << ") : " << P[i].x << " " << P[i].y << " "
			<< "|exit : " << P[i].exit << " |dist : " << P[i].dist << "\n";
	}
	cout << "exit : " << exit_x << " " << exit_y << "\n";
	cout << "\n";
}
int get_dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int move() {
	/*
1. ������ �̵�
 - �ּ� �Ÿ��� �켱���� ������ �̵�
 - �̵� �Ŀ� exit���� �Ÿ��� ����
 - ���� �Ÿ��߿� ���� ª�� �Ÿ��� ���� ������ ��ȣ ����
 - Ż�� ��, ������ exit ���� ����
 - Ż���� �����ڴ� ����
	*/

	int cur_dist, new_dist, short_person_dist = 999999, short_person = -1;
	int new_x, new_y, short_x, short_y;
	for (int i = 1; i <= M; i++) {
		if (P[i].exit)
			continue;

		cur_dist = get_dist(P[i].x, P[i].y, exit_x, exit_y);

		int short_dist = 9999999;
		int flag = 0;
		for (int j = 0; j < 4; j++) {  // get direction, short_dist
			new_x = P[i].x + dx[j];
			new_y = P[i].y + dy[j];
			if (new_x < 1 || new_y < 1 || new_x > N || new_y > N) continue;
			if (map_block[new_x][new_y] > 0) continue;
			if (new_x == exit_x && new_y == exit_y) {
				P[i].exit = true;
				P[i].dist++;
				flag = 0;
				break;
			}
			new_dist = get_dist(new_x, new_y, exit_x, exit_y);
			if (new_dist > cur_dist)
				continue;

			if (new_dist < short_dist) {
				short_dist = new_dist;
				short_x = new_x;
				short_y = new_y;
				flag = 1;
			}
		}
		if (flag == 0)  // �̵� ������.
			continue;

		P[i].dist++;
		P[i].x = short_x;
		P[i].y = short_y;
		if (short_dist < short_person_dist) {
			short_person_dist = short_dist;
			short_person = i;
		}
		else if (short_dist == short_person_dist) {  // ª�� �Ÿ� ���� ��
			if (P[i].x < P[short_person].x) {
				short_person_dist = short_dist;
				short_person = i;
			}
			else if (P[i].x == P[short_person].x) {
				if (P[i].y < P[short_person].y) {
					short_person_dist = short_dist;
					short_person = i;
				}
			}
		}
	}

	return short_person;
}

int get_short_person() {
	int cur_dist, short_dist = 999999, short_person = -1;
	for (int i = 1; i <= M; i++) {
		if (P[i].exit)
			continue;
		cur_dist = get_dist(P[i].x, P[i].y, exit_x, exit_y);
		if (cur_dist < short_dist) {
			short_dist = cur_dist;
			short_person = i;
		}
		else if (cur_dist == short_dist) {  // ª�� �Ÿ� ���� ��
			if (P[i].x < P[short_person].x) {
				short_dist = cur_dist;
				short_person = i;
			}
			else if (P[i].x == P[short_person].x) {
				if (P[i].y < P[short_person].y) {
					short_dist = cur_dist;
					short_person = i;
				}
			}
		}
	}

	return short_person;
}

bool check_box(int a, int b) {  // �»�� or ���ϴ� ��ǥ �޾Ƽ� ���ɿ��� �Ǵ�
	if (a < 1 || a > N || b < 1 || b > N)
		return false;
	return true;
}

void block_break(int x, int y) {
	if (map_block[x][y] != 0)
		map_block[x][y]--;
}

void rotation(int short_person) {
	/*
	2. ȸ��
	 - �տ��� ���� ������ ��ȣ�� �����ϴ� ���� ���� ���簢�� ���� ����
	 - 8�������� ��Ÿ�� �� ����.
	   - �� ���⸶���� �ٸ� ������ ���ϵ��� ���ǹ�
	   - �»��(r,c)�� �ʺ�(w)�� ����.
	 - �»�ܺ��� �ð����(����)���� �ݺ���
	   - ���簪�� �����ϰ�, �������� ���� ��ǥ�� �Ҵ��ϴ� ���(swap)
	 - ȸ���� block�� �� -1

	 ���� �»��(r,c), ���ϴ�(a,b)�� ���Ѵٸ�,
	 ���� ���� �ִ� �����ڵ��� �����Ѵ�.
	 �׸��� w�������� ������, �� ������ ���� �����ڵ��� ��ǥ�� �������� Ȯ��?
	 �����ϴٸ�, �̵��ؾ� �ϰ� ���ܽ��Ѿ� ��.
	*/
	if (short_person == -1) // �ƹ��� �̵��� ������ ��, ���� ª�� ��� ����.
		short_person = get_short_person();
	if (short_person == -1)  // ��� ������ Ż��� ����.
		return;

	int x, y, w;
	int r, c; // �»��
	int a, b; // ���ϴ�
	x = P[short_person].x;
	y = P[short_person].y;

	// �ⱸ�� ��������, (r,c), (a,b) ����. 8���� ���ǹ�
	if (x == exit_x && y < exit_y) {  // ����
		w = exit_y - y;
		for (int i = exit_x - w; i <= exit_x; i++) {
			if (i < 1)
				continue;
			r = i;
			c = y;
			a = i + w;
			b = exit_y;
			break;
		}
	}
	else if (x == exit_x && y > exit_y) { // ����
		w = y - exit_y;
		for (int i = exit_x - w; i <= exit_x; i++) {
			if (i < 1)
				continue;
			r = i;
			c = exit_y;
			a = i + w;
			b = y;
			break;
		}
	}
	else if (x < exit_x && y == exit_y) { // ���
		w = exit_x - x;
		for (int i = exit_y - w; i <= exit_y; i++) {
			if (i < 1)
				continue;
			r = x;
			c = i;
			a = exit_x;
			b = i+w;
			break;
		}
	}
	else if (x > exit_x && y == exit_y) { // �ϴ�
		w = x - exit_x;
		for (int i = exit_y - w; i <= exit_y; i++) {
			if (i < 1)
				continue;
			r = exit_x;
			c = i;
			a = x;
			b = i+w;
			break;
		}
	}
	else if (x < exit_x && y < exit_y) { // �»��
		if (exit_x - x > exit_y - y) {
			w = exit_x - x;
			for (int i = exit_y - w; i <= exit_y; i++) {
				if (i < 1)
					continue;
				r = x;
				c = i;
				a = exit_x;
				b = i + w;
				break;
			}
		}
		else {
			w = exit_y - y;
			for (int i = exit_x - w; i <= x; i++) {
				if (i < 1)
					continue;
				r = i;
				c = y;
				a = i + w;
				b = exit_y;
				break;
			}
		}
	}
	else if (x > exit_x && y < exit_y) { // ���ϴ�
		if (x - exit_x > exit_y - y)
		{
			w = x - exit_x;
			for (int i = exit_y - w; i <= exit_y; i++) {
				if (i < 1)
					continue;
				r = exit_x;
				c = i;
				a = x;
				b = i + w;
				break;
			}

		}
		else {
			w = exit_y - y;
			for (int i = exit_y - w; i <= exit_y; i++) {
				if (i < 1)
					continue;
				r = exit_x;
				c = i;
				a = x;
				b = i + w;
				break;
			}
		}
	}
	else if (x < exit_x && y > exit_y) { // ����
		if (exit_x - x > y - exit_y)
			w = exit_x - x;
		else
			w = y - exit_y;

		for (int i = y - w; i <= y; i++) {
			if (i < 1)
				continue;
			r = x;
			c = i;
			a = exit_x;
			b = i + w;
			break;
		}
	}
	else if (x > exit_x && y > exit_y) { // ���ϴ�
		if (x - exit_x > y - exit_y)
			w = x - exit_x;
		else
			w = y - exit_y;

		for (int i = y - w; i <= y; i++) {
			if (i < 1)
				continue;
			r = exit_x;
			c = i;
			a = x;
			b = i + w;
			break;
		}
	}
	else cout << "wrong@@\n";

	if (print_on) {
		cout << "(r,c), (a,b) : (" << r << "," << c << "), (" << a << "," << b << ")\n";
	}

	queue<int> person_idx;

	for (int i = 1; i <= M; i++) {  //���� ���� �ִ� ������ �״´�.
		if (P[i].exit)
			continue;
		if (P[i].x >= r && P[i].x <= a && P[i].y >= c && P[i].y <= b)
			person_idx.push(i);
	}

	// map�� person �̵�. 
	int p_idx, p_size;
	int map_block_buf[15][15] = {};  // block ����
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			if (map_block[i][j] != 0) {
				if (map_block[i][j] == -1)
				{
					map_block_buf[r + j - c][b + r - i] = map_block[i][j];
					exit_x = r + j - c;
					exit_y = b + r - i;
				}
				else
					map_block_buf[r + j - c][b + r - i] = map_block[i][j] - 1;
				
			}
			else {
				p_size = person_idx.size();
				for (int k = 0; k < p_size; k++) {
					p_idx = person_idx.front();
					person_idx.pop();
					if (i == P[p_idx].x && j == P[p_idx].y) {
						P[p_idx].x = r + j - c;
						P[p_idx].y = b + r - i;
					}
					else person_idx.push(p_idx);
				}
			}
		}
	}

	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			map_block[i][j] = map_block_buf[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map_block[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> P[i].x >> P[i].y;
		P[i].dist = 0;
		P[i].exit = false;
	}

	cin >> exit_x >> exit_y;
	map_block[exit_x][exit_y] = -1;

	if (print_on) {
		cout << "�ʱ����\n";
		print_map();
	}

	int short_p;
	for (int i = 0; i < K; i++) {  // K�� ���� 
		short_p = move();  // ������ �̵�

		if (print_on) {
			cout << "��� �̵�, short_p = " << short_p << "\n";
			print_map();
		}

		rotation(short_p);  // map ȸ��
		if (print_on) {
			cout << "map ȸ��\n";
			print_map();
		}
	}

	int ans = 0;
	for (int i = 1; i <= M; i++) {
		ans += P[i].dist;
	}

	cout << ans << "\n";
	cout << exit_x << " " << exit_y;
}
