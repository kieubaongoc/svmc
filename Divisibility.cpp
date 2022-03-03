//In ra tất cả các số nguyên ai sao cho ai chia hết cho x và không chia hết cho y, trong đó 1 < ai < n < 100000.
//
//	Đầu vào
//
//	Đầu tiên, bạn được cung cấp t(t < 100) - số trường hợp thử nghiệm.Trong t dòng sau, 3 số nguyên : n x y.
//
//	Bạn cũng có thể giả định rằng x < n và x không chia hết cho y.
//
//	Đầu ra
//
//	Trong mỗi dòng trong số t dòng sau, các số được yêu cầu trong mô tả bài toán được phân tách bằng một khoảng trắng theo thứ tự tăng dần.

//Input:
//	2
//	7 2 4
//	35 5 12
//Output :
//	2 6
//	5 10 15 20 25 30

#include <iostream>
#define MAX 100000

using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		for (int i = 1; i < n; i++) {
			if (i % x == 0 && i % y != 0) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}