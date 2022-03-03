//Cho một số N, tìm tổng của tất cả các tích x* y sao cho N / x = y (Phép chia số nguyên).
//
//Vì tổng có thể rất lớn, vui lòng xuất module 1000000007 này.
//
//Đầu vào
//
//Dòng đầu tiên của tệp đầu vào chứa một số nguyên T, số lượng trường hợp thử nghiệm cần tuân theo.Mỗi dòng trong số T dòng tiếp theo chứa một số nguyên N.
//
//Đầu ra
//
//Xuất ra T dòng chứa câu trả lời cho test case tương ứng.

//#include <iostream>
//#define MAX 1000000007
//
//using namespace std;
//
//int ts, ms;
//
//int divine(int ts, int ms) {
//	int res = 0;
//	for (int i = 1; i <= ts; i++) {
//		res = ts / ms;
//	}
//	return res;
//}
//
//unsigned long long sumOf(int ts) {
//	int i;
//	unsigned long long res_sum = 0;
//	for (i = 1; i <= ts; i++) {
//		res_sum += i * divine(ts, i);
//	}
//	return res_sum;
//}
//
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	int tc;
//	cin >> tc;
//	int n;
//	cin >> n;
//	cout << sumOf(n);
//	return 0;
//}

#include<iostream>
using namespace std;
unsigned long long num, re, answer, h, pre, n1;
int main()
{
	freopen("input.txt", "r", stdin);
	for (int t = 0; t < 5; t++)
	{
		cin >> num;
		re = 0;
		//for (int i = 1; i <= num; i++)
		//{
		//	answer = num / i;
		//	re += answer * i;
		//}
		cout << "right: " << re << endl;
		h = 2;
		pre = num;
		re = 0;
		while (true)
		{
			answer = num / h;
			if (pre != answer) {
				answer++;
				n1 = ((pre - answer + 1) * (pre + answer)) / 2;
				re += n1 * (h - 1);
				pre = num / h;
				h++;
				if (h >= num) break;
			}
			else
			{
				for (int k = num / h; k > 0; k--)
				{
					n1 = num / k;
					re += n1 * k;
				}
				break;
			}
		}
		cout << "my_re: " << re << endl;
	}
	return 0;
}

//Input:
//3
//2
//4
//6
//Output:
//
//4
//15
//33
//Constraints :
//1 ≤ T ≤ 500
//1 ≤ N ≤ 109
//
//Sample Explanation :
//Case #1:
//2 / 1 = 2
//2 / 2 = 1
//Answer = 1 * 2 + 2 * 1 = 4
//Case #2:
//4 / 1 = 4
//4 / 2 = 2
//4 / 3 = 1
//4 / 4 = 1
//Answer = 1 * 4 + 2 * 2 + 3 * 1 + 4 * 1 = 15