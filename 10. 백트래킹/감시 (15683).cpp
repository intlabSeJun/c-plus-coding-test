#include<iostream>
#include<utility>
using namespace std;

int N, M, cnt=0, total=10000; // cnt : 캠의 개수.
int arr[10][10] = {};
int cam_num[10] = {};  // cam 번호
pair<int, int> cam_coord[10]; // 각각의 x,y 좌표
int cam_1[4][1] = { {1},{2},{3},{4} };
int cam_2[2][2] = { {1,3},{2,4} };
int cam_3[4][2] = { {1,2}, {2,3},{3,4},{4,1} };
int cam_4[4][3] = { {1,2,3},{2,3,4},{3,4,1},{4,1,2} };
int cam_5[1][4] = { { 1,2,3,4 } };

void print_arr() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void drawing(int num, int x, int y, int k) {
	if (num == 1) {
		for (int i = y-1; i >= 0; i--) {
			if (arr[x][i] == 6) 
				return;
			else if(arr[x][i] == 0)
				arr[x][i] = -k - 2;
		}
	}
	else if (num == 2) {
		for (int i = x-1; i >= 0; i--) {
			if (arr[i][y] == 6) 
				return;
			else if (arr[i][y] == 0)
				arr[i][y] = -k - 2;
		}
	}
	else if (num == 3) {
		for (int i = y+1; i < M; i++) {
			if (arr[x][i] == 6) return;
			else if (arr[x][i] == 0)
				arr[x][i] = -k - 2;
		}
	}
	else if (num == 4) {
		for (int i = x+1; i < N; i++) {
			if (arr[i][y] == 6) return;
			else if (arr[i][y] == 0)
				arr[i][y] = -k - 2;
		}
	}
}

void erasing(int num, int x, int y, int k) {
	if (num == 1) {
		for (int i = y; i >= 0; i--) {
			if (arr[x][i] == 6) return;
			if (arr[x][i] == -k - 2)
				arr[x][i] = 0;
		}
	}
	else if (num == 2) {
		for (int i = x - 1; i >= 0; i--) {
			if (arr[i][y] == 6) return;
			if (arr[i][y] == -k - 2)
				arr[i][y] = 0;
		}
	}
	else if (num == 3) {
		for (int i = y + 1; i < M; i++) {
			if (arr[x][i] == 6) return;
			if (arr[x][i] == -k -2)
				arr[x][i] = 0;
		}
	}
	else if (num == 4) {
		for (int i = x + 1; i < N; i++) {
			if (arr[i][y] == 6) return;
			if (arr[i][y] == -k-2) 
				arr[i][y] = 0;
		}
	}
}

void func(int k) {  // 0번째 cam부터 시작
	if (k == cnt) {
		int cur_total = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (arr[i][j] == 0) cur_total++;
		if (cur_total < total) total = cur_total;
		//cout << cur_total << "\n";
		return;
	}

	pair<int, int> buf_cam_coord;
	int single_cam_value;
	buf_cam_coord = cam_coord[k];
	if (cam_num[k] == 1) { // cam번호가 1일경우 수행
		for (int i = 0; i < 4; i++) {  // 4가지 경우의 수 존재
			single_cam_value = cam_1[i][0];
			drawing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			//print_arr();
			func(k + 1);
			erasing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			//print_arr();
		}
	}
	else if (cam_num[k] == 2) {// cam번호가 2일경우 수행
		for (int i = 0; i < 2; i++) { // 2가지 경우의 수 존재
			for (int j = 0; j < 2; j++) {// 2가지 방향 각각 수행
				single_cam_value = cam_2[i][j];
				drawing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
			func(k + 1);
			for (int j = 0; j < 2; j++) {// 2가지 방향 각각 수행
				single_cam_value = cam_2[i][j];
				erasing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
		}
	}
	else if (cam_num[k] == 3) {// cam번호가 3일경우 수행
		for (int i = 0; i < 4; i++) { // 4가지 경우의 수 존재
			for (int j = 0; j < 2; j++) {// 2가지 방향 각각 수행
				single_cam_value = cam_3[i][j];
				drawing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
			func(k + 1);
			for (int j = 0; j < 2; j++) {// 2가지 방향 각각 수행
				single_cam_value = cam_3[i][j];
				erasing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
		}
	}
	else if (cam_num[k] == 4) { // cam번호가 4일경우 수행
		for (int i = 0; i < 4; i++) { // 4가지 경우의 수 존재
			for (int j = 0; j < 3; j++) {// 3가지 방향 각각 수행
				single_cam_value = cam_4[i][j];
				drawing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
			func(k + 1);
			for (int j = 0; j < 3; j++) {// 3가지 방향 각각 수행
				single_cam_value = cam_4[i][j];
				erasing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
		}
	}
	else if (cam_num[k] == 5) {
		for (int i = 0; i < 1; i++) { // 1가지 경우의 수 존재
			for (int j = 0; j < 4; j++) {// 4가지 방향 각각 수행
				single_cam_value = cam_5[i][j];
				drawing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
			func(k + 1);
			for (int j = 0; j < 4; j++) {// 4가지 방향 각각 수행
				single_cam_value = cam_5[i][j];
				erasing(single_cam_value, buf_cam_coord.first, buf_cam_coord.second, k);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int buf;
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++) {
			cin >> buf;
			arr[i][j] = buf;
			if (buf != 0 && buf != 6) {
				cam_num[cnt] = buf; // cam 번호 저장
				cam_coord[cnt] = { i,j }; // 해당 cam (x,y) 저장
				cnt++; // cam 개수 저장.
			}
		}

	func(0);
	cout << total;
}