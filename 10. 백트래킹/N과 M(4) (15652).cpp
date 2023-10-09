#include<iostream>
using namespace std;

int N, M;
int arr[10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	/*for (int i = 1; i <= N; i++) {
		if (k != 0) {
			if (arr[k - 1] <= i)
			{
				arr[k] = i;
				func(k + 1);
			}
		}
		else {
			arr[k] = i;
			func(k + 1);
		}
	}*/

	int st;
	if (k != 0) st = arr[k - 1];
	else st = 1;
	for (int i = st; i <= N; i++) {
		arr[k] = i;
		func(k + 1);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);
}