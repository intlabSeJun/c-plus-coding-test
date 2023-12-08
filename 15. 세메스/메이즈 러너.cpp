/*
참가자 구조체 저장
- 좌표, 이동횟수, 탈출 여부

벽에 대한 정보 map에 저장

exit 좌표를 변수에 저장

1. 참가자 이동
 - 최소 거리와 우선순위 따져서 이동
 - 이동 후에 exit와의 거리를 구함
 - 구한 거리중에 가장 짧은 거리에 대한 참가자 번호 저장
 - 탈출 시, 참가자 exit 정보 갱신
 - 탈출한 참가자는 제외

2. 회전
 - 앞에서 구한 참가자 번호를 포함하는 가장 작은 정사각형 범위 구함
 - 8방향으로 나타낼 수 있음.
   - 각 방향마다의 다른 범위를 구하도록 조건문
   - 좌상단(x,y)과 너비(w), 높이(h)를 구함. 
 - 좌상단부터 시계방향(원형)으로 반복문
   - 현재값은 저장하고, 이전값을 현재 좌표에 할당하는 방식(swap)
 - 회전한 block들 값 -1

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, M, K; //(맵크기, 참가자 수, K초)
int map_block[15][15] = {};  // block 정보
int exit_x, exit_y;  // 출구 좌표 
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int print_on = true;

struct person {
	int x, y, dist;  // (좌표), 이동한 거리
	bool exit;  // 탈출 여부
};

person P[12];  // 사람 정보, 1~M까지.

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
	return abs(x1-x2) + abs(y1-y2);
}

int move() {
	/*
1. 참가자 이동
 - 최소 거리와 우선순위 따져서 이동
 - 이동 후에 exit와의 거리를 구함
 - 구한 거리중에 가장 짧은 거리에 대한 참가자 번호 저장
 - 탈출 시, 참가자 exit 정보 갱신
 - 탈출한 참가자는 제외
	*/

	int cur_dist, new_dist, short_person_dist=999999, short_person = -1;
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
		if (flag == 0)  // 이동 없을시.
			continue;

		P[i].dist++;
		if (short_dist < short_person_dist) {
			short_person_dist = short_dist;
			short_person = i;
			P[i].x = short_x;
			P[i].y = short_y;
		}
		else if (short_dist == short_person_dist) {  // 짧은 거리 여러 개
			if (P[i].x < P[short_person].x) {
				short_person_dist = short_dist;
				short_person = i;
				P[i].x = short_x;
				P[i].y = short_y;
			}
			else if (P[i].x == P[short_person].x) {
				if (P[i].y < P[short_person].y) {
					short_person_dist = short_dist;
					short_person = i;
					P[i].x = short_x;
					P[i].y = short_y;
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
		else if (cur_dist == short_dist) {  // 짧은 거리 여러 개
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

bool check_box(int a, int b) {  // 좌상단 or 우하단 좌표 받아서 가능여부 판단
	if (a < 1 || a > N || b < 1 || b > N)
		return false;
	return true;
}

void block_break(int x, int y) {
	if(map_block[x][y] != 0)
		map_block[x][y]--;
}

void person_move(queue<int>& person_idx, int &r, int &c, int &a, int &b, int &w) {
	int p_size = person_idx.size();
	int p_idx;

	for (int i = 0; i < p_size; i++) {
		p_idx = person_idx.front();
		person_idx.pop();

		if (P[p_idx].x == r) {//좌상단에서 오른쪽 가로 방향 갱신
			P[p_idx].x = P[p_idx].x + P[p_idx].y - c;
			P[p_idx].y = b;
		}
		else if (P[p_idx].y == b) { // 우상단에서 아래쪽 세로 방향 갱신
			P[p_idx].x = a;
			P[p_idx].y = b - P[p_idx].x + 2;
		}
		else if (P[p_idx].x == a) { //우하단에서 왼쪽 가로 방향 갱신
			P[p_idx].x = P[p_idx].y + 1;
			P[p_idx].y = c;
		}
		else if (P[p_idx].y == c) { //좌하단에서 위쪽 세로 방향 갱신
			P[p_idx].x = r;
			P[p_idx].y = b - P[p_idx].x + 2;
		}
		else person_idx.push(p_idx); // 해당 라인에 없는 사람은 다시 채움.
	}
}

void rotation(int short_person) {
	/*
	2. 회전
	 - 앞에서 구한 참가자 번호를 포함하는 가장 작은 정사각형 범위 구함
	 - 8방향으로 나타낼 수 있음.
	   - 각 방향마다의 다른 범위를 구하도록 조건문
	   - 좌상단(r,c)과 너비(w)를 구함. 
	 - 좌상단부터 시계방향(원형)으로 반복문
	   - 현재값은 저장하고, 이전값을 현재 좌표에 할당하는 방식(swap)
	 - 회전한 block들 값 -1

	 범위 좌상단(r,c), 우하단(a,b)을 구한다면,
	 범위 내에 있는 참가자들을 추출한다. 
	 그리고 w범위마다 돌릴때, 각 범위에 대한 참가자들의 좌표와 동일한지 확인? 
	 동일하다면, 이동해야 하고 제외시켜야 함. 
	*/
	if (short_person == -1) // 아무도 이동을 안했을 시, 가장 짧은 사람 구함.
		short_person = get_short_person();
	if (short_person == -1)  // 모든 참가자 탈출시 종료.
		return;

	int x, y, w;
	int r, c; // 좌상단
	int a, b; // 우하단
	x = P[short_person].x;
	y = P[short_person].y;

	// 출구를 기준으로, (r,c), (a,b) 구함. 8방향 조건문. +exit 좌표 갱신.
	if (x == exit_x && y < exit_y) {  // 좌측
		w = exit_y - y;
		if (check_box(x - w, y)) { // 위로 그리기
			r = x - w;
			c = y;
			a = exit_x;
			b = exit_y;

			exit_y = c;

		}
		else {  // 아래로 그리기
			r = x;
			c = y;
			a = exit_x + w;
			b = exit_y;

			exit_x = a;

		}
	}
	else if (x == exit_x && y > exit_y) { // 우측
		w = y - exit_y;
		if (check_box(exit_x - w, exit_y)) { // 위로 그리기
			r = exit_x - w;
			c = exit_y;
			a = exit_x;
			b = exit_y + w;

			exit_x = r;

		}
		else {  // 아래로 그리기
			r = exit_x;
			c = exit_y;
			a = exit_x + w;
			b = exit_y + w;

			exit_y = b;

		}
	}
	else if (x < exit_x && y == exit_y) { // 상단
		w = exit_x - x;
		if (check_box(x, y-w)) { // 좌측으로 그리기
			r = x;
			c = y - w;
			a = exit_x;
			b = exit_y;

			exit_y = c;

		}
		else {  // 우측으로 그리기
			r = x;
			c = y;
			a = exit_x;
			b = exit_y + w;

			exit_x = r;

		}
	}
	else if (x > exit_x && y == exit_y) { // 하단
		w = x - exit_x;
		if (check_box(exit_x, exit_y - w)) { // 좌측으로 그리기
			r = exit_x;
			c = exit_y - w;
			a = exit_x + w;
			b = exit_y;

			exit_x = a;

		}
		else {  // 우측으로 그리기 
			r = exit_x;
			c = exit_y;
			a = exit_x + w;
			b = exit_y + w;

			exit_y = b;

		}
	}
	else if (x < exit_x && y < exit_y) { // 좌상단
		if (exit_x - x > exit_y - y)
			w = exit_x - x;
		else
			w = exit_y - y;

		r = exit_x - w;
		c = exit_y - w;
		a = exit_x;
		b = exit_y;

		exit_y = c;

	}
	else if (x > exit_x && y < exit_y) { // 좌하단
		if (x - exit_x > exit_y - y)
			w = x - exit_x;
		else
			w = exit_y - y;

		r = exit_x;
		c = exit_y - w;
		a = exit_x + w;
		b = exit_y;

		exit_x = a;

	}
	else if (x < exit_x && y > exit_y) { // 우상단
		if (exit_x - x >  y - exit_y)
			w = exit_x - x;
		else
			w = y - exit_y;

		r = exit_x - w;
		c = exit_y;
		a = exit_x;
		b = exit_y + w;

		exit_x = r;
	}
	else if (x > exit_x && y > exit_y) { // 우하단
		if ( x - exit_x > y - exit_y)
			w = x - exit_x;
		else
			w = y - exit_y;

		r = exit_x;
		c = exit_y;
		a = exit_x + w;
		b = exit_y + w;

		exit_y = b;
	}

	// 정사각형 중앙값 갱신, 홀수일 경우만 수행
	if((w+1)%2 != 0)
		block_break(a-r, b-c);

	queue<int> person_idx;

	for (int i = 1; i <= M; i++) {  //범위 내에 있는 참가자 쌓는다.
		if (P[i].exit) 
			continue;
		if (P[i].x >= r && P[i].x <= a && P[i].y >= c && P[i].y <= b)
			person_idx.push(i);  
	}

	//좌상단부터 시계방향(원형)으로 반복문
	while (w >= 1) {
		person_move(person_idx, r, c, a, b, w);

		int buf[4];
		for (int i = 0; i < w; i++) {
			//좌상단에서 오른쪽 가로 방향 갱신
			buf[0] = map_block[r][c + i];
			map_block[r][c + i] = map_block[a - i][c];

			// 우상단에서 아래쪽 세로 방향 갱신
			buf[1] = map_block[r + i][c + w];
			map_block[r + i][c + w] = buf[0];

			//우하단에서 왼쪽 가로 방향 갱신
			buf[2] = map_block[a][b - i];
			map_block[a][b - i] = buf[1];

			//좌하단에서 위쪽 세로 방향 갱신
			buf[3] = map_block[a - i][c];
			map_block[a - i][c] = buf[2];

			// block 감소
			block_break(r, c + i);
			block_break(r + i, c + w);
			block_break(a, b - i);
			block_break(a - i, c);
		}
		// 내부 정사각형으로 범위 수정
		r += 1;
		c += 1;
		a -= 1;
		b -= 1;

		w -= 2;
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

	if (print_on) {
		cout << "초기상태\n";
		print_map();
	}

	int short_p;
	for (int i = 0; i < K; i++) {  // K초 수행 
		short_p = move();  // 참가자 이동

		if (print_on) {
			cout << "사람 이동, short_p = " << short_p << "\n";
			print_map();
		}

		rotation(short_p);  // map 회전
		if (print_on) {
			cout << "map 회전\n";
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
