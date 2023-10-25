#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
string s[55];

int sum_only_num(const string& x) {
	int sum_x = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] >= '0' && x[i] <= '9')
			sum_x += int(x[i] - '0');
	}
	return sum_x;
}

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length()) return a.length() < b.length();
	int sum_a, sum_b;
	sum_a = sum_only_num(a);
	sum_b = sum_only_num(b);
	if (sum_a != sum_b) return sum_a < sum_b;
	return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	//cout << s[0].length();

	sort(s, s + N, cmp);
	for (int i = 0; i < N; i++)
		cout << s[i] << "\n";
}