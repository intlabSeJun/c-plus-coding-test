/*
��� ��Ʈ
- 0~9������ ����Ʈ ����
- 1�� �ڸ� ���� ���� �� ����Ʈ�� ���� -> 0���� ���������� ����
- 10�� �ڸ� ���� ���� �� ����Ʈ�� ���� -> ������ ����
- N�� �ڸ����� �����ϸ� ���� �ϼ�

- ����Ʈ�� ����ϱ⿡ STL�� �ʿ��ϴٰ� ��.

*/
#include<iostream>
#include<vector>
using namespace std;

int n = 15;  // ���� ����
int arr[1000001] = {};  // �� ��� �ִ� �迭
int d = 3;  // ���� �ڸ��� ����
int p10[3];  // ���� �ڸ��� 1,10,100 ������ ����

int digitNum(int x, int a) { // ��, �ڸ��� ����
	return (x / p10[a]) % 10;  // �ش� �ڸ����� �� ����
}

vector<int> l[10];  // ����Ʈ 0~9����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p10[0] = 1;
	for (int i = 1; i < d; i++) p10[i] = p10[i - 1] * 10; // 10,100 ����
	for (int i = 0; i < d; i++) {  // �� �ڸ������� ���ؼ� ����
		for (int j = 0; j < 10; j++) l[j].clear(); // ����Ʈ ����ְ�
		for (int j = 0; j < n; j++) // �ڸ����� ���� �� ����Ʈ�� ����.
			l[digitNum(arr[j], i)].push_back(arr[j]);
		int aidx = 0;
		for (int j = 0; j < 10; j++) { // �ٽ� ���� �迭�� ����
			for (auto x : l[j]) arr[aidx++] = x;  // ����Ʈ���� ���������� ����
		}
	}
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}