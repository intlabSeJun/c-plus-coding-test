#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int L, N, Q; //(ü���� ũ��, ���� ��, ��� ��)
int map1[45][45] = {};  // ���� 1, �� 2
int map2[45][45] = {};  // �� ���� ��ȣ
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool print_on = false;

struct sss {
	int x, y, h, w, k, d;
};

sss knights[35];

void print_map() {  // ��� map ���
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++)
			cout << map2[i][j] << " ";
		cout << "\n";
	}
	for (int i = 1; i <= N; i++)
		cout <<"damage: " << knights[i].d << " ";
	cout << "\n";
}

bool check(int &target, int &direction, stack<int>& moving_knights) {
	if (knights[target].d >= knights[target].k)  // �̹� ���� ��� ����
		return false;
	moving_knights.push(target);  // ���� ��� ���� ��� ��ȣ ����, ���Ŀ� top()���� �̵�.
	queue<int> Q;
	Q.push(target);

	int cur_target;
	int check[35] = {};
	while (!Q.empty()) {
		cur_target = Q.front();
		Q.pop();
		
		if (knights[cur_target].k <= knights[cur_target].d) // �ƿ��� ��� ����
			continue;

		int next_value, next_target;
		int new_x, new_y;
		if (direction == 0) {  // ��
			new_x = knights[cur_target].x - 1;
			if (new_x < 1)  // ���� ������ ���
				return false;
			for (int new_y = knights[cur_target].y; new_y < knights[cur_target].y + knights[cur_target].w; new_y++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // ���� ������ ���
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else if (direction == 1) {  // ��
			new_y = knights[cur_target].y + knights[cur_target].w;
			if (new_y > L)  // ���� ������ ���
				return false;
			for (int new_x = knights[cur_target].x; new_x < knights[cur_target].x + knights[cur_target].h; new_x++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // ���� ������ ���
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else if (direction == 2) {  // ��
			new_x = knights[cur_target].x + knights[cur_target].h;
			if (new_x > L)  // ���� ������ ���
				return false;

			for (int new_y = knights[cur_target].y; new_y < knights[cur_target].y + knights[cur_target].w; new_y++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // ���� ������ ���
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else {  // ��
			new_y = knights[cur_target].y - 1;
			if (new_y < 1)  // ���� ������ ���
				return false;

			for (int new_x = knights[cur_target].x; new_x < knights[cur_target].x + knights[cur_target].h; new_x++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // ���� ������ ���
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
	}

	return true;
}

void erase(int &cur_target) {
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++)
			if (map2[i][j] == cur_target)
				map2[i][j] = 0;
	}
}

void move(int &direction, stack<int>& moving_knights) {
	if (print_on) {
		cout << "before move\n";
		print_map();
		cout << "\ncur target : ";
	}
	int cur_target, next_target;
	int cur_x, cur_y;
	while (!moving_knights.empty()) {
		cur_target = moving_knights.top();
		moving_knights.pop();
		if (print_on) {
			cout <<  cur_target << " ";
		}
		if (direction == 0) {  // ��
			int new_x = knights[cur_target].x - 1;
			cur_y = knights[cur_target].y;
			for (int new_y = cur_y; new_y < cur_y + knights[cur_target].w; new_y++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_y == knights[cur_target].y)  // �»�� ��ǥ ����. x-1, y�״��
					knights[cur_target].x = new_x;

				// erase last array
				map2[new_x + knights[cur_target].h][new_y] = 0;
			}
		}
		else if (direction == 1) {  // ��
			int new_y = knights[cur_target].y + knights[cur_target].w;
			cur_x = knights[cur_target].x;
			for (int new_x = cur_x; new_x < cur_x + knights[cur_target].h; new_x++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_x == knights[cur_target].x)  // �»�� ��ǥ ����. x�����, y+1�״��
					knights[cur_target].y = knights[cur_target].y + 1;

				// erase last array
				map2[new_x][new_y - knights[cur_target].w] = 0;
			}
		}
		else if (direction == 2) {  // ��
			int new_x = knights[cur_target].x + knights[cur_target].h;
			cur_y = knights[cur_target].y;
			for (int new_y = cur_y; new_y < cur_y + knights[cur_target].w; new_y++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_y == knights[cur_target].y)  // �»�� ��ǥ ����. x+1, y�״��
					knights[cur_target].x = knights[cur_target].x + 1;

				// erase last array
				map2[new_x - knights[cur_target].h][new_y] = 0;
			}
		}
		else {  // ��
			int new_y = knights[cur_target].y - 1;
			cur_x = knights[cur_target].x;
			for (int new_x = cur_x; new_x < cur_x + knights[cur_target].h; new_x++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_x == knights[cur_target].x)  // �»�� ��ǥ ����. x�״��, y-1
					knights[cur_target].y = new_y;

				// erase last array
				map2[new_x][new_y + knights[cur_target].w] = 0;
			}
		}

		// ���� ���� Ȯ�� �� ������ �߰�
		int value;
		for (int x = knights[cur_target].x; x < knights[cur_target].x + knights[cur_target].h; x++) {
			for (int y = knights[cur_target].y; y < knights[cur_target].y + knights[cur_target].w; y++) {
				value = map1[x][y];
				if (value == 1 && moving_knights.size() != 0) {  // ������ ������ ���, ��� ���� ��� ����
					knights[cur_target].d++; // ������ �߰�
				}
			}
		}

		// ü�� ���ٸ� ����, map2���� �����
		if (knights[cur_target].d >= knights[cur_target].k) 
			erase(cur_target);  

	}

	if (print_on) {
		cout << "\nend move\n";
		print_map();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> N >> Q;

	// ����, �� 
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cin >> map1[i][j];
		}
	}
	
	// ��� ���� �� ��� map ����
	for (int i = 1; i <= N; i++) {
		cin >> knights[i].x >> knights[i].y >> knights[i].h >> knights[i].w >> knights[i].k;
		knights[i].d = 0;
		for (int r = knights[i].x; r < knights[i].x + knights[i].h; r++)
			for (int c = knights[i].y; c < knights[i].y + knights[i].w; c++)
				map2[r][c] = i;
	}

	if (print_on) {
		cout << "��� ����\n";
		print_map();
	}

	int target, direction;  // ���� ��� : i��° ��翡�� ����(0,1,2,3 | �������).
	for (int i = 1; i <= Q; i++) {
		stack<int> moving_knights;
		cin >> target >> direction;
		if (check(target, direction, moving_knights))  // ���� �̵� ���� ���� Ȯ�� �� stack�� ����
			move(direction, moving_knights);  // stack�� ���� ������� �ش� ���� �̵�
	}

	int total_damage = 0;
	for (int i = 1; i <= N; i++) {
		if (knights[i].k <= knights[i].d) // ���� ��� ����
			continue;
		total_damage += knights[i].d;
	}

	cout << total_damage;
}