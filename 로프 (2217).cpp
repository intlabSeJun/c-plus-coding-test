#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<int> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		PQ.push(x);
	}

	int total_max, cur_max;
	total_max = PQ.top();
	PQ.pop();
	int cnt = 1;

	while (!PQ.empty()) {
		cnt++;
		cur_max = PQ.top() * cnt;
		PQ.pop();
		if (cur_max > total_max) total_max = cur_max;
	}

	cout << total_max;
}