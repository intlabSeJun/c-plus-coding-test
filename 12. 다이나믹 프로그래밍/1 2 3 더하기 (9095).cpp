#include<iostream>
using namespace std;

int arr[13] = {};
int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// �ʱⰪ 3�� �Ҵ�
	arr[1] = 1;  
	arr[2] = 2;
	arr[3] = 4;

	// ��ȭ���� ������� �迭 ä���
	for (int i = 4; i < 12; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

	cin >> T;
	int x;
	for (int i = 0; i < T; i++) {
		cin >> x;
		cout << arr[x] << "\n";
	}
}