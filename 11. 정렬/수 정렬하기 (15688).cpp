//https://www.acmicpc.net/problem/15688
#include<iostream>
using namespace std;

int N;
int arr[1000005] = {};
int tmp[1000005] = {};

void merge_sort(int st, int en) {
	if (st + 1 == en) return;

	int mid = (st + en) / 2;

	merge_sort(st, mid);
	merge_sort(mid, en);
	
	int L = st;
	int R = mid;
	for (int i = st; i < en; i++) {
		if (L == mid) tmp[i] = arr[R++];
		else if (R == en) tmp[i] = arr[L++];
		else if (arr[L] < arr[R]) tmp[i] = arr[L++];
		else tmp[i] = arr[R++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	merge_sort(0, N);
	for (int i = 0; i < N; i++) cout << arr[i] << "\n";
}