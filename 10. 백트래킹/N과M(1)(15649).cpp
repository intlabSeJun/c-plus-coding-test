#include<iostream>
using namespace std;

int N, M;
int arr[10];
bool check[10];

void func(int k) {
	if (k == M) {
		for (int j = 0; j < M; j++) cout << arr[j] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			arr[k] = i;
			check[i] = 1;
			func(k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;

	func(0);
}