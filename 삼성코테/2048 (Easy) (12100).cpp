#include<iostream>
using namespace std;

int N;
int arr[10][25][25] = {};
int total_max = 0;

void print_arr(int k) {
	cout << k << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[k][i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void moving_blocks(int k, int dir) {
	if (dir == 1) { // left side
		//cout << "left\n";
		for (int i = 0; i < N; i++) {
			int cnt = 0; // moving point
			for (int j = 0; j < N; j++) { // moving reft side, K -> K+1
				if (arr[k][i][j] != 0) arr[k + 1][i][cnt++] = arr[k][i][j];
			}
			//print_arr(k + 1);
			cnt = 0;
			for (int j = 0; j < N; j++) { // sum, in K+1 layer
				if (arr[k+1][i][j] != 0) { // 값 존재시 수행
					if (j + 1 != N) { // 마지막항 제외하고 수행
						if (arr[k+1][i][j] == arr[k+1][i][j + 1]) { // 현재값과 다음항 값이 같을 때 수행
							arr[k + 1][i][cnt++] = arr[k+1][i][j] * 2;
							arr[k + 1][i][j + 1] = 0; //다음항 값 제거
							if (cnt - 1 != j) arr[k + 1][i][j] = 0; // 현재 값 제거, 단,저장했던 곳 제외
							j++; // 다음항 제거했으므로 볼 필요 없음
						}
						else { // 현재 값과 다음 값 다를 때 수행
							arr[k + 1][i][cnt++] = arr[k + 1][i][j]; // moving point에 저장
							if(cnt-1 != j) // 저장했던 곳 아니면, 이전의 값 제거
								arr[k + 1][i][j] = 0;
						}
					}
					else { // 마지막 항일 때 수행
						arr[k + 1][i][cnt++] = arr[k + 1][i][j];
						if (cnt - 1 != j)
							arr[k + 1][i][j] = 0;
					}
				}
			}
		}
	}
	else if (dir == 2) { // Upper side
		//cout << "upper\n";
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[k][j][i] != 0) arr[k + 1][cnt++][i] = arr[k][j][i];
			}
			cnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[k+1][j][i] != 0) {
					if (j + 1 != N) {
						if (arr[k+1][j][i] == arr[k+1][j + 1][i]) {
							arr[k + 1][cnt++][i] = arr[k+1][j][i] * 2;
							arr[k + 1][j+1][i] = 0;
							if (cnt - 1 != j) arr[k + 1][j][i] = 0;
							j++;
						}
						else {
							arr[k + 1][cnt++][i] = arr[k+1][j][i];
							if (cnt - 1 != j)
								arr[k + 1][j][i] = 0;
						}
					}
					else {
						arr[k + 1][cnt++][i] = arr[k + 1][j][i];
						if (cnt - 1 != j)
							arr[k + 1][j][i] = 0;
					}
				}
			}
		}
	}
	else if (dir == 3) { // Right Side
		//cout << "Right\n";
		for (int i = 0; i < N; i++) {
			int cnt = N-1;
			for (int j = N-1; j >=0 ; j--) {
				if (arr[k][i][j] != 0) arr[k + 1][i][cnt--] = arr[k][i][j];
			}
			cnt = N - 1;
			for (int j = N-1; j >= 0; j--) {
				if (arr[k+1][i][j] != 0) {
					if (j != 0) {
						if (arr[k+1][i][j] == arr[k+1][i][j - 1]) {
							arr[k + 1][i][cnt--] = arr[k+1][i][j] * 2;
							arr[k + 1][i][j - 1] = 0;
							if (cnt + 1 != j) arr[k + 1][i][j] = 0;
							j--;
						}
						else {
							arr[k + 1][i][cnt--] = arr[k+1][i][j];
							if (cnt + 1 != j)
								arr[k + 1][i][j] = 0;
						}
					}
					else
					{
						arr[k + 1][i][cnt--] = arr[k + 1][i][j];
						if (cnt + 1 != j)
							arr[k + 1][i][j] = 0;
					}
				}
			}
		}
	}
	else if (dir == 4) { // Bottom Side
		//cout << "Down\n";
		for (int i = 0; i < N; i++) {
			int cnt = N-1;
			for (int j = N-1; j >= 0; j--) {
				if (arr[k][j][i] != 0) arr[k + 1][cnt--][i] = arr[k][j][i];
			}
			cnt = N - 1;
			for (int j = N-1; j >= 0; j--) {
				if (arr[k+1][j][i] != 0) {
					if (j != 0) {
						if (arr[k+1][j][i] == arr[k+1][j - 1][i]) {
							arr[k + 1][cnt--][i] = arr[k+1][j][i] * 2;
							arr[k + 1][j - 1][i] = 0;
							if (cnt + 1 != j) arr[k + 1][j][i] = 0;
							j--;
						}
						else {
							arr[k + 1][cnt--][i] = arr[k+1][j][i];
							if (cnt + 1 != j)
								arr[k + 1][j][i] = 0;
						}
					}
					else {
						arr[k + 1][cnt--][i] = arr[k + 1][j][i];
						if (cnt + 1 != j)
							arr[k + 1][j][i] = 0;
					}
				}
			}
		}
	}
}

void init_specific_layer(int k) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[k][i][j] = 0;
}

void func(int k) {
	if (k == 5) { // 5번 수행시 종료
		int cur_max = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (cur_max < arr[k][i][j]) cur_max = arr[k][i][j];
		if (total_max < cur_max) total_max = cur_max;
		//cout << "sum\n";
		return;
	}

	//cout << "before moving\n";
	//print_arr(k);

	for (int i = 0; i < 4; i++) {
		//cout << k << " " << i << "\n";
		moving_blocks(k, i+1); // 블럭 이동 및 합산
		//print_arr(k+1);
		func(k + 1); // 다음 수행 시작, 재귀
		init_specific_layer(k+1); // 해당 layer 초기화
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[0][i][j];
	func(0);
	cout << total_max;
}