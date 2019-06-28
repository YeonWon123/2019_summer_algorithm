#include <cstdio>

struct info {
	int x, y, z;
};

int main(void) {
	info a, c;

	scanf("%d %d %d", &a.x, &a.y, &a.z);
	scanf("%d %d %d", &c.x, &c.y, &c.z);

	printf("%d %d %d\n", c.x - a.z, c.y / a.y, c.z - a.x);
}