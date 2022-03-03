#include <iostream>
#define MAX 40000
using namespace std;

int arr[MAX];
int arr_s[100];
int sum1 = 0;

int area(int x, int y) {
	int s = 0;
	s = x * y;
	return s;
}

void solve(int x1, int y1, int x2, int y2) {
	int x, y, h = 0;
	x = x2 - x1;
	y = y2 - y1;
	if (x < 0) x = 0 - x;
	if (y < 0) y = 0 - y;
	sum1 += area(x, y);
	arr_s[h] = sum1;
	h++;
}


int main() {
	freopen("input.txt", "r", stdin);
	int N, i, j = 0, sum = 0;
	int x, y, p, q;
	int x1, y1, x2, y2;
	cin >> N;
	
	for (i = 0; i < N * 4; i += 4) {
		cin >> x1 >> y1 >> x2 >> y2;
		//solve(x1, y1, x2, y2);

		arr[i] = x1;
		arr[i + 1] = y1;
		arr[i + 2] = x2;
		arr[i + 3] = y2;
	
		x = x2 - x1;
		y = y2 - y1;
		if (x < 0) x = 0 - x;
		if (y < 0) y = 0 - y;
		arr_s[j] = area(x, y);
		
		sum = sum + arr_s[j];
		j++;

		
		for (int k = 2; k < N * 4; k+=4)
		{
			if ((arr[k] < arr[k + 2]) || (arr[k] > arr[k + 2])) {
				//p = arr[k] - arr[k+2];
				//q = arr[k+1] - arr[k+3];
				p = 5;
				q = 5;
				if (p < 0) p = 0 - p;
				if (q < 0) q = 0 - p;
				//sum = sum - area(p, q);
				//sum = sum + arr_s[j] - area(p, q);
			}
			
		}
	}
	
	cout << sum;
	//cout << sum1;
	return 0;
}