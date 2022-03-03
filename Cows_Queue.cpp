//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//long long n, k;
//long long arr[17];
//long long coppy[17];
//int vt[17];
//long long kq;
//
//void check() {
//	long long minus = 0;
//	for (int i = 1; i < n; i++)
//	{
//		minus = coppy[i] - coppy[i - 1];
//		if (minus < 0)
//			minus = 0 - minus;
//		if (minus <= k)
//			return;
//	}
//	kq++;
//}
//void add(int location) {
//	if (location == n) {
//		check();
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (vt[i] == 0) {
//			vt[i] = 1;
//			coppy[location] = arr[i];
//			add(location + 1);
//			vt[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	cin >> n >> k;
//	kq = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		vt[i] = 0;
//	}
//	add(0);
//	cout << kq << endl;
//	return 0;
//}


#include<iostream>
#include<stdio.h>
int M;
using namespace std;
int ar[10][10];
int vt[10][10];
int front, rear;
int x[100];
int y[100];
int start_count;
int td_x[8] = { 1,-1,0,0,1,1,-1,-1 };
int td_y[8] = { 0,0,-1,1,1,-1,1,-1 };
struct toado
{
	int x, y;
};
void EnQueue(int _x, int _y) {
	x[rear] = _x;
	y[rear] = _y;
	rear++;
}

toado DeQueue() {
	toado re;
	if (front < rear) {
		re.x = x[front];
		re.y = y[front];
		front++;
	}
	return re;
}

int check(toado star) {
	if (star.x < 0 || star.x >= M || star.y < 0 || star.y >= M)
		return 0;
	if (ar[star.x][star.y] == 0)
		return 0;
	if (vt[star.x][star.y] == 1)
		return 0;
	return 1;
}

void queue(int _x, int _y) {
	front = rear = 0;
	int count_star = 1;
	EnQueue(_x, _y);
	vt[_x][_y] = 1;
	toado star;
	toado new_star;
	while (front < rear) {
		star = DeQueue();
		for (int i = 0; i < 8; i++)
		{
			new_star.x = star.x + td_x[i];
			new_star.y = star.y + td_y[i];
			if (check(new_star)) {
				EnQueue(new_star.x, new_star.y);
				vt[new_star.x][new_star.y] = 1;
				count_star++;
			}
		}

	}
	if (start_count < count_star)
		start_count = count_star;
}
void solve() {
	for (int i = 0; i < M; i++)
	{
		for (int k = 0; k < M; k++)
		{
			if (ar[i][k] == 1 && vt[i][k] == 0)
				queue(i, k);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> M;
	start_count = 0;
	for (int i = 0; i < M; i++)
	{
		for (int k = 0; k < M; k++)
		{
			cin >> ar[i][k];
			vt[i][k] = 0;
		}
	}
	solve();
	cout << start_count;
	return 0;
}