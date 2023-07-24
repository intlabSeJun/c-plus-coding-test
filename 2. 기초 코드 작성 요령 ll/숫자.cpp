/*
����
�� ���� ������ �־����� ��, �� �� ���̿� �ִ� ������ ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� ���� A�� B�� �־�����.

���
ù° �ٿ� �� �� ���̿� �ִ� ���� ������ ����Ѵ�.

��° �ٿ��� �� �� ���̿� �ִ� ���� ������������ ����Ѵ�.

�����½�ũ
��ȣ	����	����
1	30
1 �� A, B �� 1000.

2	70
1 �� A, B �� 1015, A�� B�� ���̴� �ִ� 100,000.

���� �Է� 1
8 14
���� ��� 1
5
9 10 11 12 13
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> v(2);

	cin >> v[0] >> v[1];
	sort(v.begin(), v.end());
	
	if (v[0] == v[1] || v[1] - v[0] == 1) cout << 0;
	else {
		cout << v[1] - v[0] - 1 << "\n";
		for (long long i = v[0] + 1; i < v[1]; i++) cout << i << " ";
	}
}
