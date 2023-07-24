/* https://blockdmask.tistory.com/70
* vector container 란?
* - 자동으로 메모리가 할당되는 배열, 
* - 인덱스 접근하여 값 변경 가능
* - 함수로 보낼시에는 참조자를 사용해야 주소를 보내, 원본 변경 가능. 또한, 시간 복잡도도 O(N) -> O(1)로 줄어듬.
* - template를 사용하기 때문에 데이터 타입은 마음대로 넣을 수 있음. 
* - vector.push_back(값) : 값을 벡터 맨 마지막에 추가함. (append)
* - vector.pop_back() : 마지막 원소를 제거.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void print_func(string name, vector<int>& v) {
	cout << name << " : ";
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n";
}

int main() {
	// 여러가지 자료형 선언 가능.
	/*vector<int> v1;
	vector<double> v2;
	vector<string> v3;
	vector<char> v4;*/

	//// string 예시, 문자열이 벡터 공간 하나의 인덱스에 들어감. python 리스트 같음. 개쩐당.
	//v3.push_back("sejun");
	//cout << v3[0] << "\n";

	vector<int> v1(5); // 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector v를 생성.
	print_func("v1", v1);

	vector<int> v2(5, 2); // 2로 초기화된 5개의 원소를 가지는 vector v를 생성.
	print_func("v2", v2);
	
	vector<int> v3(v2);  // v3는 v2 vector를 복사해서 생성. 
	print_func("v3", v3);

	if (v1 == v3) cout << 1;  // 대소비교는 같은지(==)만 사용하는게 좋을 듯. -> 모든 원소 값들이 같은지 나타냄. 

	v1.assign(4, 2);  // 새롭게 할당됨
	print_func("v1.assing(5,2)", v1);

	v2.assign(3, 10);  // 새롭게 할당됨
	print_func("v2.assing(3,10)", v2);
	
	v2.front(); // 첫번째 원소를 참조.
	v2.back(); // 마지막 원소를 참조.

	// v2.clear(); // 모든 원소를 제거. 원소만 제거하고 메모리는 남아 있음. size만 줄어들고 capacity는 그대로.

	v2.push_back(7);  // 마지막 원소 뒤에 7 삽입. append
	print_func("v2.push_back(7)", v2);
	v2.pop_back();  // 마지막 원소를 제거.
	print_func("v2.pop_back()", v2);

	v2.begin();  // 첫번째 원소를 가르킴 (iterator와 사용)
	v2.end();  // 마지막의 "다음"을 가르킴 (iterator와 사용)

	v2.rbegin();  // reverse begin을 가르킴 (거꾸로 해서 첫번째 원소를 가르킴) (iterator와 사용)
	v2.rend();  // reverse end을 가르킴 (거꾸로 해서 마지막의 다음을 가르킴) (iterator와 사용)

	v2.resize(2);  // 크기를 n으로 변경, 더 작아졌을 경우 뒤에 값들이 버려짐, 더 커졌을 경우 default 값인 0으로 초기화
	print_func("v2.resize(10)", v2);
	
	v2.resize(10, 20);  // 크기를 n으로 변경, 더 커졌을 경우 20으로 초기화 한다. 
	print_func("v2.resize(10,20)", v2);

	v2.size(); // 원소의 갯수를 리턴
	cout << "v2.size()" << v2.size() << "\n";

	v2.capacity(); // 할당된 공간의 크기를 리턴
	cout << "v2.capacity()" << v2.capacity() << "\n";

	v2.swap(v3); // v1과 v2의 원소와 capacity 바꿔줌 (모든 것을 스왑)
	print_func("v2 swap with v3", v2);
	print_func("v3 swap with v2", v3);

	print_func("before v2.insert(v2.begin(), -1, 4)", v2);
	v2.insert(v2.begin(), 3, -1);  // v2 시작 부분에 3개의 -1의 값을 삽입, 기존 값들은 뒤로 밀린다.
	print_func("v2.insert(v2.begin(), -1, 4)", v2);

	v2.insert(v2.begin() + 2, 2, 10);  // v2.begin()+2 인덱스부터 삽입.
	print_func("v2.insert(v2.begin()+2, 2, 10)", v2);

	cout <<"before erase v2.capacity() : " << v2.capacity() << "\n";
	v2.erase(v2.begin()+2);  // iter 위치를 제거함, size만 줄고 capacity(할당된 메모리)는 그대로 남아 있음. 
	print_func("v2.erase(v2.begin()+2)", v2);
	cout << "after erase v2.capacity() : " << v2.capacity() << "\n";

	v2.erase(v2.begin(), v2.begin() + 2);  // iter의 범위를 제거함. 역시 그대로 capacity는 남아 있음.
	print_func("v2.erase(v2.begin(), v2.begin() + 2)", v2);

	v2.empty(); // vector의 size가 비어 있으면 리턴 1 else 0. capacity와는 상관 없음.
	cout << "v2.empty() : " << v2.empty() << "\n";
	
	//sort(v2.begin(), v2.end()); // 오름차순 정렬
	//reverse(v2.begin() + 2, v2.end() + 4);  // 내림차순 정렬, index 2~3까지.

	int max = *max_element(v2.begin(), v2.end());  // 가장 큰 수를 반환함
	int max_index = max_element(v2.begin(), v2.end()) - v2.begin();  // 가장 큰 인덱스를 반환함(인덱스번호 반환)

	// vector를 iterator로 반복할 수 있음.
	for (int e : v2) {  // v2의 각 원소들을 순회하면서 값을 복사하여 저장
		cout << e << " ";
	}
	for (int& e : v2) {  // v2를 참조하기 때문에, e를 변경시 원본 v2가 변경됨
		e = 1;
	}
	for (int e : v2) cout << e << " ";
}