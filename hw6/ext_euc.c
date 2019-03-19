#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>

/*int a, b;*/

int gccd(int x, int y, int &a, int &b) {
	if (y == 0) {
		a = 1;
		b = 0;
		assert(a*x + b*y == x);
		return x;
	} else {
		int a_t, b_t;
		int r = gccd(y, x % y, a_t, b_t);
		a = b_t;
		b = a_t - b_t * (x / y);
		assert(a * x + b * y == r);
		return r;
	}
}



int main() {
	#define LINE_MAX 256
	char buf[LINE_MAX];
	char *end;

	int a, b;
	int x =0, y = 0;
	
	
	printf("Please enter an integer: ");
	do {
	     if (!fgets(buf, sizeof buf, stdin))
	        break;

	     // remove \n
	     buf[strlen(buf) - 1] = 0;

	     int x = strtol(buf, &end, 10);
	} while (end != buf + strlen(buf));

	printf("Please enter another integer: ");
	do {
	     if (!fgets(buf, sizeof buf, stdin))
	        break;

	     // remove \n
	     buf[strlen(buf) - 1] = 0;

	     int y = strtol(buf, &end, 10);
	} while (end != buf + strlen(buf));
	
	int r = gccd(x, y, a, b);
	printf("%d * %d + %d * %d = %d\n", a, x, b, y, r);
	printf("a = %d\n b = %d\n", a, b);
}
