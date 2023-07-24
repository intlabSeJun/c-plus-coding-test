/* 문제4
* N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라
* N은 10억 이하의 자연수이다.
* 
* 출력 예시
* func4(5) = 4,
* func4(97615282) = 67108864,
* func4(1024) = 1024
*/
#include <iostream>
using namespace std;


int func4_official(int N) {  // 시간복잡도가 logN이 된다고 함.
	int val = 1;
	while (2 * val <= N) val *= 2;
	return val;
}
int func4(int N) {  // 내가 짠 코드
	if (N == 1) return 1;
	int out = 1;
	for (int i = 2; i <= N;) {
		if (out * i > N) return out;
		else if (out * i == N) return out * i;
		else out = out * i;
	}
}

int main() {
	int arr[] = { 5, 97615282, 1024 };
	int length_arr = sizeof arr / sizeof arr[0];
	for (int i = 0; i < length_arr; i++) {
		cout << "func4(" << arr[i] << ") = " << func4(arr[i]) << endl;
	}
}