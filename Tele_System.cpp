#include <iostream>
#define SIZE 105
using namespace std;

char map[SIZE][SIZE];
int countH = 0;
int M, N;

int station_A[4][2] = { {0, 1}, { 0, -1 }, { -1, 0 }, { 1, 0 } };
int station_B[8][2] = { {0, 1}, { 0, -1 }, { -1, 0 }, { 1, 0 }, {0, 2}, { 0, -2 }, { -2, 0 }, { 2, 0 } };
int station_C[12][2] = { {0, 1}, { 0, -1 }, { -1, 0 }, { 1, 0 }, {0, 2}, { 0, -2 }, { -2, 0 }, { 2, 0 }, {0, 3}, { 0, -3 }, { -3, 0 }, { 3, 0 } };

int out(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return 1;
	return 0;
}

void read_input() {
	for (int j = 0; j < M; j++) {
		for (int k = 0; k < N; k++)
		{
			cin >> map[j][k];
		}
	}
}

void solve(int M, int N) {
	int check_x = 0;
	int check_y = 0;

	for (int j = 0; j < M; j++) {
		for (int k = 0; k < N; k++)
		{
			if (map[j][k] == 'H') {
				countH++;
			}

			if (map[j][k] == 'A') 
			{
				for (int g = 0; g < 4; g++)
				{
					check_x = j + station_A[g][0];
					check_y = k + station_A[g][1];
					if (map[check_x][check_y] == 'H' && out(check_x, check_y) == 0)
					{
						countH--;
						map[check_x][check_y] = 'X';
					}
				}
			}

			else if (map[j][k] == 'B') 
			{
				for (int g = 0; g < 8; g++)
				{
					check_x = j + station_B[g][0];
					check_y = k + station_B[g][1];
					if (map[check_x][check_y] == 'H' && out(check_x, check_y) == 0)
					{
						countH--;
						map[check_x][check_y] = 'X';
					}
				}
			}

			else if (map[j][k] == 'C')
			{
				for (int g = 0; g < 12; g++)
				{
					check_x = j + station_C[g][0];
					check_y = k + station_C[g][1];
					if (map[check_x][check_y] == 'H' && out(check_x, check_y) == 0)
					{
						countH--;
						map[check_x][check_y] = 'X';
					}
				}
			}
		}
	}
	cout << countH;
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> M >> N;
		read_input();
		cout << "#" << i << " ";
		solve(M, N);
	}
	return 0;
}