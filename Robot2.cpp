#include <iostream>
#include <algorithm>
#define SIZE 205
using namespace std;

char map[SIZE][SIZE];
char a[SIZE];
char b[SIZE];

int X, Y, K;
int pos_Ax;
int pos_Ay;
int pos_Bx;
int pos_By;
int result;
int kca, kcb = 0;

int pos_x[4] = { 1, 0, -1, 0 };
int pos_y[4] = { 0, -1, 0, 1 };

void read_input() {
	
	cin >> X >> Y >> K;
	for (int i = 0; i < K; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < K; i++) {
		cin >> b[i];
	}
}

void solve() {
	pos_Ax = 0;
	pos_Ay = 0;
	pos_Bx = 0;
	pos_By = 0;
	result = 0;
	int dir_A, dir_B = 0;

	for (int j = 0; j < K; j++) {
		if (a[j] == 'N') {
			dir_A = 3;
		}
		else if (a[j] == 'S') {
			dir_A = 1;
		}
		else if (a[j] == 'W') {
			dir_A = 2;
		}
		else if (a[j] == 'E') {
			dir_A = 0;
		}
		else if (a[j] == 'L') {
			dir_A = (dir_A + 3) % 4;
		}
		else if (a[j] == 'R') {
			dir_A = (dir_A + 1) % 4;
		}
		else if (a[j] == 'B') {
			dir_A = (dir_A + 2) % 4;
		}
		pos_Ax = pos_Ax + pos_x[dir_A];
		pos_Ay = pos_Ay + pos_y[dir_A];

		if (b[j] == 'N') {
			dir_B = 3;
		}
		else if (b[j] == 'S') {
			dir_B = 1;
		}
		else if (b[j] == 'W') {
			dir_B = 2;
		}
		else if (b[j] == 'E') {
			dir_B = 0;
		}
		else if (b[j] == 'L') {
			dir_B = (dir_B + 3) % 4;
		}
		else if (b[j] == 'R') {
			dir_B = (dir_B + 1) % 4;
		}
		else if (b[j] == 'B') {
			dir_B = (dir_B + 2) % 4;
		}
		pos_Bx = pos_Bx + pos_x[dir_B];
		pos_By = pos_Bx + pos_y[dir_B];

		// khi 2 robot ve dich
		if (pos_Ax == X && pos_Ay == Y && pos_Bx == X && pos_By == Y) {
			result = 1; // gg
			break;
		}
		if (pos_Ax == X && pos_Ay == Y) {
			result = 2; // A win
			break;
		}
		if (pos_Bx == X && pos_By == Y) {
			result = 3; // B win
			break;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int q = 1; q <= tc; q++) {
		read_input();
		solve();
		if (result == 1) {
			cout << "#" << tc << " " << "Good game!" << endl;
		}
		else if (result == 2) {
			cout << "#" << tc << " " << "Team A win!" << endl;
		}
		else if (result == 3) {
			cout << "#" << tc << " " << "Team B win!" << endl;
		}
		else {
			kca = sqrt((X - pos_Ax) * (X - pos_Ax) + (Y - pos_Ay) * (Y - pos_Ay));
			kcb = sqrt((X - pos_Bx) * (X - pos_Bx) + (Y - pos_By) * (Y - pos_By));
			printf("#%d %0.3f %0.3f\n", tc, kca, kcb);
		}
	}
	return 0;
}