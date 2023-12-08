#include<iostream>
using namespace std;

int N;
int arr[1005][3] = {};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}


}