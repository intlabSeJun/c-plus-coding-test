#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// ����
	// ���� ����, �Է����δ� �迭 Ȥ�� ���Ϳ��� �ϰ�, 
	//            ������������ ���ĵǾ� �־�� ��� ������ �����
	int a[3] = { 0,2,3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << "\n";
	} while (next_permutation(a, a + 3));

	int a4[4] = { 3,2,1,0 };
	sort(a4, a4 + 4); // ������ ���� ����
	for (int e : a4)cout << e << " ";
	cout << "\n\n";

	// ����
	// ���ӵ� �������� Ư�� ������ ���� ���
	int b[4] = { 0,0,1,1 };
	do {
		for (int i = 0; i < 4; i++) {
			if (b[i] == 0)
				cout << i + 1;
		}
		cout << "\n";
	} while (next_permutation(b, b + 4));
	cout << "\n";

	// ���ӵ��� ���� �������� Ư�� ������ ���� ���
	int c[4] = { 0,0,1,1 };
	int d[4] = { -2,-1,1,2 };
	do {
		for (int i = 0; i < 4; i++) {
			if (c[i] == 0)
				cout << d[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(c, c + 4));
}