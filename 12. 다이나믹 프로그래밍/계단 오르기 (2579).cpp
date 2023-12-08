/*
��ǥ �������� ������ �����ؾ� �ϴ� ������ �������� ��ȭ�� �ۼ�.
N�� ��ġ�� �� �� �ִ� ����� ���� 2������,
1) ���ӵ��� �ʰ� ����� ��Ƽ� ���� ���(����)
2) ���ӵǰ� ����� ��Ƽ� ���� ��� 

�̸� ��ȭ������ ��Ÿ���ٸ�,
1) arr[K][1] = max(arr[K-2][1], arr[K-2][2]) + value[i];
2) arr[K][2] = arr[K-1][1] + value[i];

2���� �迭��, column 1�� ����, column 2�� ���� �϶��� �ִ밪. 
-> K��° ��ܿ� �ö��� ��, column(1or2) ���� ����� ��� �ִ밪. 
value�� ���� ����� ����.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[305][2] = {};
int N;
int value[305] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> value[i];

	if (N == 1) cout << value[1]; // ����� 1���� ��� ����ó��.
	else {
		arr[1][1] = value[1];
		arr[1][2] = 0;
		arr[2][1] = value[2];
		arr[2][2] = value[1] + value[2];

		for (int i = 3; i <= N; i++) {
			arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + value[i];
			arr[i][2] = arr[i - 1][1] + value[i];
		}

		cout << max(arr[N][1], arr[N][2]);
	}
}