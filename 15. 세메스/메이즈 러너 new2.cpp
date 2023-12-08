/*
1. 사람 이동
 1) 상하좌우 순서
  - 행 비교 : 사람 x < 출구 x &
  - 열 비교 : 
2. map 이동

*/

#include<iostream>
#include<utility>
using namespace std;

int N, M, K;  // (맵크기, 참가자 수, K초)
int map[15][15] = {}; // 미로 벽 정보 = 1~9, exit = -1
int exit_x, exit_y;  // 출구 좌표

int print_on = false;  // 검사를 위한 print 

// 사람 정보 구조체로 저장
struct person {
	int x, y;  // 현재 좌표
	int dist;  // 이동한 거리
	bool exit;  // 탈출 여부 
};

person P[15];  // 사람들 구조체 선언

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

void is_finish(int i) {  // 참가자 탈출했으면 갱신.
	if (P[i].x == exit_x && P[i].y == exit_y)
		P[i].exit = true;
}

void move_person() {
	// 참가자 1~M까지 각각 출구와 가까워지는 방향으로 1칸 이동
	// 현재 위치보다 가까워야 하며, 벽으로는 이동 불가
	// 이동 우선순위는 상하좌우
	for (int i = 1; i <= M; i++) {
		if (P[i].exit)  // 참가자 탈출시 
			continue;

		// 참가자 x,y 좌표 참조
		int& x = P[i].x;
		int& y = P[i].y;

		// 우선순위를 기반으로 하나씩 판별하여 참가자 이동한다.
		// 출구가 참가자보다 위쪽(row 기준)에 있을 시
		if (x > exit_x && map[x - 1][y] <= 0) {  // 위로 이동
			x--;
			P[i].dist++;
			is_finish(i);
		}
		// 출구가 참가자보다 아래쪽(row 기준)에 있을 시
		else if (x < exit_x && map[x + 1][y] <= 0) {  // 아래로 이동
			x++;
			P[i].dist++;
			is_finish(i);
		}
		// 출구가 참가자보다 오른쪽(column 기준)에 있을시
		else if (y < exit_y && map[x][y + 1] <= 0) {  // 우로 이동
			y++;
			P[i].dist++;
			is_finish(i);
		}
		// 출구가 참가자보다 왼쪽(column 기준)에 있을시
		else if (y > exit_y && map[x][y - 1] <= 0)  // 좌로 이동 
		{
			y--;
			P[i].dist++;
			is_finish(i);
		}
	}
}

void get_coord(int& r, int& c, int& a, int& b) {
	// 박스의 크기를 늘려가면서, 박스 내에 출구와 사람이 있는지 조사.
	for (int d = 2; d <= N; d++) {
		for (int rx = 1; rx <= N - d + 1; rx++) {
			for (int cy = 1; cy <= N - d + 1; cy++) {
				int ax = rx + d - 1;
				int by = cy + d - 1;

				if (exit_x < rx || exit_x > ax || exit_y < cy || exit_y > by)  // 출구가 박스 내에 없을 경우 
					continue;

				bool is_person = false;
				for (int i = 1; i <= M; i++) {
					if (P[i].x < rx || P[i].x > ax || P[i].y < cy || P[i].y > by || P[i].exit)  // 사람이 박스 내에 없을 경우 
						continue;
					is_person = true;
				}

				if (is_person) {  //박스내 사람 존재시.
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
	int r, c, a, b;  // 좌상단, 우하단 좌표

	get_coord(r, c, a, b);  // get 좌상단, 우하단

	if (print_on) {
		cout << "r c a b :" << r << " " << c << " " << a << " " << b << "\n";
	}

	int map_buf[15][15] = {};  // 회전할 배열을 임시 저장할 공간.

	// rotate map block and exit
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			if (map[i][j] == -1) {  // 출구 일 경우
				exit_x = r + j - c; // x좌표 90도 회전 공식
				exit_y = b - (i - r);  // y좌표 90도 회전 공식
				map_buf[r + j - c][b - (i - r)] = map[i][j];  // 임시 저장
			}
			if(map[i][j] > 0)
				map_buf[r + j - c][b - (i - r)] = map[i][j] - 1;  // block 갱신
		}
	}

	// rotate again, 원본 map에 다시 저장.
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			map[i][j] = map_buf[i][j];
		}
	}

	// person rotate
	int is_rotate_person[15] = {};  // 회전한 좌표는 제외
	for (int i = r; i <= a; i++) {
		for (int j = c; j <= b; j++) {
			for (int k = 1; k <= M; k++) {  // 모든 사람들의 좌표에서 box 범위 내 존재시 이동.
				if (P[k].exit || is_rotate_person[k] == 1)
					continue;
				if (P[k].x == i && P[k].y == j) {  // 사람은 이동
					P[k].x = r + j - c;  // x좌표 90도 이동 공식
					P[k].y = b - (i - r);  // y좌표 90도 이동 공식
					is_rotate_person[k] = 1;  // 회전 여부 체크
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

	cin >> N >> M >> K;  // 맵크기, 참가자 수, 반복 수 

	//맵 정보 받기, 벽(1~9) or 빈공간(0)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	//참가자 초기 좌표 받기, 중복x, 초기화(dist, exit)
	for (int i = 1; i <= M; i++) {
		cin >> P[i].x >> P[i].y;
		P[i].dist = 0;
		P[i].exit = false;
	}

	cin >> exit_x >> exit_y;  // 출구 좌표 받기
	map[exit_x][exit_y] = -1;  // 출구는 -1로 map에 표시

	if (print_on) {
		cout << "init\n";
		print_map();
	}

	for (int i = 1; i <= K; i++) {
		move_person();  // 사람 이동
		if (print_on) {
			cout << "moved person\n";
			print_map();
		}

		if (check())  // 모든 사람이 exit 했는지 확인
			break;

		rotation();  // 맵 회전
		if (print_on) {
			cout << "rotation\n";
			print_map();
		}
	}	

	int ans = 0;
	for (int i = 1; i <= M; i++) {  // 모든 참가자 이동한 거리 합산
		ans += P[i].dist;
	}

	// 결과 출력
	cout << ans << "\n";
	cout << exit_x << " " << exit_y;

}
