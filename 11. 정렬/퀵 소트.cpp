/*
만약, 코딩 테스트에서 stl 못쓰고 직접 구현한다면, 퀵소트 말고 머지소트를 써야 한다.
(퀵 소트만큼은 쓰지 말라고 함)


퀵 소트
- 재귀적으로 작동함.
- 추가저인 공간을 사용하지 않아 매우 빠르다. (In-Place Sort)
- 원소의 위치를 서로 잘 바꿔주면 된다. 
- 배열의 양쪽 끝에 포인터 2개(L, R)를 두고 적절히 스왑.
- L은 pivot(기준이 되는 값)보다 큰 값이 나올 때 까지 오른쪽으로 이동
- R은 pivot보다 작거나 같은 값이 나올 때 까지 왼쪽으로 이동
- L과 R이 특정 지점에 머물른다면, 해당 값들을 스왑한다.
- 이러한 동작을 L과 R이 교차할 때 까지 수행한다. (R < L 인 경우에 멈춘다)
- 그 순간, R과 pivot과 스왑한다.  
- 그 결과, pivot보다 작은 값들이 왼쪽(작은 인덱스), pivot보다 큰 값들이 오른쪽(큰 인덱스)로 형성됨. 
  - 정렬로 이루어지는 것은 아니지만, 특정 값을 기준으로 나눈다고 생각하면 된다. 
  - 하지만, 이러한 과정을 머지소트에서 했던 것처럼 낮은 단위까지 계속 반복하면 정렬이 된다.
  - pivot은 재귀적으로 분할해서 병합할 시에, 구간에서의 가장 낮은 인덱스 값을 기준으로 하면 됨
- O(NlogN)
- 속도가 굉장히 빠름. 머지소트보다 평균적으로 빠르다. 
- 단점 : 최악의 경우 O(N^2)이다. 배열이 오름차순이거나 내림차순일 경우에 그렇다
         그렇기 때문에, 직접 정렬을 짜야할 때는 퀵소트 말고 머지소트를 써라. 머지소트도 충분히 빠름. 


- 에시 코드
int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};
int pivot = arr[0];
int L = 1, R = 7;
while(1) {
	// pivot보다 큰/작은 L/R 지점까지 이동
	while (L <= R && arr[L] <= pivot) L++;
	while (L <= R && arr[R] > pivot) R--;

	if (L > R) break; // 교차되면 종료
	swap(arr[L], arr[R]); // 이동된 지점 간의 스왑
}
swap(arr[0], arr[R]); // pivot 스왑

*/

#include<iostream>
using namespace std;

int n = 10;
int arr[1000005] = {};

void quick_sort(int st, int en) {
	if (en <= st + 1) return;

	int pivot = arr[st];
	int L = st + 1;
	int R = en - 1;
	while (1) {
		while (L <= R && arr[L] <= pivot) L++;
		while (L <= R && arr[R] >= pivot) R--;
		if (L > R) break;
		swap(arr[L], arr[R]);
	}
	swap(arr[st], arr[R]);

	// 재귀적으로 낮은 단위까지 분할하면서 퀵 소트하면 정렬 완료됨
	quick_sort(st, R); 
	quick_sort(R + 1, en);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	quick_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}