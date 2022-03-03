//Hai bạn học sinh trong lúc nhàn rỗi nghĩ ra trò chơi sau đây.Mỗi bạn chọn trước một dãy số gồm n số nguyên.
//Giả sử dãy số mà bạn thứ nhất chọn là :
//
//b1, b2, ..., bn
//
//còn dãy số mà bạn thứ hai chọn là
//
//c1, c2, ..., cn
//
//Mỗi lượt chơi mỗi bạn đưa ra một số hạng trong dãy số của mình.Nếu bạn thứ nhất đưa ra số hạng bi(1 ≤ i ≤ n), 
//còn bạn thứ hai đưa ra số hạng cj(1 ≤ j ≤ n) thì giá của lượt chơi đó sẽ là | bi + cj | .
//
//Ví dụ : Giả sử dãy số bạn thứ nhất chọn là 1, -2; còn dãy số mà bạn thứ hai chọn là 2, 3. 
//Khi đó các khả năng có thể của một lượt chơi là(1, 2), (1, 3), (-2, 2), (-2, 3).Như vậy, giá nhỏ nhất của một lượt chơi trong số các lượt chơi có thể là 0 tương ứng với giá của lượt chơi(-2, 2).
//
//Yêu cầu
//Hãy xác định giá nhỏ nhất của một lượt chơi trong số các lượt chơi có thể.
//
//Dữ liệu
//Dòng đầu tiên chứa số nguyên dương n(n ≤ 105)
//Dòng thứ hai chứa dãy số nguyên b1, b2, ..., bn(| bi | ≤ 109, i = 1, 2, ..., n)
//Dòng thứ hai chứa dãy số nguyên c1, c2, ..., cn(| ci | ≤ 109, i = 1, 2, ..., n)
//Hai số liên tiếp trên một dòng được ghi cách nhau bởi dấu cách.
//
//Kết quả
//Ghi ra giá nhỏ nhất tìm được.
//
//Ràng buộc
//60 % số tests ứng với 60 % số điểm của bài có 1 ≤ n ≤ 1000.

//Dữ liệu:
//2
//1 - 2
//2 3
//
//Kết qủa:
//0

#include <iostream>
#define MAX 100000
#define SIZE 1000
using namespace std;

int a[SIZE];
int a1[SIZE];
int a2[SIZE];

void clear() {
	int m;
	for (int m = 0; m < SIZE; m++)
	{
		a[m] = 0;
		a1[m] = 0;
	}
}

void read_input(int quan_pairs) {
	for (int i = 0; i < quan_pairs + 2; i += 2) {
		int first_num, second_num;
		cin >> first_num >> second_num;
		a[i] = first_num;
		a[i + 1] = second_num;
	}
}

void solve() {
	int count = 0;
	for (int k = 0; k < SIZE; k+=2) {
		count++;
		if (count & 1) {
			a1[k] = a[k] + a[k + 2];
			a1[k + 1] = a[k] + a[k + 3];
		}
		if (!(count & 1)) {
			a1[k] = a[k] + a[k - 1];
			a1[k + 1] = a[k - 1] + a[k + 1];
		}
	}

	int min = a1[0];
	for (int q = 0; q < SIZE; q++) {
		
		if (a1[q] < min) {
			min = a1[q];
		}
	}
	if (min < 0) {
		cout << "# " << 0 - min;
	}
	else 
		cout << "# " << min;
}

int main() {
	freopen("input.txt", "r", stdin);
	int quan_pairs;
	cin >> quan_pairs;
	clear();
	read_input(quan_pairs);
	solve();
	return 0;
}