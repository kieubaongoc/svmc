//#include<iostream>
//using namespace std;
//int N;
//int arry[10005];
//int coppy[10005];
//int start;
//int stone;
//int dev_stone(int num) {
//	int location = start;// chia tu vi tri start voi so luong da cho san
//	arry[start] = 0;
//	while (num)
//	{
//		arry[location + 1]++;
//		location++;
//		if (location == N)
//			location = 0;
//		num--;
//	}
//
//	return location;// tra ve vi tri sau khi chia het da
//}
//
//int count_stone(int location) {
//	int re = arry[location];// lay o an dc
//	arry[location] = 0;
//	if (re) {// neu o an dc co da
//		if (location == N)
//			location = 0;
//		while (arry[location + 1] == 0)// check o ben canh o an dc co bi trong k, neu trogn lai an dc tiep
//		{
//			if (arry[location + 2] == 0)
//				break;
//			if ((location + 1) == N) {
//				location = 1;
//				re += arry[location];
//				arry[location] = 0;
//			}
//			else
//			{
//				re += arry[location + 2];
//				location = location + 2;
//				arry[location] = 0;
//			}
//			if (location == N)
//				location = 0;
//		}
//	}
//
//	return re;// return ket qua
//}
//
//void solve() {
//	int num_store;
//	num_store = arry[start];// lay so da
//	int location = dev_stone(num_store);// dem di chia, roi tra lai vi tri sau chia
//	if (location == N)
//		location = 0;
//	while (arry[location + 1])//check o ke tiep con da k, neu con chia tiep va cap nhan start moi
//	{
//		start = location + 1;
//		num_store = arry[location + 1];
//		location = dev_stone(num_store);
//	}
//	stone = count_stone(location + 2);// neu o ke tiep k con da, thi duoc an va dem so da an dc
//}
//int main()
//{
//
//	freopen("input.txt", "r", stdin);
//	cin >> N;
//	stone = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> arry[i];
//		coppy[i] = arry[i];
//	}
//
//	cin >> start;
//	while (start) {
//		for (int i = 1; i <= N; i++)//coppy the co cu
//		{
//			arry[i] = coppy[i];
//		}
//		solve();
//		cout << stone << endl;
//		cin >> start;
//	}
//	return 0;
//}


#include<iostream>
using namespace std;
int N;
int arry[10005];
int coppy[10005];
int start;
long long stone;
int dev_stone(int num) {
	int location = start;// chia tu vi tri start voi so luong da cho san
	arry[start] = 0;
	while (num)
	{
		arry[(location + 1) % N]++;
		location++;
		num--;
		location = location % N;
	}
	return location;// tra ve vi tri sau khi chia het da
}

long long count_stone(int location) {
	long long re = arry[location];// lay o an dc
	arry[location] = 0;
	if (re) {// neu o an dc co da
		while (arry[(location + 1) % N] == 0)// check o ben canh o an dc co bi trong k, neu trogn lai an dc tiep
		{
			if (arry[(location + 2) % N] == 0)
				break;
			re += arry[(location + 2) % N];
			location = (location + 2) % N;
			arry[location] = 0;
		}
	}
	return re;// return ket qua
}

void solve() {
	int num_store;
	num_store = arry[start];// lay so da
	int location = dev_stone(num_store);// dem di chia, roi tra lai vi tri sau chia
	while (arry[(location + 1) % N])//check o ke tiep con da k, neu con chia tiep va cap nhan start moi
	{
		start = (location + 1) % N;
		num_store = arry[(location + 1) % N];
		location = dev_stone(num_store);
		location = location % N;
	}
	if (arry[(location + 2) % N])
		stone = count_stone((location + 2) % N);// neu o ke tiep k con da, thi duoc an va dem so da an dc
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coppy[i];
	}
	cin >> start;
	start--;
	while (start >= 0) {
		stone = 0;
		for (int i = 0; i < N; i++)//coppy the co cu
		{
			arry[i] = coppy[i];
		}
		if (arry[start] == 0)
			cout << "0" << endl;
		else
		{
			solve();
			cout << stone << endl;
		}
		cin >> start;
		start--;
	}
	return 0;
}