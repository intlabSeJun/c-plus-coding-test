/*
�Է�
ù �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����. T�� �ִ� 1,000,000�̴�. ���� T�ٿ��� ���� �� ���� A�� B�� �־�����. A�� B�� 1 �̻�, 1,000 �����̴�.

���
�� �׽�Ʈ���̽����� A+B�� �� �ٿ� �ϳ��� ������� ����Ѵ�.

���� �Է� 1
5
1 1
12 34
5 500
40 60
1000 1000
���� ��� 1
2
46
505
100
2000
*/
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num_T;
	int a, b;
	cin >> num_T;
	for (int i = 0; i < num_T; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}