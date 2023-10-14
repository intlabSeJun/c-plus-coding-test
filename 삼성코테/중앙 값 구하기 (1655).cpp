#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<int> PQ1; // max Èü
priority_queue<int> PQ2; // min Èü

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int x;
	cin >> x;
	PQ1.push(x);
	cout << x << "\n";

	for (int i = 1; i < N; i++) {
		cin >> x;
		if (PQ1.top() <= x) {
			if (PQ1.size() >= PQ2.size()) {
				PQ2.push(-PQ1.top());
				PQ1.pop();
				PQ1.push(x);
				
				if(PQ1.size() == PQ2.size())
					cout << PQ1.top() << "\n";
				else
					cout << -PQ2.top() << "\n";
			}
			else if(PQ1.size() < PQ2.size()){
				PQ1.push(x);
				cout << PQ1.top() << "\n";
			}
		}
		else if (PQ1.top() > x && -PQ2.top() < x) {
			if (PQ1.size() > PQ2.size()) {
				PQ2.push(-x);
				cout << PQ1.top() << "\n";
			}
			else if (PQ1.size() == PQ2.size()) {
				PQ2.push(-x);
				cout << -PQ2.top() << "\n";
			}
			else {
				PQ1.push(x);
				cout << PQ1.top() << "\n";
			}
		}
		else if (-PQ2.top() >= x){
			if (PQ1.size() > PQ2.size()) {
				PQ2.push(-x);
				cout << PQ1.top() << "\n";
			}
			else if (PQ1.size() == PQ2.size()) {
				PQ1.push(-PQ2.top());
				PQ2.pop();
				PQ2.push(-x);
				cout << -PQ2.top() << "\n";
			}
			else {
				PQ1.push(-PQ2.top());
				PQ2.pop();
				PQ2.push(-x);
				cout << PQ1.top() << "\n";
			}
		}
	}
}