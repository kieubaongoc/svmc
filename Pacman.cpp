#include <iostream>
#define SIZE 105
#define MAX_LEN 300
using namespace std;


int m, n;
int map[SIZE][SIZE];
char pacman[MAX_LEN], ghost[MAX_LEN];
long long gold_pacman, gold_ghost;

// Trai - Len - Phai - Xuong
//  0   -  1  -  2   -   3

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void read_input() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	scanf("\n");
	for (i = 0; i < m; i++) {
		scanf("%c", &pacman[i]);
	}

	scanf("\n");
	for (i = 0; i < m; i++) {
		scanf("%c", &ghost[i]);
	}
}

// L
int turn_left(int h) {
	return (h + 3) % 4;
}
// R
int turn_right(int h) {
	return (h + 1) % 4;
}

void solve() {
	// x, y
	int pacman_x = 0, pacman_y = 0;
	int ghost_x = n - 1, ghost_y = n - 1;

	int dir_pacman = 3, dir_ghost = 1;

	int i;
	for (i = 0; i < m; i++) {

		// PACMAN
		if (pacman[i] == 'C') {
			pacman_x += dx[dir_pacman];
			pacman_y += dy[dir_pacman];
		}
		else if (pacman[i] == 'L') {
			dir_pacman = turn_left(dir_pacman);
			pacman_x += dx[dir_pacman];
			pacman_y += dy[dir_pacman];
		}
		else if (pacman[i] == 'R') {
			dir_pacman = turn_right(dir_pacman);
			pacman_x += dx[dir_pacman];
			pacman_y += dy[dir_pacman];
		}

		// GHOST
		if (ghost[i] == 'C') {
			ghost_x += dx[dir_ghost];
			ghost_y += dy[dir_ghost];
		}
		else if (ghost[i] == 'L') {
			dir_ghost = turn_left(dir_ghost);
			ghost_x += dx[dir_ghost];
			ghost_y += dy[dir_ghost];
		}
		else if (ghost[i] == 'R') {
			dir_ghost = turn_right(dir_ghost);
			ghost_x += dx[dir_ghost];
			ghost_y += dy[dir_ghost];
		}

		if (pacman_x == ghost_x && pacman_y == ghost_y) {
			break;
		}
		else {
			gold_pacman += map[pacman_x][pacman_y];
			map[pacman_x][pacman_y] = 0;

			gold_ghost += map[ghost_x][ghost_y];
			map[ghost_x][ghost_y] = 0;
		}
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {

		gold_pacman = 0;
		gold_ghost = 0;

		read_input();
		solve();

		printf("#%d %lld %lld\n", i, gold_pacman, gold_ghost);
	}
	return 0;
}

//Input:
//2
//6 6
//0 0 0 0 0 0
//0 1 7 8 5 0
//0 1 5 4 3 0
//0 7 5 5 6 0
//0 8 9 9 5 0
//0 0 0 0 0 0
//CCLLRL
//CLLLLL
//6 15
//0 0 0 0 0 0
//0 9 3 3 8 0
//0 1 8 5 2 0
//0 1 3 9 5 0
//0 9 2 1 3 0
//0 0 0 0 0 0
//CCLLRCRCCCLLRLC
//CCCLCRCRCRCCCCR

//Output:
//#1 9 5
//#2 13 7