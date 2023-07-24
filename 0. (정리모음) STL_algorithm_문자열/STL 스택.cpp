#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> S;
	S.push(10);
	S.push(20);
	S.push(30);
	cout << S.size() << "\n";

	if (S.empty()) cout << "S is empty\n";
	else cout << "S is not empty\n";
	S.pop();
	cout << S.top() << "\n";
	S.pop();
	cout << S.top() << "\n";
	S.pop();
	if (S.empty()) cout << "S is empty\n";
	cout << S.top() << "\n";  // runtime error 발생, 비어있으면 생김. S.pop도 마찬가지. 
}