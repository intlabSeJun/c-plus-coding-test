#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<int> DQ;
	DQ.push_front(10);
	DQ.push_back(50);
	for (auto x : DQ) cout << x;
	cout << DQ.size() << "\n";
	if (DQ.empty()) cout << "DQ is empty\n";
	else cout << "DQ is not empty\n";

	DQ.pop_front();
	DQ.pop_back();
	cout << DQ.back() << "\n";
	cout << DQ.front();

	// 특이하게 insert, erase 가능하다.(stack, queue에서는 안됨)
	// stl vector와 비슷함. 
	DQ.insert(DQ.begin() + 1, 33);
	DQ.insert(DQ.begin() + 4, 22);
	DQ.erase(DQ.begin() + 3);
	DQ.clear();
}