#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdbool.h>


_Bool validPartition(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++)
	{
        // 判断是否有两个相同的元素
		if (i + 1 < numsSize && *(nums+i) == *(nums + i + 1))
		{
			return true;;
		}
        // 判断是否有三个相同的元素
		if (i + 2 < numsSize && *(nums + i) == *(nums + i + 1) && *(nums + i) == *(nums + i + 2))
		{
			return true;;
		}
        // / 判断是否有三个差值为各为一元素
		if (i + 2 < numsSize && *(nums + i) + 1 == *(nums + i + 1) && *(nums + i) + 2 == *(nums + i + 2))
		{
			return true;;
		}
		
	}

	return false;
}

int main()
{

	int nums[] = { 4, 2, 4, 6, 6 };
	int len = sizeof(nums) / sizeof(nums[0]);
	_Bool result = validPartition(nums, len);
	printf(result ? "true\n" : "false\n");
	

	return 0;
}