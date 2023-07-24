/*
����
�ð� ����	�޸� ����	����	����	���� ���	���� ����
0.5 �� (�߰� �ð� ����)	256 MB	221740	79044	57544	37.337%
����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
14
push 1
push 2
top
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
top
���� ��� 1
2
2
0
2
1
-1
0
1
-1
0
3
���� �Է� 2
7
pop
top
push 123
top
pop
top
pop
���� ��� 2
-1
-1
123
123
-1
-1
*/
//#include<iostream>
//#include<string>
//using namespace std;
//
//const int MX = 100005;
//int arr[MX];
//int pos = 0;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int num;
//	cin >> num;
//	
//	string s;
//	int x;
//	for (int i = 0; i < num; i++) {
//		cin >> s;
//		if (s == "push") {
//			cin >> x;
//			arr[pos++] = x;
//		}
//		else if (s == "pop") {
//			if (pos == 0) cout << -1 << "\n";
//			else cout << arr[--pos] << "\n";
//		}
//		else if (s == "size") cout << pos << "\n";
//		else if (s == "empty") {
//			if (pos == 0) cout << 1 << "\n";
//			else cout << 0 << "\n";
//		}
//		else if (s == "top") {
//			if (pos == 0) cout << -1 << "\n";
//			else cout << arr[pos - 1] << "\n";
//		}
//	}
//}

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;

	int num;
	cin >> num;

	string s;
	int x;

	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			S.push(x);
		}
		else if (s == "pop") {
			if (S.empty()) cout << -1 << "\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
		}
		else if (s == "size") cout << S.size() << "\n";
		else if (s == "empty") {
			if (S.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "top") {
			if (S.empty()) cout << -1 << "\n";
			else cout << S.top() << "\n";
		}
	}

}
