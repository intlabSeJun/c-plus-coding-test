#include<iostream>
using namespace std;

int N;
int arr[10000005] = {};

void quick_sort(int st, int en) {
	if (st + 1 >= en) return;

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

	quick_sort(st, R);
	quick_sort(R+1, en);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	quick_sort(0, N);
	for (int i = 0; i < N; i++) cout << arr[i] << "\n";
}