#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[10];
bool check[10] = {};
int buf[10] = {};

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << buf[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = 1;
			buf[k] = arr[i];
			func(k + 1);
			check[i] = 0;
			buf[k] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr+N);
	//for (int i = 0; i < N; i++) cout<< arr[i];
	func(0);
}