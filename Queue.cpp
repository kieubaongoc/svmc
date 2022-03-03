#include <iostream>
#define MAX 100
#define SIZE 15
using namespace std;

int arr[MAX];
int front;
int rear;

int map[100][100];
int dem[10];


int a[SIZE][SIZE];

int pop() {
	if (front < rear) {
		int res = arr[front];
		front++;
		return res;
	}
	return 0;
}

void push(int temp) {
	arr[rear] = temp;
	rear++;
}

void read_input() {
	int i, j;
	int sum_pair;
	int start;
	int target;

	for (i = 1; i < 10; i++) {
		for (j = 0; j < 1; j++) {
			a[i][j] = 1;
		}
	}

	cin >> sum_pair;
	for (i = 0; i < sum_pair; i++) {	
		cin >> start >> target;
		int top = a[start][0];
		a[start][top] = target;
		a[start][0]++;
	}
}

void solve() {
	dem[1] = 0;
	push(1);
	int father;
	int top;
	while (front < rear) {
		father = pop();
		top = a[father][0];

		for (int i = 1; i < top; i++)
		{
			int cur = a[father][i];
			if (dem[cur] == 0) {
				push(cur);
				dem[cur] = dem[father] + 1;
			}
			if (cur == 9) {
				return;
			}
		}
	}
}

void clear() {
	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			map[i][k] = 0;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		dem[i] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int q = 1; q <= tc; q++) {
		clear();
		front = rear = 0;
		read_input();
		solve();
		cout << "#" << q << " " << dem[9] << endl;
	}
	return 0;
}



//#include<iostream>
//#define MAX 100
//using namespace std;
//int aray[MAX];
//int map[100][100];
//int front, rear;
//int num;
//int dem[10];
//
//void push(int value) {
//	aray[rear] = value;
//	rear++;
//}
//
//int pop() {
//	if (front < rear) {
//		int re = aray[front];
//		front++;
//		return re;
//	}
//	return 0;
//}
//
//void read_input() {
//	int x, y;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> x >> y;
//		map[x][y] = 1;
//	}
//}
//
//void clear() {
//	for (int i = 0; i < 100; i++)
//	{
//		for (int k = 0; k < 100; k++)
//		{
//			map[i][k] = 0;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		dem[i] = 0;
//	}
//}
//
//void solve() {
//	dem[1] = 0;
//	push(1);
//	int father;
//	while (front < rear) {
//		father = pop();
//		for (int i = 1; i <= 9; i++)
//		{
//			if (map[father][i] == 1 && i == 9) {
//				dem[i] = dem[father] + 1;
//				return;
//			}
//			if (map[father][i] == 1 && dem[i] == 0) {
//				dem[i] = dem[father] + 1;
//				push(i);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int test;
//	freopen("input.txt", "r", stdin);
//
//	cin >> test;
//
//	for (int i = 0; i < test; i++)
//	{
//		front = rear = 0;
//		clear();
//		read_input();
//		solve();
//		cout << "#" << i + 1 << " " << dem[9] << endl;
//	}
//
//	return 0;
//}