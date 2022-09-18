/*tong 2 duong cheo cua ma tran
1 2 3
4 5 6
7 8 9
out: 30*/
#include <iostream>
using namespace std;
int main() {
	int n, a[100][100], tongMot = 0, tongHai = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				tongMot += a[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1 - i) {
				tongHai += a[i][j];
			}
		}
	}
	cout << tongMot + tongHai;
	system("pause");
	return 0;
}