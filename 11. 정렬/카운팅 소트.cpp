/*
���� ������ ������ ī��Ʈ�Ͽ�, ����ϴ� ���

���� ������ �������� ��쿡�� ����� �� ����. 

*/

#include<iostream>
using namespace std;

int freq[200001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		freq[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++) {
		while (freq[i]--) {
			cout << i - 1000000 << "\n";
		}
	}
}