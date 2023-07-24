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

		for (int e : dat) {  // 찾을 값이 어디에 있는지 파악
			if (e == x) break;
			count++;
		}
		// 찾을 값이 덱에서 맨 앞에 올 때까지 수행
		while (dat.front() != x) {  
			// 덱의 크기의 중간으로 조건문 기준을 잡음
			if (dat.size() % 2 == 0) a = dat.size() / 2;
			else a = dat.size() / 2 + 1;

			// count가 덱의 중앙보다 앞쪽이면 수행
			if (count < a) {
				dat.push_back(dat.front());
				dat.pop_front();
				total_count++;
			}
			else {// count가 덱의 중앙보다 뒤쪽이면 수행
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