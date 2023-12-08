#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;
int arr[5][9] = {};
int pointer[5] = {};
bool check_move_possible[4];
int dx[2] = { -1, 1 };

void move(int target, int direction) {
	if (direction == 1) {
		pointer[target] = (pointer[target] + 7) % 8;
	}
	else {
		pointer[target] = (pointer[target] + 1) % 8;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		}

		queue<pair<int, int>> Q;
		int target, direction;
		
		for (int i = 0; i < k; i++) {
			cin >> target >> direction;
			Q.push({ target, direction });
		}

		for (int i = 1; i < 5; i++) pointer[i] = 0;

		int new_target, new_direction;
		
		while (!Q.empty()) {
			target = Q.front().first;
			direction = Q.front().second;
			Q.pop();

			for (int i = 1; i <= 3; i++) {
				int buf1, buf2;
				buf1 = (pointer[i] + 2) % 8;
				buf2 = (pointer[i + 1] + 6) % 8;
				if (arr[i][buf1] == arr[i+1][buf2])
					check_move_possible[i] = false;
				else
					check_move_possible[i] = true;
			}
			

			queue<pair<int,int>> Q2_target;
			queue<pair<int, int>> Q3;
			Q3.push({ target, direction });
			move(target, direction);
			for (int i = 0; i < 2; i++) {
				Q2_target.push({ target, direction });
				while (!Q2_target.empty()) {
					int t = Q2_target.front().first;
					int d = Q2_target.front().second;
					Q2_target.pop();
					new_target = t + dx[i];
					new_direction = d * -1;
					if (new_target <= 0 || new_target > 4) continue;
					int idx;
					if (dx[i] == 1) idx = t;
					else idx = new_target;
					if (check_move_possible[idx] == false) continue;
					Q2_target.push({ new_target, new_direction });
					//Q3.push({ new_target, new_direction });
					move(new_target, new_direction);
				}
			}
	
			/*while (!Q3.empty()) {
				target = Q3.front().first;
				direction = Q3.front().second;
				Q3.pop();

				move(target, direction);
			}*/
			//cout << 1;
		}

		int total_sum = 0;
		for (int i = 1; i < 5; i++) {
			if (arr[i][pointer[i]] == 1) {
				if (i == 1) total_sum += 1;
				else total_sum += pow(2, i - 1);
			}
		}

		cout << "#" << test_case << " " << total_sum << "\n";
	}
	return 0;
}