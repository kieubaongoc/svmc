#include <iostream>
#define SIZE 105
using namespace std;

int h, w, m, n;
int result;

int a[SIZE][SIZE];

void read_input() {
	cin >> h >> w >> m >> n;
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

int sum(int x, int y) {
	int i, j;
	int tmp_sum = 0;
	int limit_row, limit_col;

	limit_row = x + h;
	limit_col = y + w;

	for (i = x; i < limit_row; i++) {
		for (j = y; j < limit_col; j++) {
			if (i == x || i == limit_row - 1 || j == y || j == limit_col - 1) {
				if (a[i][j] % 2 == 0) {
					tmp_sum += a[i][j];
				}
			}
		}
	}
	return tmp_sum;
}

void solve() {
	int i, j;
	int tmp_sum;
	int row = m - h;
	int col = n - w;

	for (i = 0; i <= row; i++) {
		for (j = 0; j <= col; j++) {
			tmp_sum = sum(i, j);
			if (tmp_sum > result) {
				result = tmp_sum;
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	//scanf("%d", &tc);
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		result = 0;
		read_input();
		solve();
		cout << "#" << tc << " " << result << endl;
		//printf("#%d %d\n", tc, result);
	}
	return 0;
}

//Input:
//1
//3 2 5 6
//26 63 38 56 76 49
//92 55 9 90 13 21
//53 39 1 52 21 74
//82 66 27 86 79 31
//2 13 57 63 34 72
//1
//
//Output:
//#1 274