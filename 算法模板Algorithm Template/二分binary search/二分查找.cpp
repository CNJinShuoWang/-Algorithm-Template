#include <iostream>
using namespace std;
int n, m, num[199999999], p, ans = -1;

int search(int ask) {
	ans = -1;
	int mid, l = 1, r = n;
	mid = (l + r) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (num[mid] < ask)
			l = mid + 1;
		else if (num[mid] >= ask)
			r = mid - 1;
	}
	if (num[l] == ask)
		return l;
	else
		return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= m; i++) {
		cin >> p;
		cout << search(p) << ' ';
	}
	return 0;
}
