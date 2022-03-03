//#include <iostream>
////#define MAX 4000
//#define SIZE 10000000
//
//using namespace std;
//
////int arr[MAX][MAX];
//
//struct node
//{
//	int x;
//	int y;
//};
//node aray[SIZE];
//
//void make() {
//	char x, y;
//	int location = 1;
//	bool cheo_x = 0;
//	x = 1; y = 1;
//	for (int i = location; i < SIZE;i++) {
//		aray[location].x = x;
//		aray[location].y = y;
//		location++;
//		if (x == 1 && cheo_x == 0) {
//			cheo_x = 1;
//			y++;
//			//continue;
//		}
//
//		else if (cheo_x == 1 && x == 1) {
//			x++;
//			y--;
//			//continue;
//		}
//
//		else if (y == 1 && cheo_x == 1) {
//			cheo_x = 0;
//			x++;
//			//continue;
//		}
//
//		else if (cheo_x == 0 && y == 1) {
//			y++;
//			x--;
//			//continue;
//		}
//
//		else if (cheo_x == 1) {
//			x++;
//			y--;
//			//continue;
//		}
//
//		else if (cheo_x == 0) {
//			x--;
//			y++;
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	int testcase;
//	cin >> testcase;
//	make();
//	int num;
//	for (int i = 0; i < testcase; i++)
//	{
//		cin >> num;
//		int x = aray[num].x;
//		int y = aray[num].y;
//		cout << "TERM " << num << " IS " << x << "/" << y << endl;
//	}
//}



//1/1 1/2 1/3 1/4 1/5 ...
//2/1 2/2 2/3 2/4
//3/1 3/2 3/3
//4/1 4/2
//5/1

//Trong sơ đồ trên, số hạng đầu tiên là 1/1, số hạng thứ hai là 1/2, 
//số hạng thứ ba là 2/1, số hạng thứ tư là 3/1, số hạng thứ năm là 2/2, v.v.


//Đầu vào
//
//Đầu vào bắt đầu bằng một dòng chứa một số nguyên t <= 20, số lượng trường hợp thử nghiệm.t các trường hợp thử nghiệm theo sau.
//
//Sau đó, nó chứa một số duy nhất trên mỗi dòng.
//
//Đầu ra
//
//Bạn phải viết một chương trình sẽ đọc một danh sách các số trong phạm vi từ 1 đến 10 ^ 7 
//và sẽ in ra cho mỗi số một số hạng tương ứng trong phép liệt kê Cantor như cho dưới đây.

#include<stdio.h>
#include<math.h>
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int i, num, sum = 0;
        scanf("%d", &num);// 3
        for (i = 1;; i++)
        {
            sum += i; // 0 + 1 + 2
            if (sum >= num)// 3 >= 3
                break;
        }
        int temp = num - (sum - i); // 3 - (3-2) = 2
        int total = i + 1; // 2 + 1 = 3
        if (i % 2 == 0)
            printf("TERM %d IS %d/%d\n", num, temp, total - temp);
        else
            printf("TERM %d IS %d/%d\n", num, total - temp, temp);
    }
    return 0;
}

//Input:
//3
//3
//14
//7
//
//Output :
//TERM 3 IS 2 / 1
//TERM 14 IS 2 / 4
//TERM 7 IS 1 / 4












