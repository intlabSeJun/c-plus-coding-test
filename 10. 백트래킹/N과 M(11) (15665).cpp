#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if (tmp != arr[i]) {
			num[k] = arr[i];
			tmp = num[k];
			func(k + 1);
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