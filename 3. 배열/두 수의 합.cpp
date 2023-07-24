/*
�� ���� �� �ٱ���
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	128 MB	39376	14007	10496	34.855%
����
n���� ���� �ٸ� ���� ���� a1, a2, ..., an���� �̷���� ������ �ִ�. ai�� ���� 1���� ũ�ų� ����, 1000000���� �۰ų� ���� �ڿ����̴�. �ڿ��� x�� �־����� ��, ai + aj = x (1 �� i < j �� n)�� �����ϴ� (ai, aj)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� n�� �־�����. ���� �ٿ��� ������ ���ԵǴ� ���� �־�����. ��° �ٿ��� x�� �־�����. (1 �� n �� 100000, 1 �� x �� 2000000)

���
������ ������ �����ϴ� ���� ������ ����Ѵ�.

���� �Է� 1
9
5 12 7 10 9 1 2 3 11
13
���� ��� 1
3
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	
	long long k;
	vector<long long> v(n,0);
	vector<long long> count_v(2000000, 0);
	for (long long i = 0; i < n; i++) {
		cin >> k;
		v[i] = k;
		count_v[k]++;
	}

	long long sum;
	cin >> sum;

	int count = 0;
	for (int e : v) {
		if (sum <= e) continue;
		if (count_v[sum - e] != 0) count++;
	}
	cout << count/2;
}
