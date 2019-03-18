#include <cstdio>
#include <cassert>

int gccd(int x, int y, int &a, int &b) {
	if (y == 0) {
		a = 1;
		b = 0;
		assert(a*x + b*y == x);
		return x;
	} else {
		int a_t, b_t;
		int r = gccd(y, x%y, a_t, b_t);
		a = b_t;
		b = a_t;
		assert(a*x + b*y == r);
		return r;
	}
}

int main() {
	int a, b;
	int x = 12, y = 8;
	int r = gccd(x, y, a, b);
	printf("%d * %d + %d * %d = %d\n", a, x, b, y, r);
	printf("=> a = %d\n b = %d\n", a, b);
}