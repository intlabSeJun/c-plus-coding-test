/*
����
���� N���� �̷���� ���� A�� ���� X�� �־�����. �̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� X�� �־�����. (1 �� N, X �� 10,000)

��° �ٿ� ���� A�� �̷�� ���� N���� �־�����. �־����� ������ ��� 1���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.

���
X���� ���� ���� �Է¹��� ������� �������� ������ ����Ѵ�. X���� ���� ���� ��� �ϳ� �����Ѵ�.

���� �Է� 1
10 5
1 10 4 9 2 3 8 5 7 6
���� ��� 1
1 4 2 3
*/

#include <iostream>
using namespace std;
#include <string>
#include <vector>

//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int a, b;
//	cin >> a >> b;
//	cin.ignore();
//
//	vector<int> v(a);
//	
//	for (int i = 0; i < a; i++) {
//		cin >> v[i];
//		if (v[i] < b) cout << v[i] << " ";
//	}
//}

// officia code
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, t;
	cin >> a >> b;
	while (a--) {
		cin >> t;
		if (t < b) cout << t << ' ';
	}
}