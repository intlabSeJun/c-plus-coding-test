#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[10];
int num[10];
int check[10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}

	int tmp=0; // ���� ������ �ߺ� ���� üũ�� ���� ����
	for (int i = 0; i < N; i++) {
		if (!check[i] && tmp != arr[i]) { // ���� ������ �װ� ���ο� ���� ���� ������ �������
			check[i] = 1;                 // sort()�� �������� ���ĵǾ��� ������, ���� ���ڴ� �ٷ� ������ ����.
			num[k] = arr[i];              // �� ���� �̿��Ͽ� �ٷ� ������ ���� �����س���, ���� ���� ������ �н�.
			tmp = num[k];                 // �߰�������, k�� ���� ���� ����(����� ����)�� ��Ÿ��.
			func(k + 1);                  // ����, ���� ���¿����� ���� ���� tmp�� �����س��� ����.
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	func(0);
}