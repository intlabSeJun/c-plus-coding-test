/*
�켱���� ť�� pop�� �� �� ���� �켱������ ���� ���Ұ� ������ ť

< �ܼ� �迭�� ������ >
1. ������ �߰��� O(1)
2. �켱������ ���� ���� ������ Ȯ�� O(N)
3. �켱������ ���� ���� ������ ���Ű� O(N)

< �� �̶�� ������ �̿�� >
1. ������ �߰��� O(lgN)
2. �켱������ ���� ���� ������ Ȯ�� O(1)
3. �켱������ ���� ���� ������ ���Ű� O(lgN)

< ���� �����ϱ�? +�ּ� ��, �ִ� �� >
���� ����Ʈ�� ������ ������ ����. 
������, ���� �˻� Ʈ���ʹ� �ٸ���. 
���� �ִ밪 Ȥ�� �ּڰ��� ã�� ���� ����� �� ����. (�ִ� ��, �ּ� ��)
�ּ� �� : ��Ʈ�� ���� ���� ��. + �θ� ��尡 �ڽ� ��庸�� �۾ƾ� ��.
����, ���̰� ���� ������ ���ʴ�� ä������ ������ Ʈ���� �ұ����� �߻����� ����.

< ���� ���� ���� >
�θ� ���� ���ؼ� ���ĵ�.
��, �ִ� Ʈ�� ���̸�ŭ�� ���ϸ� ��.
���� Ʈ���̱� ������ ������ �ð� ���⵵�� O(lgN)�̴�.

< �ּҰ�(��Ʈ) ���� ���� >
Ʈ���� ���� ������ ������ �ڸ��� �ٲٰ� ����, �ּҰ� ������.
�׸��� ���� ������ ������ �� �ְ� ���������� ����� ��ġ�� �ٲ۴�. 

< prioirty_queue���� �� �� �ִ°� ������ set������ �� �� �ְ�, �ð� ���⵵�� �����ϴ�.
�׷��� set�� �����ϴ� ����� �� ������ priority_queue�� �� ������ �ֳ���? >
�´� ��������, priority_queue�� �� ���� �ӵ��� ������, ������ ���� �����մϴ�.
set�� �ұ����� ���� ó���� �ʿ��ϱ� ������ �׷���.

*/

// ����ü�� Ȱ���� �켱���� ť Ǯ��.
//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//struct node {
//	int x;
//
//	bool operator<(const node& a) const {
//		if (abs(x) != abs(a.x)) return abs(a.x) < abs(x);
//		return a.x < x;
//	}
//};
//
//priority_queue<node> PQ;
//int N;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//
//	int x;
//	for (int i = 0; i < N; i++) {
//		cin >> x;
//		node x_node;
//		x_node.x = x;
//
//		if (x == 0) {
//			if (PQ.empty()) cout << 0 << "\n";
//			else {
//				cout << PQ.top().x << "\n";
//				PQ.pop();
//			}
//		}
//		else PQ.push(x_node);
//	}
//}

// class�� Ȱ���� �켱���� ť Ǯ��
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N;

class cmp {
public:
	bool operator() (int a, int b) {  // b�� ��Ʈ��� 
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
		//return a > 0 && b < 0;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	priority_queue<int, vector<int>, cmp> PQ;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (PQ.empty()) cout << 0 << "\n";
			else {
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else PQ.push(x);
	}

}