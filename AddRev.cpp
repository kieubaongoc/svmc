#include <iostream>
using namespace std;

int reverse_number(int n) {
	int r = 0;
	int a;
	while (n >= 1)
	{
		a = n % 10;
		r = r * 10 + a;
		n = n / 10;
	}
	return r;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, i, x, y;
	int r, s, t;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;

		r = reverse_number(x);
		s = reverse_number(y);

		t = reverse_number(r + s);
		cout << t << endl;
	}
	return 0;
}

//Sample input :
//
//3
//24 1
//4358 754
//305 794
//
//Sample output :
//
//34
//1998
//1