#include<iostream>
#include<vector>
using namespace std;


void change_value(vector<vector<int>> v1, vector<vector<int>>& v2) {
	/*
	 vector<vector<int>> v1  : 벡터가 복사됨. 원본 접근 x
	 vector<vector<int>> &v2 : 벡터 주소. 원본 접근 o
	*/
	v1[0][0] = 0; // 원본 안바뀜
	v2[0][1] = -1; // 원본 바뀜
}

void print_vector(vector<vector<int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	vector<vector<int>> v(2, vector<int>(3)); // (2,3) 행렬 생성
	cout << v.size() << " " << v[0].size() << "\n"; // 2 3

	print_vector(v); // 초기값은 0으로 됨.
	vector<vector<int>> v2(2, vector<int>(3, -1)); // 초기값 -1
	print_vector(v2); // -1로 초기화된 (2,3) 
	for(int i=0;i<v2.size(); i++) // fill()을 사용해서 초기화 가능
		fill(v2[i].begin(), v2[i].end(), 7); // 각 행마다 7로 초기화
	print_vector(v2); // 7로 초기화된 (2,3)

	change_value(v2, v2);
	print_vector(v2); // v[0][1]만 -1로 변경.
}