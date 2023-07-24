//https://www.acmicpc.net/problem/1021
#include<iostream>
#include<deque>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, k;
	cin >> num >> k;

	deque<int> dat;
	for (int j = 1; j < num + 1; j++) dat.push_back(j);

	int x, total_count=0, count = 0, a;
	for (int i = 0; i < k; i++) {
		cin >> x;

		for (int e : dat) {  // ã�� ���� ��� �ִ��� �ľ�
			if (e == x) break;
			count++;
		}
		// ã�� ���� ������ �� �տ� �� ������ ����
		while (dat.front() != x) {  
			// ���� ũ���� �߰����� ���ǹ� ������ ����
			if (dat.size() % 2 == 0) a = dat.size() / 2;
			else a = dat.size() / 2 + 1;

			// count�� ���� �߾Ӻ��� �����̸� ����
			if (count < a) {
				dat.push_back(dat.front());
				dat.pop_front();
				total_count++;
			}
			else {// count�� ���� �߾Ӻ��� �����̸� ����
				dat.push_front(dat.back());
				dat.pop_back();
				total_count++;
			}
		}
		count = 0;
		dat.pop_front();
	}
	cout << total_count;
}