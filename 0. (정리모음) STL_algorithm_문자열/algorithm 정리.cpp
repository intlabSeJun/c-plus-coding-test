/*
find(start iterator, end iterator, value)
: 시작 iter ~ end iter까지 중 value를 가르키는 iterator를 반환.

index만을 얻기 위해서는 start iterator를 빼주어야 한다.
ex) index = find(start iterator, end iterator, value) - start iterator
*/
 
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int main() {
	deque<int> DQ;
	for (int i = 1; i < 11; i++) DQ.push_back(i);
	int index;
	index = find(DQ.begin(), DQ.end(), 4) - DQ.begin();  // 4에 해당하는 index=3을 반환.
	cout << index;
}
