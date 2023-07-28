#include<iostream>
#include<tuple>
using namespace std;
#include<string>
int main() {
	/* 1. tuple 초기화*/
	tuple<int, int, int> t(1, 2, 3); //선언과 동시에 초기화

	tuple<int, int> t2; // 선언
	t2 = make_tuple(1, 2); // 초기화

	/* 2. tuple 원소 접근
	   - get이용
	   - 상수로 접근해야 함 */ 
	cout << get<0>(t) << get<1>(t) << get<2>(t);

	for (int i = 0; i < 3; i++) cout << get<i>(t) << " "; //error

	int const a = 1;
	cout << get<a>(t); // okay

	/* 3. tuple 원소분해
	   - tie() 이용.
	   - 같은 자료형만 됨. */
	tuple<int, int, int> t3;
	t3 = make_tuple(1, 3, 2);
	int x, y, z;
	tie(x, y, z) = t3;  // x=1,y=3,z=2

	tuple<int, char> t4(1, 'a');
	int a;
	char b;
	tie(a, b) = t4; // error
	
	/* 4.두 개의 튜플 연결*/
	tuple<int, int> t5(1, 2);
	tuple<int, int> t6(3, 4);
	tuple<int, int, int, int> t7 = tuple_cat(t5, t6);


	/* 5. tuple swap*/
	t5.swap(t6);
}