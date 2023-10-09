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

	/*
	// ���� ������ �װ� ���ο� ���� ���� ������ �������
	// sort()�� �������� ���ĵǾ��� ������, ���� ���ڴ� �ٷ� ������ ����.
	// �� ���� �̿��Ͽ� �ٷ� ������ ���� �����س���, ���� ���� ������ �н�.
	// �߰�������, k�� ���� ���� ����(����� ����)�� ��Ÿ��.
	// ����, ���� ���¿����� ���� ���� tmp�� �����س��� ����.
	*/
	int tmp=0; // ���� ������ �ߺ� ���� üũ�� ���� ����
	for (int i = 0; i < N; i++) {
		if (!check[i] && tmp != arr[i]) { 
			check[i] = 1;                 
			num[k] = arr[i];              
			tmp = num[k];                
			func(k + 1);                  
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