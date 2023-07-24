#include <iostream>


int func2(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] + arr[j] == 100) {
				return 1;
			}
		}
	}
}

int main() {
	int arr[] = { 1, 52, 48 };
	int out = func2(arr, 3);
	std::cout << out << '\n';
}