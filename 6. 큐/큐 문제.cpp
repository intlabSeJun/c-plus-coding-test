/*
* ť
�ð� ����	�޸� ����	����	����	���� ���	���� ����
0.5 �� (�߰� �ð� ����)	256 MB	106692	49076	38467	48.913%
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1 
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
���� ��� 1 
1
2
2
0
1
2
-1
0
1
-1
0
3
*/

#include<iostream>
#include<string>
using namespace std;

const int MX = 100005;
int que[MX];
int tail = 0, head = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	
	string s;
	int x;
	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			que[tail++] = x;
		}
		else if (s == "pop") {
			if (tail == head) cout << -1 << "\n";
			else cout << que[head++] << "\n";
		}
		else if (s == "size") cout << tail - head << "\n";
		else if (s == "empty") {
			if (tail == head) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (tail == head) cout << -1 << "\n";
			else cout << que[head] << "\n";
		}
		else if (s == "back") {
			if (tail == head) cout << -1 << "\n";
			else cout << que[tail - 1] << "\n";
		}
	}
}


#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	queue<int> Q;
	string s;
	int x;
	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			Q.push(x);
		}
		else if (s == "pop") {
			if (Q.empty()) cout << -1 << "\n";
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (s == "size") cout << Q.size() << "\n";
		else if (s == "empty") {
			if (Q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.front() << "\n";
		}
		else if (s == "back") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.back() << "\n";
		}
	}
}