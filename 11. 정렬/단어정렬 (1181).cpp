#include<iostream>
#include<queue>
using namespace std;

int N;

// �켱���� ť���� �� ��带 ������ ����ü
struct verb {
	string s;
	int len;

	// ������ �����ε� 
	bool operator<(const verb& a) const {
		if (a.len != len) return a.len < len;  // ��Ʈ�� ������
		return a.s < s;  // ��Ʈ�� ���� ���� ��
	}
};

priority_queue<verb> PQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		verb verb_buf; // �Է¸��� ���ο� ����ü ����

		// ����ü �� �Ҵ�
		cin >> verb_buf.s; 
		verb_buf.len = verb_buf.s.length();

		// �켱���� ť�� �Է� -> ���ǿ� ���� �ڵ����ĵ�
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