#include<iostream>
#include<queue>
#include<utility>
//#include<bits/stdc++.h>
using namespace std;

int N, M, P, C, D; //(����, �ϼ�, ��Ÿ��, ����1, ����2)
int map[55][55] = {}; // �� ����, �� ��Ÿ ��ȣ 1~P, �絹�� -1, (1,1)���� ����

// santa �̵� ����, �����¿� ����
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool print_on = false;

struct santa_info {
	int x;  
	int y;
	int status;  // ����=1~2, ����=0, �ƿ�=-1
	int score; // ���� ����.
};

santa_info santas[35];  // 1�� index ~ �ִ� 30�� index ���.

struct roodol_info { // �絹��
	int x;
	int y;
};

roodol_info roodol;

int get_distance(int &x1, int &y1, int &x2, int &y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int get_short_idx(int& x1, int& y1, int &x2, int &y2, int& dir1, int& dir2) {
	int new_x1, new_y1;
	new_x1 = x1 + dx[dir1];
	new_y1 = y1 + dy[dir1];
	int shortest = get_distance(x2, y2, new_x1, new_y1);

	new_x1 = x1 + dx[dir2];
	new_y1 = y1 + dy[dir2];
	int shortest2 = get_distance(x2, y2, new_x1, new_y1);
	if (shortest > shortest2)
		return 1;
	else return 0;
}

pair<int, int> santa_move_direction(int& x1, int& y1, int& x2, int& y2) {  // santa x1,y1 and roodol x2,y2
	if (x1 == x2 && y1 > y2)
		return { 2, -1 }; // ���� �̵� ��ȣ, -1
	else if (x1 == x2 && y1 < y2)
		return { 3, -1 }; // ���� �̵� ��ȣ, -1
	else if (x1 > x2 && y1 == y2)
		return { 0, -1 }; // ���� �̵� ��ȣ, -1
	else if (x1 < x2 && y1 == y2)
		return { 1, -1 }; // �Ʒ��� �̵� ��ȣ, -1
	else if (x1 > x2 && y1 > y2)
		return { 0, 2 }; // ���� �̵� ��ȣ, ���� �̵� ��ȣ
	else if (x1 > x2 && y1 < y2)
		return { 0, 3 }; // ���� �̵� ��ȣ, ���� �̵� ��ȣ
	else if (x1 < x2 && y1 < y2)
		return { 3, 1 }; // ���� �̵� ��ȣ, �Ʒ��� �̵� ��ȣ
	else if (x1 < x2 && y1 > y2)
		return { 1, 2 }; // �Ʒ��� �̵� ��ȣ, ���� �̵� ��ȣ
	else cout << "wrong@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

pair<int, int> roodol_move_direction(int& x1, int& y1, int& x2, int& y2) {  // roodol x,y and santas x,y
	if (x1 == x2 && y1 > y2)
		return { 0, -1 }; // ���� �̵�
	else if (x1 == x2 && y1 < y2)
		return { 0, 1 }; // ���� �̵�
	else if (x1 > x2 && y1 == y2)
		return { -1, 0 }; // ���� �̵�
	else if (x1 < x2 && y1 == y2)
		return { 1, 0 }; // �Ʒ��� �̵�
	else if (x1 > x2 && y1 > y2)
		return { -1, -1 }; // �»�� �̵�
	else if (x1 > x2 && y1 < y2)
		return { -1, 1 }; // ���� �̵�
	else if (x1 < x2 && y1 < y2)
		return { 1, 1 }; // ���ϴ� �̵�
	else if (x1 < x2 && y1 > y2)
		return { 1, -1 }; // ���ϴ� �̵�
	else cout << "wrong@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

void print_map_and_score() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "score: ";
	for (int i = 1; i <= P; i++)
		cout << santas[i].score << " ";
	cout << "\n";
	cout << "stun: ";
	for (int i = 1; i <= P; i++)
		cout << santas[i].status << " ";
	cout << "\n\n";
}

void move() {
	// ���� turn �Ҹ�
	for (int i = 1; i <= P; i++)
		if (santas[i].status > 0) santas[i].status--;

	// 1. �絹�� ���� 
	int short_santa_num, short_dist = 9999999;
	int cur_dist;
	for (int i = 1; i <= P; i++) { // ���� �絹���� ���� ����� ��Ÿ ��ȣ ����
		if (santas[i].status == -1) continue;  // out ��Ÿ ����.
		cur_dist = get_distance(roodol.x, roodol.y, santas[i].x, santas[i].y);
		if (cur_dist < short_dist) {
			short_dist = cur_dist;
			short_santa_num = i;
		}
		else if (cur_dist == short_dist) { // �Ÿ��� ���� ��Ÿ ���� ���� ���
			if (santas[i].x == santas[short_santa_num].x) {
				if (santas[i].y > santas[short_santa_num].y)
					short_santa_num = i;
			}
			else if (santas[i].x > santas[short_santa_num].x)
				short_santa_num = i;
		}
	}

	if (short_dist == 9999999) return; // ��� ��Ÿ out.

	// �絹�� �̵��� ���� ����
	pair<int, int> roodol_dir = roodol_move_direction(roodol.x, roodol.y, santas[short_santa_num].x, santas[short_santa_num].y);

	map[roodol.x][roodol.y] = 0; //���� ��ǥ ����
	roodol.x += roodol_dir.first;
	roodol.y += roodol_dir.second;
	map[roodol.x][roodol.y] = -1; //�絹�� ��ǥ ����

	// �絹�� -> ��Ÿ �浹��
	if (roodol.x == santas[short_santa_num].x && roodol.y == santas[short_santa_num].y) {
		santas[short_santa_num].score += C;
		santas[short_santa_num].x += roodol_dir.first * C;
		santas[short_santa_num].y += roodol_dir.second * C;
		if (santas[short_santa_num].x > N || santas[short_santa_num].y > N || santas[short_santa_num].x < 1 || santas[short_santa_num].y < 1)
			santas[short_santa_num].status = -1; // �ƿ�
		else {
			santas[short_santa_num].status = 2; // ����

			queue<int> Q;
			Q.push(short_santa_num);

			while (!Q.empty()) {
				int cur_santa = Q.front();
				Q.pop();

				if (map[santas[cur_santa].x][santas[cur_santa].y] != 0) {
					int new_santa = map[santas[cur_santa].x][santas[cur_santa].y];
					santas[new_santa].x += roodol_dir.first;
					santas[new_santa].y += roodol_dir.second;
					if (santas[new_santa].x > N || santas[new_santa].y > N || santas[new_santa].x < 1 || santas[new_santa].y < 1)
						santas[new_santa].status = -1;
					else Q.push(new_santa);
				}
				map[santas[cur_santa].x][santas[cur_santa].y] = cur_santa;
			}
		}
	}

	//�絹�� �̵� ���
	if (print_on) {
		cout << "rodool\n";
		print_map_and_score();
	}

	// ��Ÿ �̵�
	for (int i = 1; i <= P; i++) {
		if (santas[i].status != 0) continue;

		pair<int, int> santa_dir = santa_move_direction(santas[i].x, santas[i].y, roodol.x, roodol.y);

		int dir[2];
		dir[0] = santa_dir.first;
		dir[1] = santa_dir.second;
		
		if (dir[1] != -1) {
			int short_idx = get_short_idx(santas[i].x, santas[i].y, roodol.x, roodol.y, dir[0], dir[1]);

			if (short_idx == 1) {
				int buf;
				buf = dir[0];
				dir[0] = dir[1];
				dir[1] = buf;
			}
		}

		for (int j = 0; j < 2; j++) {
			if (dir[j] == -1) continue;
			
			int new_x, new_y;
			new_x = santas[i].x + dx[dir[j]];
			new_y = santas[i].y + dy[dir[j]];

			int buf = get_distance(santas[i].x, santas[i].y, new_x, new_y);

			if (map[new_x][new_y] == -1) {  // �絹�� ������
				
				santas[i].score += D;
				santas[i].status = 2; //����

				// �ݴ� �������� ƨ���� ��.
				new_x -= dx[dir[j]]*D;
				new_y -= dy[dir[j]]*D;

				map[santas[i].x][santas[i].y] = 0;
				santas[i].x = new_x;
				santas[i].y = new_y;

				if (new_x > N || new_y > N || new_x < 1 || new_y < 1) {
					santas[i].status = -1; // �ƿ�
					break;
				}

				queue<int> Q2;
				Q2.push(i);

				while (!Q2.empty()) {
					int cur_santa, cur_x, cur_y;
					cur_santa = Q2.front();
					cur_x = santas[cur_santa].x;
					cur_y = santas[cur_santa].y;
					Q2.pop();

					if (map[cur_x][cur_y] != 0) {
						int new_santa = map[cur_x][cur_y];
						
						santas[new_santa].x -= dx[dir[j]];
						santas[new_santa].y -= dy[dir[j]];

						if (santas[new_santa].x > N || santas[new_santa].y > N || santas[new_santa].x < 1 || santas[new_santa].y < 1) {
							santas[new_santa].status = -1; // �ƿ�
						}
						else Q2.push(new_santa);
					}
					map[cur_x][cur_y] = cur_santa;
				}

				break;
			}
			else if (map[new_x][new_y] == 0) { // �����
				map[santas[i].x][santas[i].y] = 0;
				map[new_x][new_y] = i;
				santas[i].x = new_x;
				santas[i].y = new_y;
				break;
			}
		}

	}

	// ��Ÿ �̵� ���
	if (print_on) {
		cout << "santa\n";
		print_map_and_score();
	}

	// �ϸ��� ���� �ִ� ��Ÿ +1
	for (int i = 1; i <= P; i++) {
		if (santas[i].status != -1) santas[i].score++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> P >> C >> D;

	int x, y;
	cin >> x >> y;  // �絹�� ��ġ
	roodol.x = x;
	roodol.y = y;
	map[x][y] = -1;

	int santa_num;
	for (int i = 1; i <= P; i++) {
		cin >> santa_num >> x >> y; // santa ��ȣ, ��ġ
		santas[santa_num].x = x;
		santas[santa_num].y = y;
		santas[santa_num].score = 0;
		santas[santa_num].status = 0;
		map[x][y] = santa_num;
	}

	// �ʱⰪ ���
	if(print_on)
		print_map_and_score();

	for (int i = 0; i < M; i++) {
		if(print_on)
			cout << i + 1 << "\n";
		move();
	}

	for (int i = 1; i <= P; i++)
		cout << santas[i].score << " ";

}