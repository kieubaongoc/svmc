//#include <iostream>
//#define MAX 12
//
//using namespace std;
//
//int isOE(int n) {
//	if (n % 2 == 0)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}
//
//
//void show() {
//	for (int i = 0; i < MAX; i++) {
//		for (int j = 0; j < MAX; j++)
//		{
//			if ((isOE(j) == 1 && isOE(i) == 0) || (isOE(j) == 0 && isOE(i) == 1)) {
//				cout << "  ";
//			}
//			else
//				cout << "* ";
//		}
//		cout << endl;
//	}	
//}
//
////void show(int n) {
////	for (int i = 0; i < n; i++) {
////		for (int j = 0; j < n; j++)
////		{
////			if ((isOE(j) == 1 && isOE(i) == 0) || (isOE(j) == 0 && isOE(i) == 1)) {
////				cout << "  ";
////			}
////			else
////				cout << "* ";
////		}
////		cout << endl;
////	}
////}
//
//int main() {
//	//int n;
//	cout << "1 2 3 4 5 6 7 8 9 0 1 2\n" << endl;
//	//freopen("input.txt", "r", stdin);
//	
//	//cin >> n;
//	show();
//	//show(n);
//	return 0;
//}



//cho một dãy tên các bạn trong lớp, đếm số bạn có tên theo yêu cầu

//#include <iostream>
//#define SIZE 50
//using namespace std;
//
//char arr[50*6];
//char arr2[5*6];
//
//void solve() {
//	int size;
//	cin >> size;
//	for (int i = 0; i < size; i++) {
//		//scanf("%s", &arr[i]);
//		cin >> arr[i];
//	}
//	for (int i = 0; i < size; i++) {
//		//printf("%s", &arr[i]);
//		cout << arr[i];
//	}
//	int n;
//	cin >> n;
//	for (int j = 0; j < n; j++) {
//		//scanf("%s", &arr2[j]);
//		cin >> arr2[j];
//	}
//	for (int i = 0; i < size; i++) {
//		//printf("%s", &arr[i]);
//		cout << arr2[i];
//	}
//	/*for (int k = 0; k < size; k++) {
//		if (strcmp(&arr[k], &arr2[k])==0) {
//			printf("%s ", &arr2[k]);
//		}
//	}*/
//}
//
//
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	int tc;
//	cin >> tc;
//	solve();
//	return 0;
//}



#include<iostream>
#define max 100005
using namespace std;

struct node {
	char name[6];
}; node user_name[51];

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
		if (compare(name, user_name[i].name))
			re++;
	}
	return re;
}

int main()
{
	int testcase;
	char name[6];
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	int num_name;
	for (int j = 0; j < testcase; j++)
	{
		cin >> num_name;
		for (int i = 0; i < num_name; i++)
		{
			cin >> name;
			copy(user_name[i].name, name);
		}
		int quest;
		cin >> quest;
		for (int i = 0; i < quest; i++)
		{
			cin >> name;
			cout << name << ": ";
			cout << check(name, num_name) << endl;
		}
	}
	return 0;
}