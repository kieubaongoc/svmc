//Bắt đầu từ điểm(0, 0) trên một mặt phẳng, chúng ta đã viết tất cả các số nguyên không âm 0, 1, 2, ... như trong hình.
//Ví dụ, 1, 2 và 3 đã được viết lần lượt tại các điểm(1, 1), (2, 0) và(3, 1) và mẫu này vẫn tiếp tục.

//Bạn phải viết một chương trình đọc tọa độ của một điểm(x, y) và viết số (nếu có) đã được viết tại điểm đó. 
//(x, y) tọa độ trong đầu vào nằm trong khoảng 0 ... 10000.
//
//Đầu vào
//
//Dòng đầu tiên của đầu vào là N, số lượng trường hợp thử nghiệm cho vấn đề này.
//Trong mỗi dòng trong số N dòng sau, có x và y biểu diễn tọa độ(x, y) của một điểm.
//
//Đầu ra
//
//Đối với mỗi điểm trong đầu vào, hãy ghi số được viết tại điểm đó hoặc ghi Không số nếu không có.

#include <iostream>
#define MAX 10000
#define SIZE 10000

using namespace std;

//int arr[SIZE][SIZE];

void position(int x, int y) {

	// n=0 => pos=[0][0]
	// 
	// n=1 => pos[x+1][y+1]
	// 
	// n=2 => pos[x+1][y-1]
	// 
	// n=3 => pos[x+1][y+1]
	// 
	// n=4 => pos[x-1][y+1]
	// 
	// n=5 => pos[x+1][y+1]
	// 
	// n=6 => pos[x+1][y-1]
	// 
	// n=7 => pos[x+1][y+1]
	

	if ((x & 1) && (y & 1) && (x >= y)) {
		cout << x + y - 1;
	}
	else if(!(x & 1) && !(y & 1) && (x >= y)) {
		cout <<  x + y;
	}
	else {
		cout << "No Number";
	}

	if(x == y && x % 2 == 0 || x - y == 2 & x % 2 == 0) {
		printf("%d\n", x + y);
	}
	else if (x == y && x % 2 != 0 || x - y == 2 & x % 2 != 0) {
		printf("%d\n", x + y - 1);
	}
	else {
		printf("No Number\n");
	}
}
		

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int x, y;
		cin >> x >> y;
		position(x, y);
		cout << endl;
	}
	return 0;
}

//Input:
//3
//4 2
//6 6
//3 4
//
//Output :
//6
//12
//No Number