#include<iostream>
#include<vector>
using namespace std;


void change_vector_value(vector<int> v1, vector<int> &v2) {
	/*
	 vector<int> v1  : vector값이 복사됨. (+메모리)
	 vector<int> &v1 : vector값의 주소가 복사됨. (원본접근)
	*/
	v1[0] = 3; // 원본에 반영 안됨.
	v2[1] = 4; // 원본에 반영됨.
}

void print_vector(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n";
}

int main() {
	vector<int> v1;  
	print_vector(v1); // 비어 있는 상태

	vector<int> v2(3, -1); // -1로 3개 값을 할당함
	print_vector(v2); // -1 -1 -1

	change_vector_value(v2, v2);
	print_vector(v2);  // -1 4 -1

}