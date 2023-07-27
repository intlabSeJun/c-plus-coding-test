#include<iostream>
using namespace std;

int main() {
	int arr[10][10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fill(arr[i][j], arr[i][j] + 10, 0);
		}
	}

	cout << arr[0][0][0];
}