/*
pair�� �� ������ ������ Ÿ���� �ϳ��� ����, �ѹ��� ���� �� �� ����

���� ������ 2���� �����͸� �� ������ ��� ó���� �� ���ϴ�.
*/

#include<iostream>
#include<utility>
#include<queue>
using namespace std;


void print_pair(pair<int, int> p) {
	cout << p.first << " " << p.second;
}

int main() {
	pair<int, int> p1 = { 1,2 };  //����������
	pair<int, int> p2 = make_pair(1, 2); // ���� ������ ���
	pair<string, int>p3 = {"sfdf", 2 };  // �ٸ� �ڷ����� �Բ� ����

	print_pair(p1); // first, second �� ���

	queue<pair<int,int>> q;  // queue ���·� ��� ���� 
	q.push({ 2,3 }); // queue�� front�� �׾���.

	print_pair(q.front());
}