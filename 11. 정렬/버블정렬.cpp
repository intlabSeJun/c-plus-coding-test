/*
��������
- ������ ���鰣�� ���ϸ鼭 swap�����ν�, �������� or ������������ �����. 
- ON^2
*/
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[5] = { 13, 2, 6, 4, -2 };

	int n = 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}

	for (int e : arr) cout << e << " ";
}