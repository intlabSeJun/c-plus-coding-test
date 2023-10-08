#include<iostream>
using namespace std;

int N; // �Է� N
bool check[3][40] = {};
/*
 check[0] : column �������� �ߺ� üũ
 check[1] : ���� ��� ���� �밢������ �ߺ� üũ
 check[2] : ���� �ϴ� ���� �밢������ �ߺ� üũ

 -> 2�� �迭���� ��� �ȼ��� üũ�ϴ� ���� �ƴ�
 -> 1�� �迭���� ����(����)�� ���� üũ
    -> O(1)�� �ߺ����θ� Ȯ���� �� �ֱ� ������ ������ ������ ȿ�����̴�.
*/
int cnt = 0;  // ����

void func(int x) {
	if (x == N) { //�� �ึ�� ������ ���� ã�Ҵٸ�
		cnt++;
		return;
	}

	for (int y = 0; y < N; y++) {  // �� ������ �ݺ��ؼ� ����
		if (!check[0][y] && !check[1][x + y] && !check[2][x - y + N - 1]) {
			check[0][y] = 1;
			check[1][x + y] = 1; // ���� ����� ���⼺���� ���� ����
			check[2][x - y + N - 1] = 1; // ���� �ϴ��� ���⼺���� ���� ����
			//N-1�� �迭�� �ε��� ������ ����� ����ϱ� ����.

			func(x + 1); // ���

			// return�ϸ� ���� ���� �ʱ�ȭ.
			check[0][y] = 0;
			check[1][x + y] = 0;
			check[2][x - y + N - 1] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> N;

	func(0);
	cout << cnt;
}