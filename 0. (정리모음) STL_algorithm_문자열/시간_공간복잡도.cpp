/*

*/
# include <iostream>
using namespace std;

// 아래 코드가 몇 번의 연산을 수행하는지 알아보자
int func1(int arr[], int n) {
	int cnt = 0;  // 1
	for (int i = 0; i < n; i++) {  // 초기값 대입: 1, i가 n보다 작은지 확인: 1, 작을 경우 i를 증가시키는 연산 : 1 -> 이를 n번 반복 = 1 + n x(2)
		if (arr[i] % 5 == 0) cnt++;  // arr을 5로 나눈 나머지를 계산: 1, 결과가 0과 일치하는지 : 1, cnt++ : 1, = 3 
	}
	return cnt;  // 반환시 1
	// 따라서, 총 연산은 1+1+nx(2+2+1)+1 = 5n+3
	// 이를 간단히, 5n+3 -> n에 비례한다 라고 말함. 

	/*
		시간 복잡도(TIme Complexity)
		: 입력의 크기와 문제를 해결하는데 걸리는 시간의 상관관계

		빅오표기법(Big-O Notation)
		: 주어진 식을 값이 가장 큰 대표항만 남겨서 나타내는 방법.
		O(N) : 5N + 3, 2N + 10logN, 10N
		O(N^2) : N^2 + 2n +4, 6N^2
		O(NlogN) : NlogN + 30N
		O(1) : 15, 30
	*/
}