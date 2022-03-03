//#include <iostream>
//#define MAX 1000000
//using namespace std;
//
//int arr[MAX];
//int maxx;
//
//void read_input(int sum_plank) {
//	int p_height;
//
//	for (int i = 1; i <= sum_plank; i++) {
//		cin >> p_height;
//		arr[i] = p_height;
//	}
//	arr[0] = 0;
//	arr[sum_plank + 1] = 0;
//}
//
//void solve(int sum_plank) {
//	int start = 1;
//	int dem = 0;
//	maxx = 0;
//
//	while (start < sum_plank) {
//		dem = 0;
//		if (arr[start] > maxx) {
//			for (int j = 1; j <= arr[start]; j++) {
//				if (arr[start + j] >= arr[start]) {
//					dem++;
//					if (dem >= arr[start]) {
//						maxx = arr[start];
//						break;
//					}
//				}
//				else {
//					break;
//				}
//			}
//
//			for (int j = 0; j <= arr[start]; j++) {
//				if (arr[start - j] >= arr[start]) {
//					dem++;
//					if (dem >= arr[start]) {
//						maxx = arr[start];
//						break;
//					}
//				}
//				else {
//					break;
//				}
//			}
//		}
//		start++;
//	}
//	cout << "# " << maxx;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	int sum_plank;
//	cin >> sum_plank;
//	read_input(sum_plank);
//	solve(sum_plank);
//	return 0;
//}

#include<iostream>
#include<stdio.h>

#define gh 1234567

using namespace std;

int n, T;
int arr[gh];
int trai[gh];
int phai[gh];
int R[gh];
int L[gh];

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int z = 1;
	R[1] = 1;
	for (int i = 2; i < n; i++)
	{
		if (arr[i] < arr[R[z]])
		{
			while (arr[i] < arr[R[z]] && z > 0)
			{
				phai[R[z]] = i - 1;
				z--;
			}
		}
		R[++z] = i;
		if (i == n)
			for (int j = 1; j <= n; j++)
				phai[R[z]] = n;
	}
	z = 1;
	L[1] = 1;
	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i] < arr[L[z]])
		{
			while (arr[i] < arr[L[z]] && z > 0)
			{
				trai[L[z]] = i - 1;
				z--;
			}
		}
		L[++z] = i;
		if (i == n)
			for (int j = 1; j <= n; j++)
				trai[L[z]] = n;
	}
	int kq = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] <= phai[i] - trai[i] + 1)
		{
			kq = max(kq, min(phai[i] - trai[i] + 1, arr[i]));
		}
	}
	cout << kq;
	return 0;
}