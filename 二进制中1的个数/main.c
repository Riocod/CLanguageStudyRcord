#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int xx = 0;
	printf(">>>");
	scanf("%d", &xx);
	int count = 0;
	for (int i = 0; i < 32; i++)
	{ // ((xx >> 1) & 1) == 1
		if ((xx >> i) & 1) {
			++count;
		}
	}
	printf("%d\n", count);
	count = 0;
	while (xx)
	{
		xx = ((xx - 1) & xx);
		++count;
	}
	printf("%d\n", count);
	return 0;
}