#include<iostream>
using namespace std;

long long N, x, Start, End, Type[1010];

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i <= N - 2; i++) {
		cin >> Start >> End >> Type[i];

		if (Type[i] == 1) {
			x++;
		}
	}
	if (x % 2 == 0) {
		cout << 0;
	}
	else {
		cout << 1;
	}

	return 0;
}

//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int N;
//	scanf("%d", &N);
//	int i, x, y, z, s;
//	s = 0;
//	for (i = 2; i <= N; i++)
//	{
//		scanf("%d %d %d", &x, &y, &z);
//		s = s + z;
//	}
//
//	if (s % 2 == 0) 
//		printf("0");
//	else
//		printf("1");
//	return 0;
//}