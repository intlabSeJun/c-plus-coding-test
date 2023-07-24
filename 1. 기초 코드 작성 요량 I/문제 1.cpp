#include <stdio.h>

int func1(int N) {
	int sum = 0;
	for (int i = 3; i <= N; i++)
	{
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int sum = 0;
	sum = func1(34567);  // 시간복잡도 O(N)
	printf("%d\n", sum);
}