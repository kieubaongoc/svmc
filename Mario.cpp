#include <iostream>
#define MAX 1000
#define WIDTH 5
using namespace std;

// C = {x-1,y}
// L = {x-1,y-1}
// R = {x-1,y+1}

//int dc[3] = { 0, -1, 0 };
//int dl[3] = { 0, -1, -1 };
//int dr[3] = { 0, -1, 1 };


int arr[MAX][WIDTH];
char dir[MAX];
int p[2][1000];

int cur_x;
int cur_y;
int coin = 0;
bool re = true;

void read_input(int height) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			cin >> arr[i][j];
		}
	}

	/*for (int k = 0; k < height; k++) {
		cin >> dir[k];
	}*/
	cin >> dir;
}

void solve(int height) {
	const int row_start = height;
	const int col_start = WIDTH / 2;

	cur_x = row_start;
	cur_y = col_start;

	for (int k = 0; k < height; k++) {
		if (dir[k] == 'C') {
			//p[row_start][col_start] = p[height - 1][col_start];
			cur_x = cur_x - 1;

			p[0][k] = cur_x;
			p[1][k] = cur_y;
		}
		else if (dir[k] == 'L')
		{
			//p[row_start][col_start] = p[height - 1][col_start - 1];
			cur_x = cur_x - 1;
			cur_y = cur_y - 1;

			p[0][k] = cur_x;
			p[1][k] = cur_y;
		}
		else if (dir[k] == 'R') {
			//p[row_start][col_start] = p[height - 1][col_start + 1];
			cur_x = cur_x - 1;
			cur_y = cur_y + 1;

			p[0][k] = cur_x;
			p[1][k] = cur_y;
		}

		if (arr[cur_x][cur_y] == 2) {
			re = false;
			break;
		}
		else if (arr[cur_x][cur_y] == 1) {
			coin++;
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	//int q = 1;
	//while (q<=tc)
	for(int i=1;i<=tc;i++)
	{
		re = true;
		int height;
		cin >> height;
		
		read_input(height);
		solve(height);
		
		if (!re) {
			cout << "#" << i << " NO" << endl;
		}
		else {
			cout << "#" << i << " YES " << coin << endl;
		}
		//q++;
	}

	return 0;
}

//Input:
//2
//5
//2 1 0 1 1
//2 0 0 0 2
//1 2 0 0 0
//0 0 0 0 0
//2 1 0 0 0
//CLLRR
//9
//2 2 2 1 1
//2 2 2 0 2
//1 1 1 0 2
//2 0 2 2 0
//2 1 0 1 1
//1 1 2 0 0
//2 0 2 0 2
//1 1 0 2 1
//2 0 0 1 0
//CCLLRCCLR
//
//Output :
//#1 YES 1
//#2 NO