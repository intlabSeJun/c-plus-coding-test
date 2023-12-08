/*
목표 지점에는 무조건 도달해야 하는 조건을 기준으로 점화식 작성.
N의 위치에 올 수 있는 경우의 수는 2가지로,
1) 연속되지 않게 계단을 밟아서 오는 경우(점프)
2) 연속되게 계단을 밟아서 오는 경우 

이를 점화식으로 나타낸다면,
1) arr[K][1] = max(arr[K-2][1], arr[K-2][2]) + value[i];
2) arr[K][2] = arr[K-1][1] + value[i];

2차원 배열로, column 1은 점프, column 2는 연속 일때의 최대값. 
-> K번째 계단에 올랐을 때, column(1or2) 연속 계단을 밟는 최대값. 
value는 현재 계단의 점수.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[305][2] = {};
int N;
int value[305] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> value[i];

	if (N == 1) cout << value[1]; // 계단이 1개일 경우 예외처리.
	else {
		arr[1][1] = value[1];
		arr[1][2] = 0;
		arr[2][1] = value[2];
		arr[2][2] = value[1] + value[2];

		for (int i = 3; i <= N; i++) {
			arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + value[i];
			arr[i][2] = arr[i - 1][1] + value[i];
		}

		cout << max(arr[N][1], arr[N][2]);
	}
}