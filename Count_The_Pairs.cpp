#include <iostream>
#include <algorithm>

#define MAX 100005

using namespace std;


int n;
int k;
int arr[MAX];

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
}

int binary_search(int arr[], int lo, int hi, int value) {
	int mid;

	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;

		if (arr[mid] == value) {
			return 1;
		}
		else if (arr[mid] > value) {
			hi = mid - 1;
		}
		else if (arr[mid] < value) {
			lo = mid + 1;
		}
	}

	return 0;
}

int solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += binary_search(arr, i, n - 1, arr[i] + k);
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	read_input();
	printf("%d\n", solve());
	return 0;
}

//Sample Input :
//
//5 2
//
//1 5 3 4 2
//
//Sample Output :
//
//3
//
//Sample Input :
//
//10 1
//
//363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793
//
//Sample Output :
//
//0