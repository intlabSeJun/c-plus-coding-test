#include<iostream>
using namespace std;

int N, M;
bool check[10];
int cnt = 0;

void func(int k) {
	if (cnt == M) {
		for (int i = 0; i < N; i++)
			if (check[i]) cout << i+1 << " ";
		cout << "\n";

		return;
	}

	for (int i = k; i < N; i++) {
		if (!check[i]) {
			check[i] = 1;
			cnt++;
			func(i + 1);
			cnt--;
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(0);
}