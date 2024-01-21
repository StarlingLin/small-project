#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int f1 = m - 1, f2 = n - 1, f = m + n - 1;
    while (f2 >= 0)
    {
        if (f1 < 0 || nums2[f2] >= nums1[f1])
        {
            nums1[f--] = nums2[f2--];
        }
        else
        {
            nums1[f--] = nums1[f1--];
        }
    }
}

int main()
{
	int nums1[6] = { 1,2,3,0,0,0 };
	int nums2[3] = { 2,5,6 };
	merge(nums1, 6, 3, nums2, 3, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	return 0;
}