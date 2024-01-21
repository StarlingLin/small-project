#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int src = 0, dest = 0;
    for (; src < numsSize; src++)
    {
        if (nums[src] != val)
        {
            nums[dest] = nums[src];
            dest++;
        }
    }
    return dest;
}

int main()
{
	int nums[] = { 3,2,2,3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int val = 3;
	int ret = removeElement(nums, numsSize, val);
	printf("%d\n", ret);
	return 0;
}