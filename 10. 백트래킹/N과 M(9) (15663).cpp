#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[10];
int num[10];
int check[10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}

	int tmp=0; // 이전 수열의 중복 여부 체크를 위한 변수
	for (int i = 0; i < N; i++) {
		if (!check[i] && tmp != arr[i]) { // 이전 수열의 항과 새로운 항의 값이 같으면 수행안함
			check[i] = 1;                 // sort()로 오름차순 정렬되었기 때문에, 같은 숫자는 바로 인접해 있음.
			num[k] = arr[i];              // 이 점을 이용하여 바로 이전의 값을 저장해놓고, 다음 값과 같으면 패스.
			tmp = num[k];                 // 추가적으로, k는 현재 상태 순서(출력할 순서)를 나타냄.
			func(k + 1);                  // 따라서, 현재 상태에서의 이전 값을 tmp로 저장해놓는 것임.
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	func(0);
}