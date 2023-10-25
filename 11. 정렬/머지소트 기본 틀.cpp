/*
머지소트(Merge Sort)
- 재귀적으로 수열을 나눠 정렬한 후 합치는 정렬법
- 두 배열을 합쳐서 정렬된 배열을 만든다. 
- O(NlogN)

오름차순 머지소트일 경우
- 두 배열중 가장 작은 것들만 비교해서, 작은 수를 합해지는 배열에 채워넣으면 됨.
- 하지만, 그 전에 각 배열을 오름차순으로 만들어 놔야 한다. 

보다 개념적인 머지소트 방법은 다음과 같다
- 배열을 작은 단위, 1개까지 나누어서 2개씩 비교하고, 이를 머지소트를 반복하면서 배열을 완성한다.
*/

// 서로 다른 두 배열을 머지소트 하는 기본 예제
// https://www.acmicpc.net/problem/11728
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int N, M;
//int arr1[1000005] = {};
//int arr2[1000005] = {};
//int arr3[1000005] = {};
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) cin >> arr1[i];
//	for (int i = 0; i < M; i++) cin >> arr2[i];
//
//	sort(arr1, arr1 + N);
//	sort(arr2, arr2 + M);
//
//	int k1 = 0, k2 = 0;
//
//	for (int i = 0; i < N + M; i++) {
//		if (k1 >= N) {
//			arr3[i] = arr2[k2++];
//		}
//		else if (k2 >= M) arr3[i] = arr1[k1++];
//		else {
//			if (arr1[k1] < arr2[k2]) arr3[i] = arr1[k1++];
//			else arr3[i] = arr2[k2++];
//		}
//	}
//
//	for (int i = 0; i < N + M; i++) cout << arr3[i] << " ";
//
//}


// 하나의 배열을 머지소트를 이용하여 빠르게 정렬하는 "머지소트 예제"
#include<iostream>
using namespace std;

int n = 10;
int arr[1000005] = {};
int tmp[1000005];

void merge(int st, int en) {
	int mid = (st + en) / 2; // 중간지점 구함
	int lidx = st; // 중간지점에서 왼쪽 배열의 가장 처음
	int ridx = mid; // 중간지점에서 오른쪽 배열의 가장 처음
	// 두 배열을 merge sort하는 것과 동일하다
	// 여기서는 배열을 1개 단위까지 쪼개서 merge sort를 bottom up 방식으로 수행
	// 따라서, 중간지점으로 배열을 나누었을 때, 각 왼쪽/오른쪽 구간은 정렬이 되어 있는 상태임.
	for (int i = st; i < en; i++) { // lidx, ridx를 기점으로 가장 작은 값들을 비교하면서 tmp에 저장
		if (ridx == en) tmp[i] = arr[lidx++]; // 중간지점 이후 오른쪽 배열 모두 저장되었으므로, 왼쪽 배열만 저장하면 된다
		else if (lidx == mid) tmp[i] = arr[ridx++]; // 중간지점 이후 왼쪽 배열 모두 저장되었으므로, 오른쪽 배열만 저장.

		// 양쪽 배열의 가장 작은(낮은 인덱스) 값들간의 비교를 통해 저장.
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++]; // 왼쪽 배열의 가장 낮은 값이 더 작을 때
		else tmp[i] = arr[ridx++]; // 오른쪽 배열의 가장 낮은 값이 더 작을 때
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i]; // 다시 원래 배열에 넣어줌
}

void merge_sort(int st, int en) {
	/*
	arr[st:en]까지의 정렬을 수행하는 함수. st ~ en-1 까지.
	
	재귀적으로 수행되는 함수이며, 가장 낮은 단위인 1개까지 갔다가 merge sort하면서 bottom up 한다.
	*/
	if (en == st + 1) return; // 비교하려는 수가 2개일때 return
	int mid = (st + en) / 2;
	merge_sort(st, mid); // 분할
	merge_sort(mid, en); // 분할
	merge(st, en);  // 구간내에서 왼쪽/오른쪽 배열 비교하여 머지소트한다. 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}