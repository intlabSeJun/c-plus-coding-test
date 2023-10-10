#include<iostream>
#include<string>
using namespace std;

int N, M;
char map[15][15][15]; // 각 층마다 map 생성.
int short_cut = 100;
pair<int, int> RBO[15][3]; //각 층마다 R,B,O 위치 저장
int goal = 0;
char goal_target;

void print_arr(int k) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[k][i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void _moving_left(int k, int x, int y, char input_c, char block_c, char block_d) {
	int rb;
	if (input_c == 'R') rb = 0;
	else rb = 1;

	for (int i = y - 1; i >= 0; i--) {
		if (map[k][x][i] == block_c || (input_c != block_d && map[k][x][i] == block_d)) {
			if (i == y - 1)
				break;
			map[k][x][i + 1] = input_c;
			map[k][x][y] = '.';
			RBO[k][rb] = { x, i + 1 };
			break;
		}
		else if (map[k][x][i] == 'O') {
			map[k][x][y] = '.';
			if (goal == 1) goal = 2;
			else goal = 1;
			goal_target = input_c;
			return;
		}
			
	}
}

void _moving_upper(int k, int x, int y, char input_c, char block_c, char block_d) {
	int rb;
	if (input_c == 'R') rb = 0;
	else rb = 1;

	for (int i = x - 1; i >= 0; i--) {
		if (map[k][i][y] == block_c || (input_c != block_d && map[k][i][y] == block_d)) {
			if (i == x - 1)
				break;
			map[k][i+1][y] = input_c;
			map[k][x][y] = '.';
			RBO[k][rb] = { i+1, y };
			break;
		}
		else if (map[k][i][y] == 'O') {
			map[k][x][y] = '.';
			if (goal == 1) goal = 2;
			else goal = 1;
			goal_target = input_c;
			return;
		}
	}
}

void _moving_right(int k, int x, int y, char input_c, char block_c, char block_d) {
	int rb;
	if (input_c == 'R') rb = 0;
	else rb = 1;

	for (int i = y + 1; i < M; i++) {
		if (map[k][x][i] == block_c || (input_c != block_d && map[k][x][i] == block_d)) {
			if (i == y + 1)
				break;
			map[k][x][i - 1] = input_c;
			map[k][x][y] = '.';
			RBO[k][rb] = { x, i - 1 };
			break;
		}
		else if (map[k][x][i] == 'O') {
			map[k][x][y] = '.';
			if (goal == 1) goal = 2;
			else goal = 1;
			goal_target = input_c;
			return;
		}
	}
}

void _moving_bottom(int k, int x, int y, char input_c, char block_c, char block_d) {
	int rb;
	if (input_c == 'R') rb = 0;
	else rb = 1;

	for (int i = x + 1; i < N; i++) {
		if (map[k][i][y] == block_c || (input_c != block_d && map[k][i][y] == block_d)) {
			if (i == x + 1)
				break;
			map[k][i - 1][y] = input_c;
			map[k][x][y] = '.';
			RBO[k][rb] = { i - 1, y };
			break;
		}
		else if (map[k][i][y] == 'O') {
			map[k][x][y] = '.';
			if (goal == 1) goal = 2;
			else goal = 1;
			goal_target = input_c;
			return;
		}
	}
}

void moving(int k, int dir) {
	pair<int, int> R_point, B_point, O_point;
	R_point = RBO[k][0];
	B_point = RBO[k][1];
	O_point = RBO[k][2];

	if (dir == 1) { // left
		if (R_point.first == B_point.first) {
			if (R_point.second < B_point.second) {
				_moving_left(k, R_point.first, R_point.second, 'R', '#', 'R');
				_moving_left(k, B_point.first, B_point.second, 'B', '#', 'R');
			}
			else {
				_moving_left(k, B_point.first, B_point.second, 'B', '#', 'B');
				_moving_left(k, R_point.first, R_point.second, 'R', '#', 'B');
			}
		}
		else {
			_moving_left(k, R_point.first, R_point.second, 'R', '#', 'R');
			_moving_left(k, B_point.first, B_point.second, 'B', '#', 'B');
		}
	}
	else if (dir == 2) {  // upper
		if (R_point.second == B_point.second) {
			if (R_point.first < B_point.first) {
				_moving_upper(k, R_point.first, R_point.second, 'R', '#', 'R');
				_moving_upper(k, B_point.first, B_point.second, 'B', '#', 'R');
			}
			else {
				_moving_upper(k, B_point.first, B_point.second, 'B', '#', 'B');
				_moving_upper(k, R_point.first, R_point.second, 'R', '#', 'B');
			}
		}
		else {
			_moving_upper(k, R_point.first, R_point.second, 'R', '#', 'R');
			_moving_upper(k, B_point.first, B_point.second, 'B', '#', 'B');
		}
	}
	else if (dir == 3) { // right
		if (R_point.first == B_point.first) {
			if ( B_point.second < R_point.second) {
				_moving_right(k, R_point.first, R_point.second, 'R', '#', 'R');
				_moving_right(k, B_point.first, B_point.second, 'B', '#', 'R');
			}
			else {
				_moving_right(k, B_point.first, B_point.second, 'B', '#', 'B');
				_moving_right(k, R_point.first, R_point.second, 'R', '#', 'B');
			}
		}
		else {
			_moving_right(k, R_point.first, R_point.second, 'R', '#', 'R');
			_moving_right(k, B_point.first, B_point.second, 'B', '#', 'B');
		}
	}
	else if (dir == 4) { // down
		if (R_point.second == B_point.second) {
			if (R_point.first > B_point.first) {
				_moving_bottom(k, R_point.first, R_point.second, 'R', '#', 'R');
				_moving_bottom(k, B_point.first, B_point.second, 'B', '#', 'R');
			}
			else {
				_moving_bottom(k, B_point.first, B_point.second, 'B', '#', 'B');
				_moving_bottom(k, R_point.first, R_point.second, 'R', '#', 'B');
			}
		}
		else {
			_moving_bottom(k, R_point.first, R_point.second, 'R', '#', 'R');
			_moving_bottom(k, B_point.first, B_point.second, 'B', '#', 'B');
		}
	}
}

void set_layer(int k) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[k][i][j] = map[k-1][i][j];

	for (int i = 0; i < 3; i++) 
		RBO[k][i] = RBO[k - 1][i];
}

void func(int k, int except) {
	if (k == 10) {
		return;
	}

	int result;
	for (int i = 0; i < 4; i++) {
		if (except == i) continue;
		set_layer(k+1);
		//cout << i << "\n";
		//cout << "before and after\n";
		//print_arr(k + 1);
		moving(k+1, i+1);
		//print_arr(k+1);

		if (goal == 2) {
			goal = 0;
			continue;
		}
		else if (goal == 1) {
			if (short_cut >= k+1 && goal_target == 'R') short_cut = k + 1;
			goal = 0;
			continue;
		}
		func(k + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[0][i][j] = s[j];
			if (s[j] == 'R') RBO[0][0] = { i,j };
			else if (s[j] == 'B') RBO[0][1] = { i,j };
			else if (s[j] == 'O') RBO[0][2] = { i,j };
		}
	}

	func(0, -1);
	if (short_cut == 100) cout << -1;
	else cout << short_cut;
}