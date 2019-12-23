//Task: bits
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {

		ull a;
	int n;

	cin >> n >> a;

	bool has_zero = 0, has_one = 0;
	int f_zero = 0, f_one = 0;

	for (int i = 0; i < n; ++i) {
		if ((1ull << i) & a) f_one = i, has_one = 1;
		else f_zero = i, has_zero = 1;
	}

	ull max_a, min_a;

	if (has_zero) {
		max_a = (1ull << f_zero) + a;
	} else {
		max_a = a;
	}

	if (has_one) {
		min_a = (1ull << f_one) ^ a;
	} else {
		min_a = a;
	}

	cout << min_a << ' ' << max_a << endl;
	return 0;
}

