#include <iostream>
using namespace std;

const int Q = 0;
const int K = 1;
const int P = 2;
const int Safe = 3;
const int Unsafe = 4;

int Board[1000][1000];	// Lưu bàn cờ
int ROW, COL;			// Số hàng ,cột

// Đường đi con mã
int K_row[8] = { -1,-2, 1, 2,-2,-1, 2, 1 };
int K_col[8] = { 2, 1, 2, 1,-1,-2,-1,-2 };

/*
* Tính số ô con mã có thể ăn
* @PARAM: row, hàng của con mã đang xét
* @PARAM: col, cột của con mã đang xét
* RETURN: số vị trí con mã có thể ăn
*/
int checkK(int row, int col)
{
	int count = 0;
	// Kiểm tra 8 hướng của con mã
	for (int i = 0; i < 8; i++)
	{
		int r = row + K_row[i];
		int c = col + K_col[i];
		if (r <= ROW && r >= 0 && c <= COL && c >= 0)
		{
			// Nếu ô nào đang ở vị trí an toàn
			// thì tức là con mã có thể ăn
			// cho ô đó thành Unsafe để tránh lặp và tăng biến đếm
			if (Board[r][c] == Safe)
			{
				Board[r][c] = Unsafe;
				count++;
			}
		}
	}
	return count;
}

// Đường đi con hậu
int Q_row[8] = { 0, 0, 1, 1, 1,-1,-1,-1 };
int Q_col[8] = { 1,-1,-1, 0, 1,-1, 0, 1 };
int Sum = 0;

/*
* Duyệt mỗi con hậu tại vị trí row, col theo từng hướng
* Sử dụng đệ quy
*/
void checkQ(int row, int col, int direct)
{
	int r = row + Q_row[direct];
	int c = col + Q_col[direct];

	if (r <= ROW && r >= 0 && c <= COL && c >= 0)
	{
		// Ô nào đang an toàn thì sẽ bị ăn
		// Cho thành Unsafe
		if (Board[r][c] == Safe)
		{
			Board[r][c] = Unsafe;
			Sum--;
			checkQ(r, c, direct);
		}
		else if (Board[r][c] == Unsafe)
		{
			// Trường hợp này là đã tính trước đó.
			checkQ(r, c, direct);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int tc = 0;
	while (true)
	{
		cin >> ROW >> COL;
		if (ROW == 0 && COL == 0) break;
		tc++;
		Sum = ROW * COL;
		ROW--;
		COL--;

		// Ban đầu gán các ô là ô an toàn
		for (int r = 0; r <= ROW; r++)
			for (int c = 0; c <= COL; c++)
				Board[r][c] = Safe;

		int r, c;
		int row[2][100], col[2][100];	// Lưu thông tin con hậu, con mã
		int num[3];						// Số lượng con hậu, con mã, con tốt

		// Tiếp tục nhập đầu vào
		for (int i = 0; i < 3; i++)
		{
			cin >> num[i];
			for (int j = 0; j < num[i]; j++)
			{
				cin >> r >> c;
				Board[r - 1][c - 1] = i;
				if (i != 2)
				{
					row[i][j] = r - 1;
					col[i][j] = c - 1;
				}
			}
		}

		// Tính tổng các ô rảnh mà chưa có con nào đang đứng
		Sum -= num[Q] + num[K] + num[P];

		// Duyệt các con mã
		for (int j = 0; j < num[K]; j++)
			Sum -= checkK(row[K][j], col[K][j]);

		// Duyệt các con hậu
		for (int j = 0; j < num[Q]; j++)
			for (int i = 0; i < 8; i++)
				checkQ(row[Q][j], col[Q][j], i);

		cout << "Board " << tc << " has " << Sum << " safe squares." << endl;
	}
	return 0;
}

//Input:
//4 4
//2 1 4 2 4
//1 1 2
//1 2 3
//2 3
//1 1 2
//1 1 1
//0
//1000 1000
//1 3 3
//0
//0
//0 0
//
//Output:
//Board 1 has 6 safe squares.
//Board 2 has 0 safe squares.
//Board 3 has 996998 safe squares.