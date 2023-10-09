#include<iostream>
using namespace std;

int N, M;
bool check[10][10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if(check[i][j]) cout << j + 1 << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		check[k][i] = 1;
		func(k + 1);
		check[k][i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);
}