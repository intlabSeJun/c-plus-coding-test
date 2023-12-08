#include<iostream>
#include<queue>
using namespace std;

int N;

struct coord {
	int first_t, end_t;

	bool operator < (const coord& a) const {
		if (a.end_t != end_t) return a.end_t < end_t;
		if (a.first_t != first_t) return a.first_t < first_t;
	}
};

priority_queue<coord> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int first, end;
	for (int i = 0; i < N; i++) {
		cin >> first >> end;
		coord k;
		k.first_t = first;
		k.end_t = end;

		PQ.push(k);
	}

	int cur_first_t, cur_end_t;
	coord buf;
	buf = PQ.top();
	PQ.pop();
	cur_first_t = buf.first_t;
	cur_end_t = buf.end_t;
	int total_cnt = 1;

	while (!PQ.empty()) {
		buf = PQ.top();
		PQ.pop();
		if (buf.first_t < cur_end_t) continue;
		cur_first_t = buf.first_t;
		cur_end_t = buf.end_t;
		total_cnt++;
	}

	cout << total_cnt;
}
