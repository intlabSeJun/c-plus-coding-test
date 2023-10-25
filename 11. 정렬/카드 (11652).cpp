#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<long long> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	long long x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		PQ.push(x);
	}

	int cur_count = 0;
	int max_count = 0;
	long long max_count_value = PQ.top();
	long long cur_count_value = PQ.top();
	PQ.pop();
	cur_count++;
	for (int i = 1; i < N; i++) {
		x = PQ.top();
		PQ.pop();

		if (x == cur_count_value) {
			cur_count++;
		}
		else {
			cur_count = 1;
			cur_count_value = x;
		}
		if (cur_count >= max_count) {
			max_count = cur_count;
			max_count_value = x;
		}
	}

	cout << max_count_value;
}