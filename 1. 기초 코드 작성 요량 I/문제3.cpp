/*
* 문제 3
* N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성하라.
* N은 10억 이하의 자연수이다.
* 
* 출력 예시
* func3(9) = 1,
* func3(693953651) = 0,
* func3(756580036) = 1
*/
# include <iostream>
# include <math.h>
# include <time.h>

using namespace std;


double m_sqrt(double n)  // custom sqrt, 내장 sqrt와 속도 비슷함. 
{
	double s = 0;
	double t = 0;

	s = n / 2;
	for (; s != t;)
	{
		t = s;
		s = ((n / t) + t) / 2;
	}
	return s;
}

int func3(int num)  // 속도가 빠르지만, sqrt 구현에 대해서는 모른다.
{
	//int a = sqrt(num);  // 내장 sqrt
	int a = m_sqrt(num);  // custom sqrt
	if (a * a == num) {
		return 1;
	}
	else {
		return 0;
	}

}

int func3_1(int num) // 속도가 더 오래걸린다 대략 560배.
{
	for (int i = 1; i * 1 <= num; i++) {
		if (i * i == num) return 1;
	}
	return 0;
}

int main() {
	clock_t start, end;
	double duration;
	start = clock();
	int arr[] = { 9, 693953651, 756580036 };
	int out;
	int length_arr = sizeof arr / sizeof arr[0];
	for (int i = 0; i < length_arr; i++) {
		cout << "func3(" << arr[i] << ") = " << func3(arr[i]) << endl;
	}
	end = clock();
	duration = (double)(end-start);
	cout << duration << endl;
}