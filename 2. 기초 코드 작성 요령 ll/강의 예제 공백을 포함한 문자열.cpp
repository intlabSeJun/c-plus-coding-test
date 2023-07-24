#include <iostream>
using namespace std;
#include <string>

//int main() {
//	string s = "hi im";
//	//cout << "input : ";
//	//cin >> s;
//	cout << "s is " << s;
//}

// getling 사용, 공백까지 다 받아오자
int main() {
	int n;
	string s;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	cout << s;
	cout << n;
}