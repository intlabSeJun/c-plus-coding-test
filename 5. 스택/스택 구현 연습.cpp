#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {  // 스택에 x를 추가
	dat[pos++] = x;
}

void pop() {  // 맨 위의 원소 제거
	if (pos != 0) {
		pos--;
	}
}

int top() {  // 맨 위의 원소의 값을 확인
	if (pos != 0) cout << dat[pos-1];
}

void test() {  // 

}

int main() {

}