#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {  // ���ÿ� x�� �߰�
	dat[pos++] = x;
}

void pop() {  // �� ���� ���� ����
	if (pos != 0) {
		pos--;
	}
}

int top() {  // �� ���� ������ ���� Ȯ��
	if (pos != 0) cout << dat[pos-1];
}

void test() {  // 

}

int main() {

}