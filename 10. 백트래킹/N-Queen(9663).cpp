#include<iostream>
using namespace std;

int N; // 입력 N
bool check[3][40] = {};
/*
 check[0] : column 방향으로 중복 체크
 check[1] : 우측 상단 방향 대각선에서 중복 체크
 check[2] : 좌측 하단 방향 대각선에서 중복 체크

 -> 2차 배열에서 모든 픽셀을 체크하는 것이 아님
 -> 1차 배열에서 기울기(방향)에 따라 체크
    -> O(1)로 중복여부를 확인할 수 있기 때문에 굉장히 빠르며 효과적이다.
*/
int cnt = 0;  // 개수

void func(int x) {
	if (x == N) { //각 행마다 가능한 수를 찾았다면
		cnt++;
		return;
	}

	for (int y = 0; y < N; y++) {  // 각 열마다 반복해서 수행
		if (!check[0][y] && !check[1][x + y] && !check[2][x - y + N - 1]) {
			check[0][y] = 1;
			check[1][x + y] = 1; // 우측 상단의 경향성으로 수식 산출
			check[2][x - y + N - 1] = 1; // 좌측 하단의 경향성으로 수식 산출
			//N-1은 배열의 인덱싱 범위를 양수로 사용하기 위함.

			func(x + 1); // 재귀

			// return하면 이전 값들 초기화.
			check[0][y] = 0;
			check[1][x + y] = 0;
			check[2][x - y + N - 1] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> N;

	func(0);
	cout << cnt;
}