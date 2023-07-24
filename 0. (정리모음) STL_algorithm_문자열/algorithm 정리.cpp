/*
find(start iterator, end iterator, value)
: ���� iter ~ end iter���� �� value�� ����Ű�� iterator�� ��ȯ.

index���� ��� ���ؼ��� start iterator�� ���־�� �Ѵ�.
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
	index = find(DQ.begin(), DQ.end(), 4) - DQ.begin();  // 4�� �ش��ϴ� index=3�� ��ȯ.
	cout << index;
}
