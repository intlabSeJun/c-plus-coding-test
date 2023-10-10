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
				if (arr[k+1][i][j] != 0) { // �� ����� ����
					if (j + 1 != N) { // �������� �����ϰ� ����
						if (arr[k+1][i][j] == arr[k+1][i][j + 1]) { // ���簪�� ������ ���� ���� �� ����
							arr[k + 1][i][cnt++] = arr[k+1][i][j] * 2;
							arr[k + 1][i][j + 1] = 0; //������ �� ����
							if (cnt - 1 != j) arr[k + 1][i][j] = 0; // ���� �� ����, ��,�����ߴ� �� ����
							j++; // ������ ���������Ƿ� �� �ʿ� ����
						}
						else { // ���� ���� ���� �� �ٸ� �� ����
							arr[k + 1][i][cnt++] = arr[k + 1][i][j]; // moving point�� ����
							if(cnt-1 != j) // �����ߴ� �� �ƴϸ�, ������ �� ����
								arr[k + 1][i][j] = 0;
						}
					}
					else { // ������ ���� �� ����
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
	if (k == 5) { // 5�� ����� ����
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
		moving_blocks(k, i+1); // �� �̵� �� �ջ�
		//print_arr(k+1);
		func(k + 1); // ���� ���� ����, ���
		init_specific_layer(k+1); // �ش� layer �ʱ�ȭ
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