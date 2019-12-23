#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

i64 multiply(i64 x, i64 y, i64 p) {
	i64 r = 0;
	while (y > 0) {
		if (y & 1) {
			r = (r + x) % p;
			--y;
		} else {
			x = (2 * x) % p;
			y >>= 1;
		}
	}
	return r;
}

i64 power(i64 x, i64 y, i64 p) {
	i64 r = 1;
	while (y > 0) {
		if (y & 1) {
			r = multiply(r, x, p);
			--y;
		} else {
			x = multiply(x, x, p);
			y >>= 1;
		}
	}
	return r;
}

int main() {
//	freopen(problem".in", "r", stdin);
//	freopen(problem".out", "w", stdout);
	
	i64 a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", power(a, b, c));
	return 0;
}
