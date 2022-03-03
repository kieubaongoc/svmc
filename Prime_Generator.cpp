#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

//int isPrime(long int k) {
//	if (k < 2)
//		return 0;
//	for (int i = 2; i < k; i++) {
//		if (k % i == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}

bool checkPrime(long int num)
{
	if (num <= 1)
		return false;
	else if (num == 2)
		return true;
	else if (num % 2 == 0)
		return false;
	else
	{
		bool prime = true;
		int divisor = 3;

		int upperLimit = sqrt(num) + 1;

		while (divisor <= upperLimit)
		{
			if (num % divisor == 0)
				return false;
			divisor += 2;
		}
		return prime;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	int a, b, i, j, testcase;
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++)
	{
		scanf(" %d %d", &a, &b);
		printf("\n");
		for (j = a; j <= b; j++)
		{
			if (checkPrime(j))
				printf("%d\n", j);
		}
		printf("\n");
	}
	return 0;
}

//Input:
//2
//1 10
//3 5
//
//Output :
//2
//3
//5
//7
//
//3
//5