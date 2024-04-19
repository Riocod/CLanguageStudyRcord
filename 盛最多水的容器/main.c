#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define LEN(n) (sizeof(n) / sizeof(n[0]))
#define FMIN(x, y) (x <= y ? x : y)
#define FMAX(x, y) (x <= y ? y : x)
// 暴力解法
//int maxArea(int* height, int heightSize) {
//	if (heightSize <= 2)
//	{
//		return height[0] * height[1];
//	}
//	int mid = heightSize / 2 + 1;
//	int leftflag = height[0];
//	//int rightflag = height[mid + 1];
//	for (int i = 0; i < mid; i++)
//	{
//		if (height[i + 1] > leftflag) {
//			leftflag = height[i + 1];
//		}
//	}
//	int max = leftflag * height[mid + 1];
//	for (int i = mid + 1; i < heightSize; i++)
//	{
//		
//		if (max < (i * height[i] * leftflag))
//		{
//			max = leftflag < height[i] ? leftflag * leftflag : height[i] * height[i];
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	int arr[] = {3, 5, 4};
//	int length = LEN(arr);
//	int max = maxArea(arr, length);
//	printf("%d\n", max);
//}

int maxArea(int* height, int heightSize) {
	// 顶一个双指针，分别从数组左右两边的下标开始；
	int l = 0, r = heightSize - 1; 
	int ans = 0;
	while (l < r)
	{
		int area = (r - l ) * FMIN(height[l], height[r]);
		ans = FMAX(area, ans);
		if (height[l] < height[r])
		{
			++l;
		}
		else
		{
			--r;
		}
	}
	return ans;
}

int main()
{
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	int length = LEN(arr);
	int max = maxArea(arr, length);
	printf("%d\n", max);
}