#include <iostream>

using namespace std;

struct node {
	char ngoac[2];
}; node _ngoac[51];
	
void copy(char a[6], char b[6]) {
	int i = 0;
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = b[i];
	//for (int i = 0; a[i] = b[i]; i++);
}

int compare(char a[6], char b[6]) {
	int i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return 0;
		i++;
	}
	if (a[i] != b[i])
		return 0;
	else
		return 1;
}
int check(char name[6], int num_name) {
	int re = 0;
	for (int i = 0; i < num_name; i++)
	{
		if (compare(name, _ngoac[i].ngoac))
			re++;
	}
	return re;
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {

		}
	}
	return 0;
}