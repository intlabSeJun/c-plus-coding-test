#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int L, N, Q; //(체스판 크기, 기사들 수, 명령 수)
int map1[45][45] = {};  // 함정 1, 벽 2
int map2[45][45] = {};  // 각 기사들 번호
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool print_on = false;

struct sss {
	int x, y, h, w, k, d;
};

sss knights[35];

void print_map() {  // 기사 map 출력
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
	if (knights[target].d >= knights[target].k)  // 이미 죽은 기사 제외
		return false;
	moving_knights.push(target);  // 현재 명령 받은 기사 번호 저장, 추후에 top()부터 이동.
	queue<int> Q;
	Q.push(target);

	int cur_target;
	int check[35] = {};
	while (!Q.empty()) {
		cur_target = Q.front();
		Q.pop();
		
		if (knights[cur_target].k <= knights[cur_target].d) // 아웃된 기사 제외
			continue;

		int next_value, next_target;
		int new_x, new_y;
		if (direction == 0) {  // 상
			new_x = knights[cur_target].x - 1;
			if (new_x < 1)  // 벽에 도달한 경우
				return false;
			for (int new_y = knights[cur_target].y; new_y < knights[cur_target].y + knights[cur_target].w; new_y++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // 벽에 도달한 경우
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else if (direction == 1) {  // 우
			new_y = knights[cur_target].y + knights[cur_target].w;
			if (new_y > L)  // 벽에 도달한 경우
				return false;
			for (int new_x = knights[cur_target].x; new_x < knights[cur_target].x + knights[cur_target].h; new_x++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // 벽에 도달한 경우
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else if (direction == 2) {  // 하
			new_x = knights[cur_target].x + knights[cur_target].h;
			if (new_x > L)  // 벽에 도달한 경우
				return false;

			for (int new_y = knights[cur_target].y; new_y < knights[cur_target].y + knights[cur_target].w; new_y++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // 벽에 도달한 경우
					return false;
				else if (next_target != 0 && check[next_target] == 0) {
					check[next_target] = 1;
					Q.push(next_target);
					moving_knights.push(next_target);
				}
			}
		}
		else {  // 좌
			new_y = knights[cur_target].y - 1;
			if (new_y < 1)  // 벽에 도달한 경우
				return false;

			for (int new_x = knights[cur_target].x; new_x < knights[cur_target].x + knights[cur_target].h; new_x++) {
				next_value = map1[new_x][new_y];
				next_target = map2[new_x][new_y];

				if (next_value == 2)  // 벽에 도달한 경우
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
		if (direction == 0) {  // 상
			int new_x = knights[cur_target].x - 1;
			cur_y = knights[cur_target].y;
			for (int new_y = cur_y; new_y < cur_y + knights[cur_target].w; new_y++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_y == knights[cur_target].y)  // 좌상단 좌표 갱신. x-1, y그대로
					knights[cur_target].x = new_x;

				// erase last array
				map2[new_x + knights[cur_target].h][new_y] = 0;
			}
		}
		else if (direction == 1) {  // 우
			int new_y = knights[cur_target].y + knights[cur_target].w;
			cur_x = knights[cur_target].x;
			for (int new_x = cur_x; new_x < cur_x + knights[cur_target].h; new_x++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_x == knights[cur_target].x)  // 좌상단 좌표 갱신. x그재로, y+1그대로
					knights[cur_target].y = knights[cur_target].y + 1;

				// erase last array
				map2[new_x][new_y - knights[cur_target].w] = 0;
			}
		}
		else if (direction == 2) {  // 하
			int new_x = knights[cur_target].x + knights[cur_target].h;
			cur_y = knights[cur_target].y;
			for (int new_y = cur_y; new_y < cur_y + knights[cur_target].w; new_y++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_y == knights[cur_target].y)  // 좌상단 좌표 갱신. x+1, y그대로
					knights[cur_target].x = knights[cur_target].x + 1;

				// erase last array
				map2[new_x - knights[cur_target].h][new_y] = 0;
			}
		}
		else {  // 좌
			int new_y = knights[cur_target].y - 1;
			cur_x = knights[cur_target].x;
			for (int new_x = cur_x; new_x < cur_x + knights[cur_target].h; new_x++) {
				// update first array
				map2[new_x][new_y] = cur_target;
				if (new_x == knights[cur_target].x)  // 좌상단 좌표 갱신. x그대로, y-1
					knights[cur_target].y = new_y;

				// erase last array
				map2[new_x][new_y + knights[cur_target].w] = 0;
			}
		}

		// 함정 존재 확인 및 데미지 추가
		int value;
		for (int x = knights[cur_target].x; x < knights[cur_target].x + knights[cur_target].h; x++) {
			for (int y = knights[cur_target].y; y < knights[cur_target].y + knights[cur_target].w; y++) {
				value = map1[x][y];
				if (value == 1 && moving_knights.size() != 0) {  // 함정이 존재할 경우, 명령 받은 기사 제외
					knights[cur_target].d++; // 데미지 추가
				}
			}
		}

		// 체력 없다면 수행, map2에서 지우기
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

	// 함정, 벽 
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cin >> map1[i][j];
		}
	}
	
	// 기사 정보 및 기사 map 갱신
	for (int i = 1; i <= N; i++) {
		cin >> knights[i].x >> knights[i].y >> knights[i].h >> knights[i].w >> knights[i].k;
		knights[i].d = 0;
		for (int r = knights[i].x; r < knights[i].x + knights[i].h; r++)
			for (int c = knights[i].y; c < knights[i].y + knights[i].w; c++)
				map2[r][c] = i;
	}

	if (print_on) {
		cout << "기사 정보\n";
		print_map();
	}

	int target, direction;  // 왕의 명령 : i번째 기사에게 방향(0,1,2,3 | 상우하좌).
	for (int i = 1; i <= Q; i++) {
		stack<int> moving_knights;
		cin >> target >> direction;
		if (check(target, direction, moving_knights))  // 기사들 이동 가능 여부 확인 후 stack에 쌓음
			move(direction, moving_knights);  // stack의 기사들 순서대로 해당 방향 이동
	}

	int total_damage = 0;
	for (int i = 1; i <= N; i++) {
		if (knights[i].k <= knights[i].d) // 죽은 기사 제외
			continue;
		total_damage += knights[i].d;
	}

	cout << total_damage;
}