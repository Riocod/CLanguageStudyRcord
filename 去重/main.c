#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1001
int main()
{
	// 开辟一个1001大小的数组，并且将前1000个赋值
	int arr[N];
	srand((unsigned)time(NULL));
	for (int i = 0; i < N-1; i++)
	{
		arr[i] = i+1;
	}
	// 产生一个随机数
	int x = rand() % 10;
	// 将最后一个下标设置为随机数
	arr[N-1] = x;
	// 产生一个随机数，并且与最后一个元素交换
	int tmp = arr[N - 1];
	int index = rand() % 10;
	arr[N-1] = arr[index];
	arr[index] = tmp;
	// 打印
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	// 0 亦或(XOR) 上任何一个数都是它本身。 将 1 到 1000的XOR结果计算出来
	int x1 = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		x1 = (x1 ^ i);
	}
	// 由于 只出现一次的元素会被消除，所以最后至剩下偶数个的元素
	for (int i = 0; i < N; i++)
	{
		x1 = x1 ^ arr[i];
	}
	printf("[+] %d\n", x1);
	return 0;
}