#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<int> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int x, top_1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			PQ.push(-x);
		}
		if (i == 0) continue;
		for (int k = 0; k < N; k++) {
			PQ.pop();
		}
	}

	cout << PQ.top()*-1;
}