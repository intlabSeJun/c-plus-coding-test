#include<iostream>
#include<queue>
using namespace std;

int N;

// 우선순위 큐에서 각 노드를 구성할 구조체
struct verb {
	string s;
	int len;

	// 연산자 오버로딩 
	bool operator<(const verb& a) const {
		if (a.len != len) return a.len < len;  // 루트가 작은값
		return a.s < s;  // 루트가 작은 사전 순
	}
};

priority_queue<verb> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		verb verb_buf; // 입력마다 새로운 구조체 선언

		// 구조체 값 할당
		cin >> verb_buf.s; 
		verb_buf.len = verb_buf.s.length();

		// 우선순위 큐에 입력 -> 조건에 따라 자동정렬됨
		PQ.push(verb_buf);
	}

	string ss = "-1";
	for (int i = 0; i < N; i++) {
		verb verb_buf;
		verb_buf = PQ.top();
		PQ.pop();
		if (verb_buf.s == ss) continue;
		ss = verb_buf.s;
		cout << verb_buf.s << "\n";
	}
}