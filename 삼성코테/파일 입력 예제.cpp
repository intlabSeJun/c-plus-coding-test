#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//cin.tie(0);

	int x, y;

	ifstream cin;
	cin.open("test.txt");
		
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> y;
		cout << y;
	}
}