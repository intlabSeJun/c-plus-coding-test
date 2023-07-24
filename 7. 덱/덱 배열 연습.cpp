#include<iostream>
using namespace std;

const int MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

//void push_front(int x) {
//	if (head == tail) {
//		dat[head--] = x;
//		tail++;
//	}
//	else dat[--head] = x;
//}
//
//void push_back(int x) {
//	dat[tail++] = x;
//}
//
//void pop_front() {
//	if(head != tail) dat[head++] = 0;
//}
//
//void pop_back() {
//	if(head != tail) dat[tail--] = 0;
//}
//
//int front() {
//	if(head != tail) return dat[head];
//}
//
//int back() {
//	if (head != tail) return dat[tail - 1];
//}
//

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

void test() {
	push_front(4);
	push_back(2);
	cout << dat[head] << " " << dat[--tail];

}


int main() {
	test();
}