/*
pair는 두 종류의 데이터 타입을 하나로 묶어, 한번에 전달 할 수 있음

서로 연관된 2개의 데이터를 한 쌍으로 묶어서 처리할 때 편리하다.
*/

#include<iostream>
#include<utility>
#include<queue>
using namespace std;


void print_pair(pair<int, int> p) {
	cout << p.first << " " << p.second;
}

int main() {
	pair<int, int> p1 = { 1,2 };  //쌍으로저장
	pair<int, int> p2 = make_pair(1, 2); // 위와 동일한 방식
	pair<string, int>p3 = {"sfdf", 2 };  // 다른 자료형과 함께 가능

	print_pair(p1); // first, second 값 출력

	queue<pair<int,int>> q;  // queue 형태로 사용 가능 
	q.push({ 2,3 }); // queue의 front에 쌓아줌.

	print_pair(q.front());
}