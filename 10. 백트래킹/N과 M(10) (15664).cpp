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
			cout << arr[num[i]] << " ";
		cout << "\n";
		return;
	}
	int st = 0;
	if (k != 0) st = num[k-1]+1;

	int tmp = -1;
	for (int i = st; i < N; i++) {
		if (!check[i] && tmp != arr[i]) {
			check[i] = 1;
			num[k] = i;
			tmp = arr[i];
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