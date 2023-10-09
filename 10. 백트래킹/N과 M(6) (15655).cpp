#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[10] = {};
bool check[10] = {};
int buf[10] = {};

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << arr[buf[i]] << " "; // 인덱스 순서별로 출력
		cout << "\n";
	}

	int st = 0;
	if (k != 0) st = buf[k - 1] + 1;
	for (int i = st; i < N; i++) {
		if(!check[i]){
			buf[k] = i; // 인덱스 순서를 저장
			check[i] = 1;
			func(k + 1);
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