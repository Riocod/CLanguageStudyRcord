#include <stdio.h>
#include <string.h>



void num(char* s, int length, int d)
{
	int value = 0;

	for (int i = 0; i < length; i++)
	{
		value = (value * 10 + *(s + i) - '0') % d;
		printf("%d", value == 0 ? 1 : 0);
	}
}

int main()
{
	char* word = "998244353";
	int m = 3;
	int len = strlen(word);
	num(word, len, 3);

	return 0;
}