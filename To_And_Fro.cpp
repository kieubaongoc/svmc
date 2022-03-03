//#include <iostream>
//
//using namespace std;
//
//char str[205];
//char a[100][100];
//
//void div(int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			a[i][j] = n * i + (n - j) * (i % 2) + (j + 1) * ((i + 1) % 2);
//		}
//	}
//}
//
//
//
//int main() {
//	int col;
//	do{
//		cin >> col;
//	} while (col < 2 || col > 20);
//	cin >> str;
//	div(col);
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; i < 100; i++) {
//			cout << a[i][j];
//		}
//	}
//
//	return 0;
//}

#include <iostream>
#define MAX 205

using namespace std;

int col, row;
char input[MAX];
char output[100][105];


int mstrlen(char* str) {
	int len = 0;
	while (str[len] != 0) {
		len++;
	}
	return len;
}

void solve() {
	int len = mstrlen(input);
	row = len / col;

	int i, j, index = 0;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			if (i % 2 == 1) {
				output[i][j] = input[index];
				index++;
			}
			else {
				output[i][col - j + 1] = input[index];
				index++;
			}
		}
	}
}

void show() {
	int i, j;
	for (i = 1; i <= col; i++) {
		for (j = 1; j <= row; j++) {
			cout << output[j][i];
		}
	}
	cout << endl;
}

void read_input() {
	cin >> col;

	while (col != 0) {
		cin >> input;
		solve();
		show();
		cin >> col;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	read_input();
	return 0;
}

//Input:
//
//5
//toioynnkpheleaigshareconhtomesnlewx
//3
//ttyohhieneesiaabss
//0
//
//Output:
//
//theresnoplacelikehomeonasnowynightx
//thisistheeasyoneab