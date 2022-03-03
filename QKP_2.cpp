#include <iostream>
#define MAX_SIZE 1005

using namespace std;

const int QUEEN = 1, KNIGHT = 2, PAWN = 3;

int n, m;
int Q, K, P;
int board[MAX_SIZE][MAX_SIZE];
int queen[MAX_SIZE * MAX_SIZE][2], knight[MAX_SIZE * MAX_SIZE][2], pawn[MAX_SIZE * MAX_SIZE][2];

int QUEEN_DIR[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1}};
int KNIGHT_DIR[8][2] = { {1,2}, {1,-2}, {2,1}, {2,-1}, {-1,2}, {-1,-2}, {-2,1}, {-2,-1}};

int res;

void init() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			board[i][j] = 0;
		}
	}
}

void read_input() {
	int i, x, y;
	res = m * n;
	
	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> x >> y;
		board[x][y] = QUEEN;

		// luu vi tri cac quan Hau
		queen[i][0] = x;
		queen[i][1] = y;
	}
	//cin >> k;
}

int main() {
		
	return 0;
}