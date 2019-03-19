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

	char *p, s[128];
	int a, b, x, y;
	
	
	printf("Please enter an integer: ");
    while (fgets(s, sizeof(s), stdin)) {
        x = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }
    
	printf("Please enter another integer: ");
	while (fgets(s, sizeof(s), stdin)) {
        y = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }
	
	int r = gccd(x, y, a, b);
	printf("%d * %d + %d * %d = %d\n", a, x, b, y, r);
	printf("a = %d\n b = %d\n", a, b);
}
